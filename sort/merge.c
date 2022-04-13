#include <stdlib.h>
/* Baseado no livro "Algoritmos em C" de Feofiloff
   procedimento para combinar dois subvetores ordenados */
void merge(long v[], long lo, long mid, long hi) {
	long i, j, k, *aux;
	aux = calloc(hi-lo, sizeof(long));
	i=lo, j=mid, k=0;
	while (i<mid && j<hi) {
		if (v[i]<=v[j]) aux[k++] = v[i++];
		else aux[k++] = v[j++];
	}
	while (i<mid) aux[k++] = v[i++];
	while (j<hi) aux[k++] = v[j++];
	for (i=lo; i<hi; i++) v[i] = aux[i-lo];
	free(aux);
}

/* Ordena o vetor v[lo..hi-1] utilizando o algoritmo mergesort. */
void mergesort(long v[], long lo, long hi) {
	if (lo<hi-1) {
		long mid = (lo+hi) / 2;
		mergesort(v, lo, mid);
		mergesort(v, mid, hi);
		merge(v, lo, mid, hi);
	}
}
