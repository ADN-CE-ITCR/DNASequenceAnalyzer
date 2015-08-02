//
// Created by roberto on 29/07/15.
//
#include "alignerFunctions.h"
int main(){
    pthread_t* controller = (pthread_t*) malloc(sizeof(pthread_t));
    pthread_create(controller, NULL, alignerThread, (void*)controller);
    pthread_join(*controller,(void*)controller);
    free(controller);
    return 0;
}
