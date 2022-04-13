#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Esta funcao recebe um numero x e um vetor v[0..N-1]
   com N>=0 e devolve k+1 comparacoes no intervalo 0..n-1 tal que v[k]==x.
   Se x nao pertence a v[0..N-1], devolve 0. */
int vetor_busca(int x, int v[], int N)
{
	int k = 0;
	/* invariante: x $\not\in$ v[k+1..N-1] */
	while (k < N && v[k] != x)
		k++;
	return k==N ? 0 : k+1;
}

/* Esta função recebe a chave procurada e um ponteiro 
   para um lista *lst, e retorna o ponteiro para o nó da chave,
   se a chave  for encontrada e NULL, cass contrário. */
struct lista *lista_busca(int x, struct lista *lst)
{
	struct lista *p;
	p = lst->prox;
	while (p != NULL && p->chave != x)
		p = p->prox;
	return p;
}

/* Insere x na lista entre a célula p e a 
   seguinte */
void lista_insere(int x, struct lista *p)
{
	struct lista *nova;
	nova = malloc(sizeof(struct lista));
	nova->chave = x;
	nova->prox = p->prox;
	p->prox = nova;
}

/* Função remove p->prox supondo que 
   p e p->prox não são nulos. */
void lista_remove(struct lista *p)
{
	struct lista *lixo;
	lixo = p->prox;
	p->prox = lixo->prox;
	free(lixo);
}
