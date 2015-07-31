//
// Created by roberto on 31/07/15.
//

#include "constants.h"

/**@brief crea la direccion en home que sera utilizada para el output
 */
void createDirectory(){
    //Obtiene home
    PROJECT_PATH = getenv("HOME");
    //Concatena ruta
    strcat(PROJECT_PATH, "/");
    strcat(PROJECT_PATH, PROJECT_NAME);
    //Crea directorio
    mkdir(PROJECT_PATH, 0777);
}