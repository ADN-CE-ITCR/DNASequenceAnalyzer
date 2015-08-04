//
// Created by roberto on 31/07/15.
//

#include "alignerFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
/**
 * @brief Imprime la matriz con todos los scores calculados
 * @param int columns: Cantidad de columnas
 * @param int rows: Cantidad de filas
 * @param int matrix: matriz con los scores
 *  */
void printMatrix(int columns, int rows, int matrix[columns][rows]) {
	//Imprime la matriz
	for (int i = 0; i < columns; ++i) {
		for (int j = 0; j < rows; ++j) {
			printf(" %i ", matrix[i][j]);
		}
		printf("\n");
	}
}
/**
 * @brief Inicializa la matriz en ceros
 * @param int columns: Cantidad de columnas
 * @param int rows: Cantidad de filas
 * @param int matrix: matriz a inicializar
 * */
void matrixInit(int columns, int rows, int matrix[columns][rows]) {
	//Inicializa la matriz en ceros
	for (int i = 0; i < columns; ++i) {
		for (int j = 0; j < rows; ++j) {
			if (i == 0)
				matrix[i][j] = D * j;
			else if (j == 0)
				matrix[i][j] = D * i;
			else
				matrix[i][j] = 0;
		}
	}
}
/**
 * @brief Retorna un valor especifico por cada letra ingresada
 * @param char newChar1: caracter que se incializa
 * @return Valor correspondiente al caracter
 * */
int getCharValue(char newChar1) {
	int tempvalue = 0;
	switch (newChar1) {
	case 'A':
		tempvalue = 1;
		break;
	case 'G':
		tempvalue = 3;
		break;
	case 'C':
		tempvalue = 5;
		break;
	case 'T':
		tempvalue = 7;
		break;
	default:
		printf("ESTE ES L VALOR %i", newChar1);
		perror(DATA_ERROR2);
		exit(1);
		break;
	}
	return tempvalue;
}

/**
 * @brief despues de la multimplicacion de valores unicos se retorna el score especifico
 * @param int newUniqueID: Valor Resultante de la multiplicacion 
 * @return Score Correspondiente a la convinacion dada
 * */
int getScore(int newUniqueID) {
	int score = 0;
	switch (newUniqueID) {
	case 1:
		score = 10;
		break;
	case 3:
		score = -1;
		break;
	case 5:
		score = -3;
		break;
	case 7:
		score = -4;
		break;
	case 9:
		score = 7;
		break;
	case 15:
		score = -5;
		break;
	case 21:
		score = -3;
		break;
	case 25:
		score = 9;
		break;
	case 35:
		score = 0;
		break;
	case 49:
		score = 8;
		break;
	default:
		perror(DATA_ERROR);
		exit(1);
		break;

	}
	return score;
}
/**
 * @brief A partir de dos caracteres calcula su score respectivo
 * @param char newChar1: primer char
 * @param char newChar2: segundo char
 * @return Score resultante
 * */
int matchingScore(char newChar1, char newChar2) {
	int finalScore = 0;
	int tempCharValue1 = getCharValue(newChar1);
	int tempCharValue2 = getCharValue(newChar2);
	finalScore = getScore(tempCharValue1 * tempCharValue2);
	return finalScore;
}

/**
 * @brief Calcula los scores diagonales , de izquieda y de arriba y llena la matriz
 * @param int columns: Cantidad de columnas
 * @param int rows: Cantidad de filas
 * @param int matrix: matriz con los a llenar
 * */
void fillScores(int columns, int rows, int matrix[columns][rows],
		struct SequenceToAlign* toAlign, char* DNA1, char* DNA2) {
	//Matrix Calc

	int leftScore;
	int upperScore;
	int diagonalScore;
	int tempScore;
	for (int i = 1; i < columns; ++i) {
		for (int j = 1; j < rows; ++j) {
			leftScore = matrix[i][j - 1] + (-5);
			upperScore = matrix[i - 1][j] + (-5);
			char uno = DNA1[i - 1];
			char dos = DNA2[j - 1];
			diagonalScore = matrix[i - 1][j - 1] + matchingScore(uno, dos);
			tempScore = MAX(leftScore, upperScore);
			tempScore = MAX(tempScore, diagonalScore);
			matrix[i][j] = tempScore;
		}
	}
}


