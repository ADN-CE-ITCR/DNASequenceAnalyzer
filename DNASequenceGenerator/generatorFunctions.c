//
// Created by roberto on 31/07/15.
//

#include "generatorFunctions.h"

/**@brief pregunta al usuario los datos requeridos
 * @param int* lenght: variable en la cual se almacenara la longitud de la secuencia
 * @param char* name: variable en la cual se almacenara el nombre de la secuencia
 */
void ask(int* lenght, char* name, pthread_mutex_t* mutualExclusion){
    pthread_mutex_lock(mutualExclusion);
    //Solicita longitud
    printf("%s\n",LENGHT_SENTENCE);
    scanf("%d",lenght);
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
    pthread_mutex_unlock(mutualExclusion);
}

/**@brief se encarga de controlar las iteraciones realizadas
 * @param void* detach: parametro para detach de pthread
 * @return 0 significa correcto
 */
void* receiverThread(void* detach){
    //Da la bienvenida e inicializa el random
    printf("%s %s",HELLO,PROJECT_NAME);
    srand(time(NULL));
    //Declara las variables a utilizar
    pthread_mutex_t* mutualExclusion = (pthread_mutex_t*)(malloc(sizeof(pthread_mutex_t)));
    pthread_mutex_init(mutualExclusion,NULL);
    char* fileName[MAX_NAME_LENGHT];
    int* sequenceLenght = (int*)malloc(sizeof(int));
    char* excecuting = (char*)malloc(sizeof(char));
    *excecuting = 1;
    //Inicia loop que pregunta por los datos, genera la secuencia
    while(*excecuting != 0){
        //Este bloque se repite hasta que el usuario cambie el valor de la bandera por 'N'
        ask(sequenceLenght, fileName, mutualExclusion);
        generate(sequenceLenght, fileName, mutualExclusion);
        printf("%s \n",DO_YOU_WANT_TO_CONTINUE);
        scanf("%d",excecuting);
    }
    free(mutualExclusion);
    free(sequenceLenght);
    free(excecuting);
    //Se despide del usuario y retorna
    printf("%s",GOODBYE);
    return detach;
}
