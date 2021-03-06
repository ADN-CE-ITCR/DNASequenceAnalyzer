//
// Created by roberto on 31/07/15.
//

#include "globalConstants.h"

/**@brief crea la direccion en home que sera utilizada para el output
 */
void createDirectory() {
	//Obtiene home
	PROJECT_PATH = getenv("HOME");
	//Concatena ruta
	strcat(PROJECT_PATH, "/");
	strcat(PROJECT_PATH, PROJECT_NAME);
	//Crea directorio
	mkdir(PROJECT_PATH, 0777);
	strcat(PROJECT_PATH, "/");
}
void stackSizeIncreased() {
	const rlim_t kStackSize = 64L * 1024L * 1024L;   // min stack size = 64 Mb
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0) {
		if (rl.rlim_cur < kStackSize) {
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0) {
				fprintf(stderr, "setrlimit returned result = %d\n", result);
			}
		}
	}

}
