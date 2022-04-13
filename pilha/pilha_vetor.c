/*
  versao: 20160427
  Implementacao do tipo abstrato de dados pilha
  usando alocacao sequencial (vetor).
*/

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

#define TAM_PILHA 32 /* tamanho da pilha */

struct pilha {
	int vet[TAM_PILHA];
	int topo;
};

Pilha *pilha_cria()
{
	Pilha *p;

	p = malloc(sizeof(Pilha));
	p->topo = -1; /* -1 indica pilha vazia */

	return p;
}

void pilha_push(Pilha *p, int k)
{
	if (pilha_cheia(p)) {
		printf("Capacidade da pilha excedida!\n");
		exit(-1);
	}
	p->topo++;
	p->vet[p->topo] = k;
}


int pilha_pop(Pilha *p)
{
	int k;
	
	if (pilha_vazia(p)) {
		printf("Pilha vazia!\n");
		exit(-1);
	}
	k = p->vet[p->topo];
	p->topo--;

	return k;
}

int pilha_cheia(Pilha *p)
{
	if (p->topo == TAM_PILHA-1)
		return 1;
	else
		return 0;
}


int pilha_vazia(Pilha *p)
{
	if (p->topo == -1)
		return 1;
	else
		return 0;
}

void pilha_libera(Pilha *p)
{
	free(p);
}
