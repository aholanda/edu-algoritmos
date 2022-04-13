#include <stdio.h>
#include <stdlib.h>
#include "instruct.h"

typedef struct list Fila;

static Fila inicio;		/* inicio da fila */
static Fila fim;		/* fim da fila */

#define VAZIA() (inicio.prox==NULL)

void lfila_insere(int k)
{
	Fila *ent;		/* elemento a entrar na fila */

	ent = (Fila *) malloc(sizeof(Fila));
	ent->chave = k;
	ent->prox = NULL;

	if (VAZIA())
		inicio.prox = fim.prox = ent;
	else
		fim.prox = ent;
}

int lfila_remove()
{
	int k;
	Fila *prox;

	if (VAZIA()) {
		printf("Fila vazia!\n");
		exit(-1);
	}

	prox = inicio.prox->prox;
	k = prox->chave;
	inicio.prox = prox->prox;
	free(prox);

	return k;
}
