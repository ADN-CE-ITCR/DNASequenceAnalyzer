/*
 ============================================================================
 Name        : DNASequenceAligner.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "globalConstants.h"
#include "fileHandler.h"

int main(void) {


	char* fileName1 = malloc(sizeof(char) * MAX_NAME_LENGHT + 4);
	char* fileName2 = malloc(sizeof(char) * MAX_NAME_LENGHT + 4);
	char* DNA1;
	char* DNA2;
	int* dnaLenght1=(int*)malloc(sizeof(int));
	int*dnaLenght2=(int*)malloc(sizeof(int));

	askFilename(fileName1, fileName2);
	openFile(fileName1, fileName2, DNA1, DNA2,dnaLenght1,dnaLenght2);

	analizeData(DNA1,DNA2,dnaLenght1,dnaLenght2);



printf("FIN DEL PROGRAMA");
	free(fileName1);
	free(fileName2);



}
