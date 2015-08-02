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

/**@brief obtiene los nombres y abre los archivos
 * @param struct SequenceToAlign toAlign: estructura donde se guardaran los datos
 */
void getSequences(struct SequenceToAlign* toAlign, pthread_mutex_t* mutex){
    pthread_mutex_lock(mutex);
    toAlign = (struct SequenceToAlign*)malloc(sizeof(struct SequenceToAlign));
    toAlign->sequences = (char**)malloc(2*sizeof(char*));
    toAlign->sequencesLenght = (int**)malloc(2*sizeof(int*));
    *(toAlign->sequencesLenght) = (int*)malloc(sizeof(int));
    *(toAlign->sequencesLenght+1) = (int*)malloc(sizeof(int));
    int i;
    for(i = 0; i < 2; i++){
        char* tmpName = malloc(strlen(PROJECT_PATH)+MAX_NAME_LENGHT+4);
        char* fileNameBuffer = malloc(MAX_NAME_LENGHT);
        printf(INPUT_MSJ);
        scanf("%s",fileNameBuffer);
        strcpy(tmpName,PROJECT_PATH);
        strcat(tmpName,fileNameBuffer);
        strcat(tmpName,FILE_EXT);
        free(fileNameBuffer);
        FILE* file;
        if(file=fopen(tmpName,"r")){
            fseek(file,0L,SEEK_END);
            **(toAlign->sequencesLenght + i) = ftell(file);
            *(toAlign->sequences + i) = malloc(**(toAlign->sequencesLenght + i));
            int j;
            //TODO: arreglar lectura
            for(j = 0; j < **(toAlign->sequencesLenght + i) ; j++) *(*(toAlign->sequences + i)+ j) = (char)fgetc(file);
            printf("%d \n",**(toAlign->sequencesLenght + i));
            printf(SUCCESSFUL,i,*(toAlign->sequences+i));
            fclose(file);
        }else{
            printf(FILENAME_ERROR);
            --i;
        }
        free(tmpName);
    }
    pthread_mutex_unlock(mutex);
}

/**@brief se encarga de controlar las iteraciones realizadas
 * @param void* detach: parametro para detach de pthread
 * @return void* detach significa correcto
 */
void* alignerThread(void* detach){
    //Da la bienvenida e inicializa el random
    createDirectory();
    printf("%s %s \n",HELLO,PROJECT_NAME);
    //Declara los mutex
    pthread_mutex_t* mutualExclusion = (pthread_mutex_t*)(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(mutualExclusion,NULL);
    //Crea variables e inicia loop que pregunta por los datos, genera la secuencia
    struct SequenceToAlign* toAlign;
    char* excecuting = (char*)malloc(sizeof(char));
    *excecuting = 1;
    while(*excecuting){
        //Obtiene los datos, llena la estructura con secuencias y matriz de resultados
        getSequences(toAlign, mutualExclusion);
        printf("%s \n",DO_YOU_WANT_TO_CONTINUE);
        scanf("%d",excecuting);
    }
    //Libera memoria
    free(mutualExclusion);
    free(excecuting);
    //Se despide del usuario y retorna
    printf("%s",GOODBYE);
    return detach;
}