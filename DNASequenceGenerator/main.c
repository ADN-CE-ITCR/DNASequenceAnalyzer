//
// Created by roberto on 29/07/15.
//
#include "generatorFunctions.h"

int main() {
    pthread_t* controller = (pthread_t*) malloc(sizeof(pthread_t));
    pthread_create(controller, NULL, receiverThread, (void*)controller);
    pthread_join(*controller,(void*)controller);
    free(controller);
    return 0;
}