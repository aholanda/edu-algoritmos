#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

double bench(int N, enum sort_t sort_alg)
{
	long i, j, t, *v;
	clock_t begin, end;
	
	v = (long *)calloc(N, sizeof(long));
	
	for (i = 0; i < N; i++)
		v[i] = i;
	
	/* shuffle=embaralha */
	for (i = 0; i < N; i++) {
		j = rand() % N;
		t = v[i], v[i] = v[j], v[j] = t; /* v[i] <=> v[j]*/
	}
	fprintf(stderr, "Sorting %d values using ", N);
	
	begin = clock();
	switch(sort_alg) {
	case INSERTION:
		printf("insertionsort\n");
		insertionsort(v, N);
		break;
	case MERGE:
		printf("mergesort\n");
		mergesort(v, 0, N);
		break;
	case QUICK:
		printf("quicksort\n");
		quicksort(v, 0, N);
		break;
	default:
		break;
	}
	end = clock();
	free(v);
	
	return (double)(end-begin)*1000.0 / CLOCKS_PER_SEC; /* ms */
}

int main(int argc, char *argv[])
{/* 2^10=1024 2^16=65.536 2^17=131.072 2^18=262.144 2^19=524.288 */
        long i, j, Ns[5] = {1<<10, 1<<16, 1<<17, 1<<18, 1<<19};
	double dt;
	FILE *f;
	
	f = fopen("bench.dat", "w");
	
	for (i = 0; i < 5; i++) {
		fprintf (f, "%ld\t", Ns[i]);
		for (j = 0; j < 3; j++) {
			dt = bench(Ns[i], j);
			fprintf(f, "%8.16f\t", dt);
		}
		fprintf(f, "\n");
	}
	
	fclose(f);
	return 0;
}
