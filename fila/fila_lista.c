/*
  Author: Adriano J. Holanda
  Version: 20160427
  Implementacao da estrutura de dados abstrata fila
  usando lista encadeada.
*/

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

struct lista {
	int chave;
	struct lista *prox;
};

typedef struct lista Lista;

struct fila {
	Lista *ini; /* inicio da fila */
	Lista *fim; /* fim da fila */
};

/* 
   A fila eh criada com p->topo apontando para NULL.
*/
Fila *fila_cria()
{
	Fila *p;

	p = malloc(sizeof(Fila));
	p->ini = NULL;
	p->fim = NULL;

	return p;
}

/*
  A fila estara vazia se p->topo apontar para NULL.
*/
int fila_vazia(Fila *p)
{
	if (p->ini == NULL)
		return 1;
	else
		return 0;
}

/* 
   Na implementacao usando lista nao colocamos limite para o tamanho
   da fila, por este motivo fila_cheia sempre retorna falso (0) para
   fila cheia.
*/
int fila_cheia(Fila *p)
{
	return 0;
}

void fila_insere(Fila *p, int k)
{
	Lista *l;

	l = malloc(sizeof(Lista));
	l->chave = k;
	
	if (p->fim != NULL)
		p->fim->prox = l;
	else
		p->ini = l;

	p->fim = l;
}

/*
  Retira o elemento para o qual p->topo aponta e retorna sua chave,
  liberando o espaco ocupado.
*/

int fila_retira(Fila *p)
{
	Lista *l;
	int k;
  
	if (fila_vazia(p)) {
		fprintf(stderr, "Fila esta vazia!\n");
		exit(-1);
	}

	l = p->ini;
	p->ini = p->ini->prox;

	k = l->chave;
	free(l);

	return k;
}

void fila_libera(Fila *p) 
{
	Lista *l, *m;

	/* libera espaco ocupado pela lista */
	l = p->ini;
	while (l != NULL) {
		m = l->prox;
		free(l);
		l = m;
	}
	/* libera espaco ocupado pela fila */
	free(p);
}
