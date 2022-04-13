#include "sort.h"

void radixsort(long v[], long N) {
	long i, rad = 1, max = 0, bucket[10], *aux;

	aux = calloc(N, sizeof(long));

	// acha o maior elemento do vetor
	for(i = 0; i < N; i++) 
		if(v[i] > max) 
			max = v[i];
		

	// bucket armazena o numero de elementos em cada digito
	while((max/rad) > 0) {
		for (i = 0; i < 10; i++) 
			bucket[i] = 0;
		
		for(i = 0; i < N; i++) 
			bucket[(v[i] / rad) % 10]++;
		
		for(i = 1; i < 10; i++) 
			bucket[i] += bucket[i-1];
		
		for(i = N-1; i >= 0; i--) 
			aux[--bucket[(v[i] / rad) % 10]] = v[i];
		
		for(i = 0; i < N; i++) 
			v[i] = aux[i];
		
		rad *= 10;
	}
	free(aux);
}
