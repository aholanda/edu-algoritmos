#include "sort.h"

/* Ordenacao por insercao. */
/* Ordena o vetor x[0..N-1] utilizando o algoritmo de insercao simples */
/* Complexidade: O(n^2)*/
void insertionsort(long v[], long N) {
	long i, j, x;
	for (i = 1; i < N; i++) {
		x = v[i];
		for (j = i-1; j >=0 && v[j] > x; j--)
			v[j+1] = v[j];
		v[j+1] = x;
	}
}

#define N 8
long example()
{
	long v[N] = {25,57,48,37,12,92,86,33};

	insertionsort(v, N);

	print_array(v, N);
	
	return 0;
}
