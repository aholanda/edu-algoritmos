#include <stdio.h>

/* Tenenbaum, Langasam, Augenstein book */
void shellsort (int x[], int N, int incrs[], int nincrs)
{
	int incri, j, k, span, y;
	
	for (incri = 0; incri < nincrs; incri++) {
		span = incrs[incri];
		
		for (j = span; j < N; j++) {
			y = x[j];
			
			for (k = j-span; k >= 0 && y < x[k]; k -= span)
				x[k+span] = x[k];
			x[k+span] = y;
			
		}
	}
}

#define N 8
#define H 3 /* no. de incrementos */
int main()
{
	int x[N] = {25,57,48,37,12,92,86,33};
	int incrs[H] = {5, 3, 1};
	int i;

	shellsort(x, N, incrs, H);

	for (i = 0; i < N; i++)
		printf("x[%d]=%d ", i, x[i]);

	printf("\n");
	
	return 0;
}
