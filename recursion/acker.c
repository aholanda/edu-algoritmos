#include <stdio.h>
#include <stdlib.h>

/*
  This program calculates the Ackermann function defined as
  A(m,n) = n+1, if m = 0;  (1)
  A(m,n) = A(m-1,1), if n = 0;  (2)
  A(m,n) = A(m-1, A(m, n-1)), if m # 0 /\ n # 0. (3)
*/

int acker(int m, int n) {
	if (m == 0) /* (1) */
		return n+1;
	if (n == 0) /* (2) */
		acker(m-1, 1);
	if (n != 0 && m != 0) /* (3) */
		acker(m-1, acker(m, n-1));
}

/* declare prototype of non-recursive Ackermann function */
int acker_nonrec(int m, int n);

int main(int argc, char*argv) {
	int m = 2, n = 3;
	printf("Ackermann(%d, %d)=%d\n", m, n, acker(m, n));
	printf("non-recursive Ackermann(%d, %d)=%d\n", m, n, acker_nonrec(m, n));
}

/* e.g.
   A(2,2) = A(1, A(2,1)) = A(1, A(1, A(2,0))) = A(1, A(1, A(1,1))) =
   = A(1, A(1, A(0, A(1, 0)))) = A(1, A(1, A(0, A(0, 1)))) = 
   = A(1, A(1, A(0, 2))) = A(1, A(1, 3)) =
   = A(1, A(0, A(1, 2))) = A(1, A(0, A(0, A(1,1)))) =
   = A(1, A(0, A(0, A(0, A(1, 0))))) = A(1, A(0, A(0, A(0 , 2)))) =
   = A(1, A(0, A(0, 3))) = A(1, A( 0, 4)) = A(1, 5) =
   = A(0, A(1, 4)) = A(0, A(0, A(1, 3))) = A(0, A(0, A(0, A(1, 2)))) = 
   = A(0, A(0, A(0, A(0, A(1,1))))) = A(0, A(0, A(0, A(0, A(0, A(1, 0)))))) = 
   = A(0, A(0, A(0, A(0, A(0, 2))))) = A(0, A(0, A(0, A(0, 3))) = 
   = A(0, A(0, A(0, 4))) = A(0, A(0, 5)) = A(0, 6) = 7 
*/
/* -- array implementation of stack --               */
/* put element at the 'top' of stack and increment top */
#define EMPTY -1
static void push(int stack[], int *top, int elem) {
	(*top)++;
	stack[(*top)] = elem;
}

static int pop(int stack[], int *top) {
	int elem;
	
	if ((*top) == EMPTY)
		return EMPTY;
	else {
		elem = stack[(*top)];
		(*top)--;
	}
	return elem;
}

/* non-recursive implementation of Ackermann function */
int acker_nonrec(int m, int n) {
	int *stack, tmp;
	int top = EMPTY;

        /* max len of stack is m+1 */
	stack = (int *)calloc(m+1, sizeof(int));

	push(stack, &top, m); /* first load in the stack */
	do {
		if (m > 0 && n > 0) { /* (1) */
			m--;
			push(stack, &top, m);
			m++;
			n--;
		}
		if (n == 0) { /* (2) */
			m--;
			n = 1;
		}
		if (m == 0) { /* (3) */
			n++;
			m = pop(stack, &top);
		}
	} while (top != EMPTY);

	free(stack);

	return n;
}
