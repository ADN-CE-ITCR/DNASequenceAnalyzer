//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_CONSTANTS_H
#define DNASEQUENCEGENERATOR_CONSTANTS_H

#include <stdlib.h>

#define PROJECT_NAME "DNASequenceGenerator"
#define FILE_EXT ".dna"
#define HELLO "Hello, welcome to"
#define GOODBYE "Goodbye, thanks for your preference."
#define LENGHT_SENTENCE "Please, input the lenght of the desired sequence."
#define FILE_NAME_SENTENCE "Please, input a name with one to twenty eight characters of the desired sequence."
#define FILE_CREATED_PART_ONE "The sequence have been generated and is stored on home/DNASequenceGenerator/"
#define FILE_CREATED_PART_TWO ". The content of the file is: "
#define DO_YOU_WANT_TO_CONTINUE "Please input any number, except for '0', if you want to continue."
#define MAX_NAME_LENGHT 28
const char* PROJECT_PATH;

void createDirectory();

#endif //DNASEQUENCEGENERATOR_CONSTANTS_H
