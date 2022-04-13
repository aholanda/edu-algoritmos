#include <stdio.h> /* printf() */
#include <stdlib.h> /* srand(), rand() */
#include <time.h> /* time() clock() */

/*
   Modifique N -> 50, 100, 200, 500, 1000, 2500, 5000, 10000
   12000, 14000, 16000, 18000, 20000, 30000 (2 valores),
   50000 (1 valor)
*/

#define N 50

static int v[N]; /* vetor de inteiros positivos */

/*
  Inicializa os elementos do vetor v[0]=0, v[1]=1, ..., v[N-1]=N-1
  com os valores de seus indices.
*/
void inicializa() {
	int i;

	printf("> Inicializando o vetor de %d elementos\n\n", N);
	for (i=0; i<N; i++)
		v[i] = i;
}

/* Percorre o vetor v[] imprimindo seus elementos */
void imprime_vetor() {
	int i;

	for (i=0; i<N; i++)
		printf("v[%d]=%d, ", i, v[i]);
	printf("\n");
}

/*
  Embaralha troca os elementos do vetor v de lugar
  de acordo com o valor de uma variavel r.
*/
void embaralha() {
	int i, j, r, tmp;

    printf("> Embaralhando o vetor de %d elementos\n\n", N);
	srand(time(NULL));
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (i != j) {
				r = rand() % 10;
				/* troca v[i] e v[j] */
				if (r < 5) {
					tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
	}
}

/*
  Dado o vetor v[0], v[1], ..., [N-1], acha o indice j
  que corresponde ao maior valor do vetor.
*/
int max() {
	int i, j;

	j = N-1;
	i = N-2;
	while (i >= 0) {
		if (v[i] > v[j])
			j = i;
		i--;
	}
	return j;
}

/*
  Dado o vetor v[0], v[1], ..., [N-1], busca o valor x
  no vetor de inteiros positivos.
*/
int busca(int x) {
	int i;

	i = N-1;
	while (i >= 0) {
		if (x == v[i])
			break;
		i--;
	}
	return i;
}

void imprime_duracao(clock_t fim, clock_t ini, char *fun) {
    double delta_t = 0.0;

    delta_t = (double)(fim-ini)/CLOCKS_PER_SEC;

    printf("A execucao de %s durou => %lf\n", fun, delta_t);
}

int main(int argc, char **argv) {
	int r;
	clock_t ini, fim;

	inicializa();
	embaralha();
	//imprime_vetor();

	ini = clock();
	printf("max=%d\n", max());
	fim = clock();
	imprime_duracao(fim, ini, "max");

	/*
	  Sorteia de 0 ate N, o que significa que ha
	  chance de 1/N de nao achar o elemento no vetor.
	*/
	r = rand() % (N+1);
	ini = clock();
	printf("\nbusca(%d)=%d\n", r, busca(r));
	fim = clock();

	imprime_duracao(fim, ini, "busca");

	return 0;
}