/**
 * @brief Imprime los char Array que tienen los alineamientos
 * @param int columns: Cantidad de columnas
 * @param int rows: Cantidad de filas
 * @param char topAligment: Primer Alineamiento
 *  @param char bottomAligment: Segundo Alineamiento
 * */
void printAligment(int columns, int rows, char topAligment[columns * rows],
		char bottomAligment[columns * rows]) {
	printf("TOP: ");
	int var;
	for (var = 0; var <= columns * rows; ++var) {
		if (topAligment[var] != 0)
			printf("%C", topAligment[var]);
	}
	printf("\n");
	printf("BOTTOM: ");
	for (var = 0; var <= columns * rows; ++var) {
		if (bottomAligment[var] != 0)
			printf("%C", bottomAligment[var]);
	}
	printf("\n");
}
/**
 * @brief hace un llamado a las funciones para calcular el alinemaiento de las secuencias
 *  @param int columns: Cantidad de columnas
 *  @param int rows: Cantidad de filas
 *   @param int scoresMatrix: matriz a la que se le aplica el algoritmo
 *   @param char* DNA1: Secuencia 1
 *   @param char* DNA2: Secuencia 2
 * */
void getAligments(int columns, int rows, int scoresMatrix[columns][rows], char* DNA1,
		char*DNA2) {
	char topAligment[columns * rows];
	memset(topAligment, 0, columns * rows * sizeof(char));
	char bottomAligment[columns * rows];
	memset(bottomAligment, 0, columns * rows * sizeof(char));
	int xIterator = columns - 1;
	int yIterator = rows - 1;
	int charPointer = columns * rows ;
	int leftScore = 0;
	int upperScore = 0;
	int diagonalScore = 0;
	while (xIterator > 0 && yIterator > 0) {
		int aux = scoresMatrix[xIterator][yIterator];
		char uno = DNA1[xIterator - 1];
		char dos = DNA2[yIterator - 1];
		leftScore = scoresMatrix[xIterator][yIterator - 1] + (-5);
		upperScore = scoresMatrix[xIterator - 1][yIterator] + (-5);
		diagonalScore = scoresMatrix[xIterator - 1][yIterator - 1] + matchingScore(uno, dos);
		if (scoresMatrix[xIterator][yIterator] == diagonalScore) {
			topAligment[charPointer] = DNA2[yIterator - 1];
			bottomAligment[charPointer] = DNA1[xIterator - 1];
			xIterator--;
			yIterator--;
		} else if (scoresMatrix[xIterator][yIterator] == leftScore) {
			topAligment[charPointer] = DNA2[yIterator - 1];
			bottomAligment[charPointer] = '-';
			yIterator--;
		} else if (scoresMatrix[xIterator][yIterator] == upperScore) {
			topAligment[charPointer] = '-';
			bottomAligment[charPointer] = DNA1[xIterator - 1];
			xIterator--;
		}
		charPointer--;
	}
	while (xIterator > 0) {
		topAligment[charPointer] = '-';
		bottomAligment[charPointer] = DNA1[xIterator - 1];
		xIterator--;
		charPointer--;
	}
	while (yIterator > 0) {
		topAligment[charPointer] = DNA2[yIterator - 1];
		bottomAligment[charPointer] = '-';
		yIterator--;
		charPointer--;

	}
	printAligment(columns, rows, topAligment, bottomAligment);


}
/**
 * @brief lleva acabo las funciones de analisis de las secuencias
 * @param SequenceToAlign*: Contiene la informacion de las secuencias
 * */
