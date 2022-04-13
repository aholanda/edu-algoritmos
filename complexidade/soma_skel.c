#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 64 /* 128, 256, 512, 1024, 2056 */

int main(int argc, char**argv) {
	int i, soma=0;
	clock_t ini, fim, dt;  /* variaveis de 'tempo' */

	ini = clock();
	/* Insira a logica do programa aqui */


	/* FIM LOGICA */
	fim = clock();

	dt = fim - ini;
	printf("dt=%ld\n", dt);
}
