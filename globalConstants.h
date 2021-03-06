//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_GLOBALCONSTANTS_H
#define DNASEQUENCEGENERATOR_GLOBALCONSTANTS_H

#include <stdlib.h>
#include "pthread.h"
#include <stdio.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <string.h>

#define PROJECT_NAME "DNASequenceAnalyzer"
#define FILE_EXT ".dna"
#define HELLO "Hello, welcome to"
#define GOODBYE "Goodbye, thanks for your preference."
#define DO_YOU_WANT_TO_CONTINUE "Please input any number, except for '0', if you want to continue."
#define ENCODING_BASE 4
#define MAX_NAME_LENGHT 28

char* PROJECT_PATH;

void createDirectory();
void stackSizeIncreased();

#endif //DNASEQUENCEGENERATOR_GLOBALCONSTANTS_H
