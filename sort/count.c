/* Ordena o vetor v[0..N-1] using o algoritmo Counting-Sort */
#include "sort.h"

void countingsort(long v[], long N) {
	long *count; /* vetor de contagem */
	long *aux; /* vetor auxiliar */
	long i, j;

	count = calloc(N, sizeof(long));
	aux = calloc(N, sizeof(long));
	
	for (i = N-1; i > 0; i--)
		for (j=i-1; j >= 0; j--) {
			if (v[i] < v[j])
				count[j]++;
			else
				count[i]++;
		}
	/* copia o vetor de acordo com a ordem da contagem 
	   para o vetor auxiliar */
	for (i = 0; i < N; i++)
		aux[count[i]] = v[i];

	/* copia o o conteudo do vetor auxiliar de volta 
	   para o vetor original */
	for (i = 0; i < N; i++)
		v[i] = aux[i];

	free(count);
	free(aux);
}

