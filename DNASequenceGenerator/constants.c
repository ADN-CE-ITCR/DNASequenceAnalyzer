//
// Created by roberto on 31/07/15.
//

#include "constants.h"

void createDirectory(){
    PROJECT_PATH = getenv("HOME");
    strcat(PROJECT_PATH, "/");
    strcat(PROJECT_PATH, PROJECT_NAME);
    mkdir(PROJECT_PATH, 0777);
}