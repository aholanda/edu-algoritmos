#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 128

static int fp[M], N;
static int tmp;

#define troca(i,j) (tmp=fp[(i)],fp[(i)]=fp[(j)],fp[(j)]=tmp)

void subir(int i)
{
	int j;

	j = floor((i-1)/2);
	
	if (i>=0 && i<N)
		if (fp[i]>fp[j]) {
			troca (i, j);
			subir(j);
		}
}

void descer(int i)
{
	int j;
	
	j = 2*i + 1;
	
	if (j<N) {
		if (j<N-1)
			if (fp[j+1]>fp[j])
				j++;
		
		if (fp[i]<fp[j]) {
			troca(i, j);
			descer(j);
		}
	}
}

void inserir(int k)
{
	if (N<M) {
		fp[N++] = k;
		subir(N-1);
	} else {
		printf("overflow\n");
		exit(-1);
	}
}

void remover()
{
	if (N>0) {
		fp[0] = fp[--N];
		descer(N-1);
	} else {
		printf("underflow");
		exit(-1);
	}
}

void print_filaprio() {
	int i;
	
	for (i=0; i<N; i++)
		printf("%d ", fp[i]);
	
	printf("\n");
}

int main(int argc, char**argv)
{
	static int a[8] = {95, 60, 78, 39, 28, 66, 70, 33};
	int i;
	
	for (i=0; i<8; i++)
		inserir(a[i]);

	printf("Fila inicial:\t\t\t\t\t");
	print_filaprio();
	
	printf("Alterar prioridade fp[5]:\t%d -> 98 =>\t", fp[5]);
	fp[5] = 98;
	subir(5);

	print_filaprio();

	printf("Retorna os valores originais:\t\t\t");
	for (i=0; i<8; i++)
		remover();
	for (i=0; i<8; i++)
		inserir(a[i]);

	print_filaprio();
	
	printf("Diminuir prioridade fp[0]:\t%d -> 37 =>\t", fp[0]);
	fp[0] = 37;
	descer(0);

	print_filaprio();


	return 0;
}