void analyzeData(struct SequenceToAlign* toAlign) {
	int columns = **(toAlign->sequencesLenght);
	int rows = **(toAlign->sequencesLenght + 1);
	char* DNA1 = 0;
	char* DNA2 = 0;
	DNA1 = *(toAlign->sequences);
	DNA2 = *(toAlign->sequences + 1);
	int matrix[columns][rows];
	//Inicializa la matriz en ceros
	matrixInit(columns, rows, matrix);
	//Matrix Calc
	fillScores(columns, rows, matrix, toAlign, DNA1, DNA2);
	//Imprime la matriz
	printMatrix(columns, rows, matrix);
	//Calculate the Aligments and prints them
	getAligments(columns, rows, matrix, DNA1, DNA2);
	printf("EL TAMAÑO ES: %i\n", (int) sizeof(matrix));

}

/**@brief obtiene los nombres y abre los archivos
 * @param struct SequenceToAlign toAlign: estructura donde se guardaran los datos
 */
void getSequences(struct SequenceToAlign* toAlign) {
	toAlign->sequences = (char**) malloc(2 * sizeof(char*));
	toAlign->sequencesLenght = (int**) malloc(2 * sizeof(int*));
	*(toAlign->sequencesLenght) = (int*) malloc(sizeof(int));
	*(toAlign->sequencesLenght + 1) = (int*) malloc(sizeof(int));
	int i;
	for (i = 0; i < 2; i++) {
		char* tmpName = malloc(strlen(PROJECT_PATH) + MAX_NAME_LENGHT + 4);
		char* fileNameBuffer = malloc(MAX_NAME_LENGHT);
		printf(INPUT_MSJ);
		scanf("%s", fileNameBuffer);
		strcpy(tmpName, PROJECT_PATH);
		strcat(tmpName, fileNameBuffer);
		strcat(tmpName, FILE_EXT);
		free(fileNameBuffer);
		FILE* file;
		if (file = fopen(tmpName, "r")) {
			fseek(file, 0, SEEK_END);
			**(toAlign->sequencesLenght + i) = ftell(file);
			fseek(file, 0, SEEK_SET);
			*(toAlign->sequences + i) = malloc(
					**(toAlign->sequencesLenght + i));
			fgets(*(toAlign->sequences + i), **(toAlign->sequencesLenght + i),
					file);
			printf("%d \n", **(toAlign->sequencesLenght + i));
			printf(SUCCESSFUL, i, *(toAlign->sequences + i));
			fclose(file);
		} else {
			printf(FILENAME_ERROR);
			--i;
		}
		free(tmpName);
	}

}

/**@brief se encarga de controlar las iteraciones realizadas
 * @param void* detach: parametro para detach de pthread
 * @return void* detach significa correcto
 */
void alignerThread(void* detach) {
//Da la bienvenida e inicializa el random
	createDirectory();
	printf("%s %s \n", HELLO, PROJECT_NAME);
//Declara los mutex
	pthread_mutex_t* mutualExclusion = (pthread_mutex_t*) (malloc(
			sizeof(pthread_mutex_t)));
	pthread_mutex_init(mutualExclusion, NULL);
//Crea variables e inicia loop que pregunta por los datos, genera la secuencia
	char* excecuting = (char*) malloc(sizeof(char));
	*excecuting = 1;
	struct timespec timeController;
	timeController.tv_sec = 1;
	while (*excecuting) {
		pthread_mutex_lock(mutualExclusion);
		//Obtiene los datos, llena la estructura con secuencias y matriz de resultados
		struct SequenceToAlign toAlign;
		getSequences(&toAlign);
		analyzeData(&toAlign);
		printf("%s \n", DO_YOU_WANT_TO_CONTINUE);
		scanf("%d", excecuting);
		nanosleep(&timeController, NULL);
		pthread_mutex_unlock(mutualExclusion);
	}
//Libera memoria
	free(mutualExclusion);
	free(excecuting);
//Se despide del usuario y retorna
	printf("%s", GOODBYE);
	return;
}
