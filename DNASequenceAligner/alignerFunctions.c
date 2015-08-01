//
// Created by roberto on 31/07/15.
//

#include "alignerFunctions.h"

/**@brief crea, llena y retorna la matriz
 * @param int lenghtOne: longitud uno
 * @param int lenghtTwo: longitud dos
 * @param char* secuenceOne: secuencia uno
 * @param char* sequenceTwo: secuencia dos
 * @return char* matrix: matriz llena
 */
char* fillMatrix(int lenghtOne, int lenghtTwo, char* secuenceOne, char* sequenceTwo){
    char matrix[lenghtOne][lenghtTwo];
    return matrix;
}

/**@brief convierte un numero a letra
 * @param int number: numero a convertir
 */
char intToDNA(int number){
    switch(number){
        case 0:
            printf("A");
            return "A";
        case 1:
            printf("C");
            return "C";
        case 2:
            printf("G");
            return "G";
        case 3:
            printf("T");
            return "T";
    }
}

/**@brief se encarga de controlar las iteraciones realizadas
 * @param void* detach: parametro para detach de pthread
 * @return void* detach significa correcto
 */
void* alignerThread(void* detach){
    //Da la bienvenida e inicializa el random
    createDirectory();
    printf("%s %s \n",HELLO,PROJECT_NAME);
    //Declara las variables a utilizar
    pthread_mutex_t* mutualExclusion = (pthread_mutex_t*)(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(mutualExclusion,NULL);
    char* FileName = (char*)malloc(MAX_NAME_LENGHT);
    //TODO: preguntar por ambos archivos y leerlos en un char*
    int* firstSequenceLenght = (int*)malloc(sizeof(int));
    int* secondSequenceLenght = (int*)malloc(sizeof(int));
    //TODO: obtener logitud
    char* excecuting = (char*)malloc(sizeof(char));
    *excecuting = 1;
    //Inicia loop que pregunta por los datos, genera la secuencia
    while(*excecuting){
        //TODO: completar
        printf("%s \n",DO_YOU_WANT_TO_CONTINUE);
        scanf("%d",excecuting);
    }
    //Libera memoria
    free(mutualExclusion);
    free(secondSequenceLenght);
    free(excecuting);
    free(fileName);
    //Se despide del usuario y retorna
    printf("%s",GOODBYE);
    return detach;
}