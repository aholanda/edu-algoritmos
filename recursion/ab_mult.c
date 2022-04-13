#include <stdio.h>
#include <stdlib.h>

/*
  Recursive algorithm to multiply Natural Numbers using the recurrence:
  ab = a = 1 if b = 1  
  ab = a + a(b-1)
*/

int ab_mult(int a, int b) {
	if (b == 1)
		return a;
	else
		return a + ab_mult(a, b-1);
}

int main()
{
    printf("%d\n", ab_mult(4,3));

    return 0;
}
