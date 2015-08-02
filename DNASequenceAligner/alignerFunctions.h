//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H
#define DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H

#include "../globalConstants.h"
#include "constants.h"

struct SequenceToAlign{
    int** sequencesLenght;
    char** sequences;
    char* scoringMatrix;
};
void getSequences(struct SequenceToAlign*, pthread_mutex_t*);
void* alignerThread(void*);
char* fillMatrix(int,int,char*,char*);

#endif //DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H
