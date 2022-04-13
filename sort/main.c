#include "sort.h"

#define N 8

char *sort_str[] = {"Counting sort", "Insertion sort", "Merge sort", "Quicksort", "Radix sort"};

static void usage(char *prog) {
	int i;
	
	printf("uso: %s <numero do algoritmo>\n", prog);
	printf("onde\n");

	for (i = 0; i < __END; i++) {
		printf ("\t%d: %s\n", i, sort_str[i]);
	}
	exit(-1);
}

int main(int argc, char*argv[])
{
	long v[N] = {11, 70, 82, 72, 34, 25, 5, 9};
	int aid = -1;
	
	if (argc > 1) {
		aid = atoi(argv[1]);

		switch(aid){
		case COUNTING:
			countingsort(v, N);
			break;
		case INSERTION:
			insertionsort(v, N);
			break;
		case MERGE:
			mergesort(v, 0, N);
			break;
		case QUICK:
			quicksort(v, 0, N);
			break;
		case RADIX:
			radixsort(v, N);
			break;			
		default:
			break;

		}
	} else
		usage(argv[0]);
		
	print_array(v, N);
	
	return 0;
}
