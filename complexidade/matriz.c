#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static clock_t ini, fim;

static long **matriz_alocar(long N) {
	long **mat, i;

	mat = (long **)calloc(N, sizeof(long *));
	for (i=0; i<N; i++)
		mat[i] = (long *)calloc(N, sizeof(long));

	return mat;
}

static void matriz_liberar(long **mat, long N) {
	int i;

	for (i=0; i<N; i++)
		free(mat[i]);

	free(mat);
}

long soma(long N) {
	int i, soma=0;

	ini = clock();
	for (i=0; i<N; i++)
		soma = soma + i*i*i;
	fim = clock();

	return (fim-ini);
}

long somat(long N) {
	long lin, col; /* linha, coluna */
	long **mat0, **mat1, **matr; /* primeira, segunda matrizes */
	clock_t begin, end; /* store time value */

	mat0 = matriz_alocar(N);
	mat1 = matriz_alocar(N);
	matr = matriz_alocar(N);

	/* gera numeros aleatorios para as matrizes */
	for (lin = 0; lin < N; lin++)
		for (col = 0; col < N; col++) {
			mat0[lin][col] = rand();
			mat1[lin][col] = rand();
		}

	begin = clock();
	for (lin = 0; lin < N; lin++)
		for (col = 0; col < N; col++) {
			matr[lin][col] = mat0[lin][col] + mat1[lin][col];
		}
	end = clock();

	matriz_liberar(mat0, N);
	matriz_liberar(mat1, N);
	matriz_liberar(matr, N);

	/* convert to second before returning */
	return (end-begin);
}

long mult(long N) {
	long lin, col, i; /* line, column and general purpose indices */
	long **mat0, **mat1, **matr; /* first, second, and resultant matrices */
	clock_t begin, end; /* store time value */
	long soma_prod = 0; /* sum-product*/

	mat0 = matriz_alocar(N);
	mat1 = matriz_alocar(N);
	matr = matriz_alocar(N);

	/* randomly generate matrices' elements */
	for (lin = 0; lin < N; lin++)
		for (col = 0; col < N; col++) {
			mat0[lin][col] = rand();
			mat1[lin][col] = rand();
		}

	begin = clock();
	for (lin = 0; lin < N; lin++)
		for (col = 0; col < N; col++) {
			soma_prod = 0;
			for(i=0; i<N; i++)
				soma_prod += mat0[lin][i] * mat1[i][col];
			matr[lin][col] = soma_prod;
		}
	end = clock();

	matriz_liberar(mat0, N);
	matriz_liberar(mat1, N);
	matriz_liberar(matr, N);

	/* convert to second before returning */
	return (end-begin);
}

#define M 8
int main(int argc, char*argv[]) {
	long ns[M] = {2<<4, 2<<5, 2<<6, 2<<7, 2<<8, 2<<9, 2<<10, 2<<11};
	int i;
	long dt;

	printf("######## Soma/mult. de matrizes ########\n");
	printf("N;soma;somat;mult\n");
	for (i=0; i<M; i++) {
		printf("%ld;", ns[i]);
		dt = soma(ns[i]);
		printf("%ld;", dt);
		dt = somat(ns[i]);
		printf("%ld;", dt);
		dt = mult(ns[i]);
		printf("%ld\n", dt);
	}
	return 0;
}
