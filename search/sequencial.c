#include <stdlib.h>
#include <limits.h>
#include "busca.h"

/*  Esta funcao recebe um vetor $v[0..N-1]$ com $N>1$ e um
    inteiro $k$. Ela retorna um indice $i$ em $0..N-1$ se a busca for
    bem sucedida, e retorna -1 em caso de falha na busca. */
int BuscaSequencialS(int k, int N, int v[])
{
	int i;
	for ( /* S0 */ i = 0; i < N; /* S2 */ i++) {
		if (v[i] == k)	/* S1 */
			return i;	/* SUCESSO */
	}
	/* S3 */
	return -1;		/* FALHA */
}

 /* Esta funcao recebe um vetor $v[0..N-1]$ com $N>1$ e um
    inteiro $k$. A chave $v[N]$ eh ficticia e recebe o valor da chave
    procurada. A busca para quando a chave eh encontrada, coma a
    comparacao feita dentro no laco. Se $i$ for menor que $N$, a
    busca obteve sucesso, se $i=N$, a chave nao foi encontrada. Este
    "truque" elimina um comparacao (desvio de fluxo). */
int BuscaSequencialQ(int k, int N, int v[])
{
	int i;			/* contador */
	/* aloca espaco para o registro ficticio */
	v = realloc(v, (N + 1) * sizeof(int));
	/* marca o fim do arquivo, registro ficticio,
	   com o valor da chave procurada */
	v[N] = k;
	for ( /* Q0 */ i = 0; /* Q1 */ k != v[i]; /* Q2 */ i++) ;
	/* Q3 */
	if (i < N)
		return i;	/* SUCESSO */
	else
		return -1;	/* i==N, FALHA */
}

/* Esta funcao recebe um vetor $v[0..N-1]$ ordenado com $N>1$ e a
   chave procurada $k$. Ela retorna o indice $i$ do elemento, se este
   existir na tabela de chaves, caso contrÃ¡rio retorna -1, para
   indicar falha na busca. */
int BuscaSequencialOrd(int k, int N, int v[]) {
  int i;

  while (i < N && v[i] < k) i++;

  if (i < N) return i;
  else return -1;

}

/*  Esta funcao recebe um vetor $v[0..N]$ com $N>1$ e um inteiro
    $k$. A busca para quando a chave corrente eh maior ou igual a $k$,
    sendo que a comparacao eh feita dentro do loop for. Se $k$ for
    igual $v[i]$, a busca obteve sucesso, se $v[i]=\infty$, a chave
    nao foi encontrada. O valor $\infty$ eh atribuido ao elemento
    ficticio do vetor. */
#define INFINITO INT_MAX	/* valor inteiro maximo suportado: 32.767$\equiv 2^{15}-1$ */
int BuscaSequencialT(int k, int N, int v[])
{
	int i;			/* contador */
	/* aloca espaco para o registro ficticio */
	v = realloc(v, (N + 1) * sizeof(int));
	/* marca o fim do arquivo, registro ficticio,
	   com o valor da chave procurada */
	i = 0;
	v[N] = INFINITO;	/* T0 */
	while (k >= v[i])	/* T1 */
		i++;		/* T2 */
	/* T3 */
	if (k = v[i])
		return i;	/* SUCESSO */
	else
		return -1;	/* i==N, FALHA */
}

struct cel *BuscaSequencialL(int k, struct cel *l)
{
	struct cel *p;

	p = l;
	while (p != NULL) {
		if (k == p->chave)
			break;
		p = p->prox;
	}
	return p;
}
