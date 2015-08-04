//
// Created by roberto on 29/07/15.
//
#include "alignerFunctions.h"
#include "../globalConstants.h"

int main(int argc, char* argv[]){
	stackSizeIncreased();

    if(argc==3) align(argv);
    else printf(PARAMETER_ERROR);
    return 0;
}
