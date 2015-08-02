/*
 * fileHandler.c
 *
 *  Created on: 1/8/2015
 *      Author: alex
 */
#include "fileHandler.h"

void askFilename(char* newFileName1, char* newFileName2) {
	int validInput = 0;
	char * newExtension1;
	char * newExtension2;
	do {
		printf("%s\n",INPUT_FIRST_FILENAME	);
		scanf("%s", newFileName1);
		printf("%s\n",INPUT_SECOND_FILENAME);
		scanf("%s", newFileName2);
		newExtension1 = strchr(newFileName1, '.');
		newExtension2 = strchr(newFileName2, '.');

		if (strcmp(newExtension1, COMMON_EXTENSION) == 0
				&& strcmp(newExtension2, ".dna") == 0) {

			validInput = 1;
		} else {
			printf("%s",EXTENTION_ERROR);
		}
	} while (!validInput);
	printf("Loading %s and %s\n", newFileName1, newFileName2);

}

int getFileSize(int fileSize, FILE* file) {
	fseek(file, 0, SEEK_END); // seek to end of file
	fileSize = ftell(file); // get current file pointer
	fseek(file, 0, SEEK_SET); // seek back to beginning of file
	return fileSize;
}





void openFile(char* newFileName1, char* newFileName2, char* DNA1, char* DNA2, int* dnaLenght1,int* dnaLenght2) {
	int fileSize1 = 0;
	int fileSize2 = 0;
	FILE* file1 = fopen(newFileName1, "r");
	FILE* file2 = fopen(newFileName2, "r");
	if (file1 == NULL || file2 == NULL) {
		perror("Error opening file");
		return;
	}
	fileSize1 = getFileSize(fileSize1, file1);
	fileSize2 = getFileSize(fileSize2, file2);

	DNA1 = (char*) malloc(sizeof(char) * fileSize1);
	DNA2 = (char*) malloc(sizeof(char) * fileSize2);

	fgets(DNA1, fileSize1, file1);
	fgets(DNA2, fileSize2, file2);

	printf("DNA1: %s\nDNA2:%s\n",DNA1,DNA2);
	*dnaLenght1=fileSize1;
	*dnaLenght2 =fileSize2;
	fclose(file1);
	fclose(file2);

}
