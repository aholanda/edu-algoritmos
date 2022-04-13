/*
  Author: Adriano J. Holanda
  Version: 20160406
  Implementacao da estrutura de dados abstrata pilha
  usando lista encadeada.
*/

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

struct lista {
	int chave;
	struct lista *prox;
};

typedef struct lista Lista;

struct pilha {
  Lista *topo;
};

/* 
   A pilha eh criada com p->topo apontando para NULL.
*/
Pilha *pilha_cria()
{
	Pilha *p;

	p = malloc(sizeof(Pilha));
	p->topo = NULL;

	return p;
}

/*
  A pilha estara vazia se p->topo apontar para NULL.
*/
int pilha_vazia(Pilha *p)
{
	if (p->topo == NULL)
		return 1;
	else
		return 0;
}

/* 
   Na implementacao usando lista nao colocamos limite para o tamanho
   da pilha, por este motivo pilha_cheia sempre retorna falso (0) para
   pilha cheia.
*/
int pilha_cheia(Pilha *p)
{
	return 0;
}

void pilha_push(Pilha *p, int k)
{
	Lista *l;

	l = malloc(sizeof(Lista));
	l->chave = k;
	l->prox = p->topo;

	p->topo = l;
}

/*
  Retira o elemento para o qual p->topo aponta e retorna sua chave,
  liberando o espaco ocupado.
*/

int pilha_pop(Pilha *p)
{
	Lista *t;
	int k;
  
	if (pilha_vazia(p)) {
		fprintf(stderr, "Pilha esta vazia!\n");
		exit(-1);
	}

	t = p->topo;
	p->topo = p->topo->prox;

	k = t->chave;
	free(t);

	return k;
}

void pilha_libera(Pilha *p) 
{
	Lista *l, *m;

	/* libera espaco ocupado pela lista */
	l = p->topo;
	while (l != NULL) {
		m = l->prox;
		free(l);
		l = m;
	}
	/* libera espaco ocupado pela pilha */
	free(p);
}
