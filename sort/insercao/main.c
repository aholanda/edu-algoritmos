#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
// BEGIN IGNORAR
#define oo natribs++
#define ooo ntrocas++
#define o() ntrocas=0,natribs=0
#define imprime_custo()					\
	printf("\t[atribuicoes=%d, trocas=%d, TOTAL=%d]\n",	\
	       natribs, ntrocas, natribs+ntrocas)

static int ntrocas, natribs;

void imprime_vetor(int v[], int n);
void exec_insertion(int v[], int n);
void exec_shell(int v[], int n);
// END IGNORAR
/////////////////////////////////////////////////////////////////////////

/* complexidade - O(N²) */
void insertion_sort(int v[], int n) {
	int i, j; /* contadores */
	int t; /* variavel temporaria */

	for (i=1; i<n; i++ ){
		oo, t = v[i];
		for (j=i-1; j>=0 && t<v[j]; j--) {
			ooo, v[j+1] = v[j];
		}
		v[j+1] = t;
	}
}

/*
    hs[] - vetor com os incrementos
    nhs - numero de incrementos
    complexidade - O(N³²)
*/
void shellsort(int v[], int n, int hs[], int nhs) {
    int i, j, k; /* contadores */
    int t; /* variavel temporaria */
    int h; /* passo/incremento */

    for (i = 0; i < nhs; i++) {
	    h = hs[i];
	    for (j = h; j < n; j++) {
		    oo, t = v[j];
		    for (k = j-h; k >= 0 && t < v[k]; k -= h)
			    ooo, v[k+h] = v[k];
		    v[k+h] = t;
	    }
    }
}

#define N 7
int main() {
	//int v[N] = {16, 11, 8, 7, 6, 4, 3}; // pior caso
	//int v[N] = {3, 4, 6, 7, 8, 11, 16}; // melhor caso
	int v[N] = {8, 3, 16, 11, 7, 6, 4};
	int a[N] = {8, 3, 16, 11, 7, 6, 4};

	exec_insertion(v, N);
	exec_shell(a, N);

	return 0;
}

////////////////////////
// Funcoes auxiliares //
////////////////////////
//////////////////////////////////////////////////////////////////////
// BEGIN IGNORAR
void exec_insertion(int v[], int n) {
	o();
	printf("INSERTION-SORT:\n");
	imprime_vetor(v, n);
	insertion_sort(v, n);
	imprime_custo();
	imprime_vetor(v, n);
}

void exec_shell(int v[], int n) {
    int hs[] = {5, 3, 1};

    o();
    printf("\nSHELLSORT:\n");
    imprime_vetor(v, n);
    shellsort(v, n, hs, 3);
    imprime_custo();
    imprime_vetor(v, n);
}


void imprime_vetor(int v[], int n) {
    int i;

    printf("\t");
    for (i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
}
// END IGNORAR
//////////////////////////////////////////////////////////////////////
