//
// Created by roberto on 31/07/15.
//

#include "alignerFunctions.h"

void analyzeData(struct SequenceToAlign* toAlign){
    int columns= **(toAlign->sequencesLenght) + 2;
    int rows= **(toAlign->sequencesLenght + 1) + 2;
    int index;
    for(index = 0; index < **(toAlign->sequencesLenght) + 2; index++) *(toAlign->scoringMatrix + index*rows) = D*index;
    for (index = 0; index < **(toAlign->sequencesLenght + 1) + 2; index++) *(toAlign->scoringMatrix + index) = D*index;
    printf(toAlign->scoringMatrix);
}

/**@brief obtiene los nombres y abre los archivos
 * @param struct SequenceToAlign toAlign: estructura donde se guardaran los datos
 */
void getSequences(struct SequenceToAlign* toAlign){
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
            fseek(file, 0, SEEK_END);
            **(toAlign->sequencesLenght + i) = ftell(file);
            fseek(file, 0, SEEK_SET);
            *(toAlign->sequences + i) = malloc(**(toAlign->sequencesLenght + i));
            fgets(*(toAlign->sequences + i),**(toAlign->sequencesLenght + i),file);
            printf("%d \n",**(toAlign->sequencesLenght + i));
            printf(SUCCESSFUL,i,*(toAlign->sequences+i));
            fclose(file);
        }else{
            printf(FILENAME_ERROR);
            --i;
        }
        free(tmpName);
    }
    toAlign->scoringMatrix = calloc(**toAlign->sequencesLenght, **(toAlign->sequencesLenght + 1));
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
    char* excecuting = (char*)malloc(sizeof(char));
    *excecuting = 1;
    struct timespec timeController;
    timeController.tv_sec=1;
    while(*excecuting){
        pthread_mutex_lock(mutualExclusion);
        //Obtiene los datos, llena la estructura con secuencias y matriz de resultados
        struct SequenceToAlign toAlign;
        toAlign.sequences = (char**)malloc(2*sizeof(char*));
        toAlign.sequencesLenght = (int**)malloc(2*sizeof(int*));
        *(toAlign.sequencesLenght) = (int*)malloc(sizeof(int));
        *(toAlign.sequencesLenght+1) = (int*)malloc(sizeof(int));
        getSequences(&toAlign);
        analyzeData(&toAlign);
        free(*toAlign.sequences);
        free(toAlign.sequences);
        free(*toAlign.sequencesLenght);
        free(toAlign.sequencesLenght);
        nanosleep(&timeController,NULL);
        printf("%s \n",DO_YOU_WANT_TO_CONTINUE);
        scanf("%d",excecuting);
        pthread_mutex_unlock(mutualExclusion);
    }
    //Libera memoria
    free(mutualExclusion);
    free(excecuting);
    //Se despide del usuario y retorna
    printf("%s",GOODBYE);
    return detach;
}