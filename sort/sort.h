#ifndef EDU_ALG_SORT_H
#define EDU_ALG_SORT_H

#include <stdio.h>
#include <stdlib.h>

#define print_array(v,N)  do {			\
		int i;				\
		for (i=0; i<(N); i++) 		\
			printf ("%ld ", (v)[i]);	\
		printf("\n");				\
						\
	} while(0)					

/* 0 Algoritmos de Ordenacao. */

enum sort_t {COUNTING, INSERTION, MERGE, QUICK, RADIX, __END};

extern void countingsort(long v[], long N);
extern void insertionsort(long v[], long N);
extern void mergesort(long v[], long lo, long hi);
extern void quicksort(long v[], long inf, long sup);
extern void radixsort(long v[], long N);
#endif
