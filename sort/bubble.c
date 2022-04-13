#include "sort.h"

void bubblesort0(int x[], int N)
{
	int i, j, t;

	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - 1 - i; j++)
			if (x[j] > x[j+1]) { /* swap (troca) */
				t = x[j];
				x[j] = x[j+1];
				x[j+1] = t;
			}

	}
}

void bubblesort(int x[], int N)
{
	int i, j, t;
	bool switched = true;

	for (i = 0; i < N - 1 && switched == true; i++) {
		switched = false;
		for (j = 0; j < N - 1 - i; j++)
			if (x[j] > x[j+1]) { /* swap (troca) */
				switched = true;
				t = x[j];
				x[j] = x[j+1];
				x[j+1] = t;
			}
	}
}

int main(int argc, char*argv[])
{
	print_array(szwar, 7);
	bubblesort0(szwar, 7);
	print_array(szwar, 7);

	return 0;
}
