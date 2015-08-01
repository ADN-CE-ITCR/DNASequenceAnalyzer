//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H
#define DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H

#include "pthread.h"
#include "stdlib.h"

char intToDNA(int);
void* alignerThread(void*);
char* fillMatrix(int,int,char*,char*);

#endif //DNASEQUENCEGENERATOR_ALIGNERFUNCTIONS_H
