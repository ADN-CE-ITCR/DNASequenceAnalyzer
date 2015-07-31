//
// Created by roberto on 31/07/15.
//

#ifndef DNASEQUENCEGENERATOR_GENERATORFUNCTIONS_H
#define DNASEQUENCEGENERATOR_GENERATORFUNCTIONS_H

#include "fileManagement.h"
#include <pthread.h>
#include <time.h>

void ask(int*, char*, pthread_mutex_t*);
void generate(int*, char*, pthread_mutex_t*);
void* receiverThread(void*);

#endif //DNASEQUENCEGENERATOR_GENERATORFUNCTIONS_H
