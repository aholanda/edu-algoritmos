/*
  versao: 20160427
  Implementacao do tipo abstrato de dados fila
  usando alocacao sequencial (vetor).
*/

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

#define TAM_FILA 4 /* tamanho da fila */

/* solucao baseada no livro "introducao a estrutura de dados" de
 * Celes, Cequeira e Rangel */
struct fila {
	int v[TAM_FILA];
	int ini; /* inicio da fila */
	int n;
};

Fila *fila_cria()
{
	Fila *p;

	p = malloc(sizeof(Fila));
	p->ini = 0;
	p->n = 0;

	return p;
}

void fila_insere(Fila *p, int k)
{
	int fim;

	if (fila_cheia(p)) {
		printf("Capacidade da fila excedida!\n");
		exit(-1);
	}
	
	fim = (p->ini + p->n) % TAM_FILA;
	p->v[fim] = k;
	p->n++;
}

int fila_retira(Fila *p)
{
	int k;
	
	if (fila_vazia(p)) {
		printf("Fila vazia!\n");
		exit(-1);
	}
	k = p->v[p->ini];
	p->ini = (p->ini + 1) % TAM_FILA;
	p->n--;

	return k;
}

int fila_cheia(Fila *p)
{
	if (p->n == TAM_FILA)
		return 1;
	else
		return 0;
}


int fila_vazia(Fila *p)
{
	if (p->n == 0)
		return 1;
	else
		return 0;
}

void fila_libera(Fila *p)
{
	free(p);
}
