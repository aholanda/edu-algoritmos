#include <stdio.h>

int puzzle(int n) {

	if (n == 1)
		return 1;

	if (n % 2 == 0)
		return puzzle(n/2);

	else return puzzle(3*n+1);
}


int main(int atgc, char*argv) {
	int i;
	i = 5;
	printf("puzzle(%d)=%d\n", i, puzzle(i));
	i = 6;
	printf("puzzle(%d)=%d\n", i, puzzle(i));
}
