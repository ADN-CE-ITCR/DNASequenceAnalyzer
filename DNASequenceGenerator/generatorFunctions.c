//
// Created by roberto on 31/07/15.
//

#include "generatorFunctions.h"

/**@brief escribe una letra a partir de un numero
 * @param int number: letra
 * @param FILE* file: archivo
 */
void write(int number, FILE* file){
    switch(number){
        case 0:
            printf("A");
            fputc('A', file);
            break;
        case 1:
            printf("C");
            fputc('C', file);
            break;
        case 2:
            printf("G");
            fputc('G', file);
            break;
        case 3:
            printf("T");
            fputc('T', file);
            break;
    }
}

/**@brief calcula la potencia de un numero
 * @param int base: numero a elevar
 * @param power: potencia
 */
long getPow(int base, unsigned short int power){
    long result = 1;
    int i;
    for(i = 0; i<power; i++) result*=base;
    return result;
}

/**@brief pregunta al usuario los datos requeridos
 * @param int* lenght: variable en la cual se almacenara la longitud de la secuencia
 * @param char* name: variable en la cual se almacenara el nombre de la secuencia
 */
void ask(int* lenght, char* name, pthread_mutex_t* mutualExclusion){
    pthread_mutex_lock(mutualExclusion);
    //Solicita longitud
    do{
        printf("%s\n",LENGHT_SENTENCE);
        scanf("%d",lenght);
    }while(*lenght > MAX_SEQUENCE_LENGHT);
    //Solicita nombre
    printf("%s\n",FILE_NAME_SENTENCE);
    scanf("%s",name);
    pthread_mutex_unlock(mutualExclusion);
}

/**@brief genera la secuencia aleatoria
 * @param int* lenght: variable que direcciona la longitud de la secuencia
 * @param char* name: variable que direcciona el nombre de la secuencia
 */
void generate(int* lenght, char* name, pthread_mutex_t* mutualExclusion){
    pthread_mutex_lock(mutualExclusion);
    FILE* sequence;
    char* tmpName = malloc(strlen(PROJECT_PATH)+MAX_NAME_LENGHT+4);
    strcpy(tmpName,PROJECT_PATH);
    strcat(tmpName,name);
    strcat(tmpName,FILE_EXT);
    printf("%s \n", tmpName);
    if(sequence = fopen(tmpName,"w+")) {
        printf(SUCCESSFUL);
        int i;
        for (i = 0; i < *lenght; i++) {
            write(rand() % ENCODING_BASE, sequence);
        }
        printf("\n");
    }else printf(FILE_ALREADY_EXISTS);
    free(tmpName);
    //Cierra el archivo y desbloque mutex
    fclose(sequence);
    pthread_mutex_unlock(mutualExclusion);
}

/**@brief se encarga de controlar las iteraciones realizadas
 * @param void* detach: parametro para detach de pthread
 * @return void* detach significa correcto
 */
void* receiverThread(void* detach){
    //Da la bienvenida e inicializa el random
    createDirectory();
    printf("%s %s \n",HELLO,PROJECT_NAME);
    srand(time(NULL));
    //Declara las variables a utilizar
    pthread_mutex_t* mutualExclusion = (pthread_mutex_t*)(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(mutualExclusion,NULL);
    char* fileName = (char*)malloc(sizeof(char));
    int* sequenceLenght = (int*)malloc(sizeof(int));
    char* excecuting = (char*)malloc(sizeof(char));
    *excecuting = 1;
    //Inicia loop que pregunta por los datos, genera la secuencia
    while(*excecuting){
        //Este bloque se repite hasta que el usuario cambie el valor de la bandera por 'N'
        ask(sequenceLenght, fileName, mutualExclusion);
        generate(sequenceLenght, fileName, mutualExclusion);
        printf("%s \n",DO_YOU_WANT_TO_CONTINUE);
        scanf("%d",excecuting);
    }
    //Libera memoria
    free(mutualExclusion);
    free(sequenceLenght);
    free(excecuting);
    free(fileName);
    //Se despide del usuario y retorna
    printf("%s",GOODBYE);
    return detach;
}
