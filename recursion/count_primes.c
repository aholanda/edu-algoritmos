#include <stdio.h>
#include <stdlib.h>
/*
  This program counts the number of primes if a interval between
  integers a and b.
*/

#define TRUE 1
#define FALSE 0

int is_prime(int num) {
	int i;
	
	if (num <= 1)
		return FALSE;

	if (num % 2 == 0 && num > 2)
		return FALSE;

	for (i=3; i<num/2; i+=2)
		if (num % i == 0)
			return FALSE;
	
	return TRUE;
}

void count_primes(int a, int b, int *pi) {
	if (a > b) {
		printf("%d primes between %d and %d.\n", 0, a, b);
		exit(-1);
	}

	if (is_prime(b) == TRUE) {
		(*pi)++;
		printf ("%d %d\n", b, *pi);
	}
	
	if (b > a) {
		count_primes(a, b-1, pi);
	} else {
		return;
	}

	return;
}

int main(int argc, char*argv) {
	int nprimes = 0;

	count_primes(2, 8, &nprimes);
	
	printf("%d\n", nprimes);
	
	return 0;
}
