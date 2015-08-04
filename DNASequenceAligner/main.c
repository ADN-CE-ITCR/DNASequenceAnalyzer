//
// Created by roberto on 29/07/15.
//
#include "alignerFunctions.h"

int main(int argc, char* argv[]){
    if(argc==3) align(argv);
    else printf(PARAMETER_ERROR);
    return 0;
}