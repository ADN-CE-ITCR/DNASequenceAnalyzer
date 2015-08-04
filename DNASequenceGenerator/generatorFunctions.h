//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_GENERATORFUNCTIONS_H
#define DNASEQUENCEGENERATOR_GENERATORFUNCTIONS_H

#include "constants.h"
#include "../globalConstants.h"
#include <time.h>
#include "pthread.h"

void write(int, FILE*);
void ask(int*, char*, pthread_mutex_t*);
void generate(int*, char*, pthread_mutex_t*);
void* receiverThread(void*);
long getPow(int, unsigned short int);

#endif //DNASEQUENCEGENERATOR_GENERATORFUNCTIONS_H
