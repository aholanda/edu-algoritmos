#include <math.h>
#include <stdio.h>

/* Retorna o indice do maior elemento no vetor v[N]. */
int max_rec(int v[], int N) {
	int j;

	if (N==1){
		return 0;
	}

	j = max_rec(v, N-1);
	if (v[N-1]>v[j]) {
		j = N-1;
	}
	return j;
}

/* Busca o indice do elemento x no vetor v[N]. */
int busca_rec(int v[], int N, int x) {
	int j;

	if (v[N-1]==x) {
		return N-1;
	}

	if (N==1){
		return -1; // Nao achou
	} else {
		j = busca_rec(v, N-1, x);
	}
	return j;
}

/* Retorna a soma harmonica H(N) = N + H(N-1). */
float harm_rec(int N) {
	if (N==1){
		return 1;
	}
	return harm_rec(N-1) + 1/(float)N;
}

/* Retorna a soma triangular usando a recorrencia
   T(N) = T(N-1) + N. */
float somatri_rec(int N) {
	if (N==1){
		return 1;
	}
	return somatri_rec(N-1) + N;
}

/* Retorna a aproximação de Stirling
   S(N) = lgN + S(N-1). */
float stirling_rec(int N) {
	if (N==1){
		return log(1.0)/log(2.0);
	}
	return stirling_rec(N-1) + log((float)N)/log(2.0);
}

/* Funcao principal */
int main(int argc, char**argv) {
	int v[5] = {5, 3, 8, 4, 1};
	int N = 5;

	/* exemplo de uso */
	printf("%d\n", max_rec(v, N));
	printf("%d\n", busca_rec(v, N, 4));
	printf("%f\n", harm_rec(N));
	printf("%f\n", somatri_rec(N));
	printf("%f\n", stirling_rec(N));

}
