#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"

#define BUFLEN 69		/* tamanho maximo do buffer */

void testa_BuscaSequencialL()
{
	struct cel *L, *l, *prev;
	int i, N;
	char buf[BUFLEN];	/* armazena a string de entrada */

	printf("Entre com o no. de elementos da listas: ");
	fgets(buf, BUFLEN, stdin);	/* no terminal digite man fgets */
	N = atol(buf);		/* converte a string em int */
	if (0 == N && 7 > N) {
		fprintf(stderr,
			"Erro ao converter o no. de elementos da lista\n");
		exit(-1);
	}

	L = (struct cel *)calloc(N, sizeof(struct cel));
	prev = NULL;
	for (i = 0, l = L; i < N; i++, l++) {
		l->chave = i;

		if (prev != NULL)
			prev->prox = l;

		prev = l;
	}

	l = BuscaSequencialL(N - 7, L);
	if (l != NULL)
		printf("chave %d encontrada\n", l->chave);
	else
		printf("chave NAO encontrada\n");

	free(L);
}

static checa_chave(int i, int k, int ret)
{
	if (ret == -1)
		printf("Chave %d NAO encontrada\n", k);
	else
		printf("Chave %d encontrada na posicao %d\n", k, i);
}

static void testa_SxB()
{
	int i, k, ret;		/* contador, chave e valor de retorno */
	int *v;		/* conjunto de chaves k */
	int N;			/* numero de elementos no vetor */
	clock_t inicio, fim;	/* inicio e fim da medida de tempo */
	char buf[BUFLEN];

	printf("Este programa compara a busca binária com a sequencial.\n");
	printf("Entre com o no. de elementos da vetor de busca: ");
	fgets(buf, BUFLEN, stdin);
	N = atol(buf);		/* converte a string em int */

	v = calloc(N, sizeof(int));

	for (i = 0; i < N; i++)
		v[i] = i;

	k = N - 3;
	inicio = clock();
	ret = BuscaSequencialS(k, N, v);
	checa_chave(ret, k, ret);
	fim = clock();
	printf("busca sequencial rapida levou %f ns\n", (float)(fim - inicio));

	inicio = clock();
	ret = BuscaBinaria(k, N, v);
	checa_chave(ret, k, ret);
	fim = clock();
	printf("busca binaria levou %2.32f ns\n", (double)(fim - inicio));

	free(v);
}

int main(int argc, char *argv[])
{
	testa_BuscaSequencialL();

	testa_SxB();
	
	return 0;
}
