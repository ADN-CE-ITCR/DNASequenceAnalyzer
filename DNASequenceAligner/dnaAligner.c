/*
 * dnaAligner.h
 *
 *  Created on: 1/8/2015
 *      Author: alex
 */
#include "dnaAligner.h"
void analizeData(char* dna1,char* dna2, int* dnaLenght1,int* dnaLenght2){
	int columns= *dnaLenght1+2;
	int rows= *dnaLenght2+2;

	int matrix[columns][rows];

	for (int i = 0; i < columns; ++i) {
		for (int j = 0; j < rows; ++j) {
		matrix[i][j]=0;
		}

	}
	for (int y = 0; y < columns; ++y) {
		matrix[y][0]=D*y;
	}
	for (int x = 0; x < rows; ++x) {
		matrix[0][x]=D*x;
	}
	for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				printf(" %i ", matrix[i][j]);
			}
			printf("\n");
		}





}
