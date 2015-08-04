//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H
#define DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H

#include "../globalConstants.h"
#include "constants.h"
#include <time.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

struct SequenceToAlign{
    int** sequencesLenght;
    char** sequences;
};
void getSequences(struct SequenceToAlign*,char*[]);
void align(char*[]);
char* fillMatrix(int,int,char*,char*);
void analyzeData(struct SequenceToAlign*);
int matchingScore(char,char);

#endif //DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H
