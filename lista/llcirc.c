#include <stdlib.h>

/* A função recebe a chave a ser procurada e a cabeça da lista
   encadeada circular ordenada. Se a busca for realizada com sucesso,
   o ponteiro para a célula contendo a chave é retornado, senão é
   retornado o valor nulo */
struct list *llcirc_busca(int x, struct list *cabeca)
{
	struct list *ant, *p;	/* ponteiros anterior e atual */
	ant = cabeca;
	cabeca->chave = x;
	p = cabeca->prox;
	while (p->chave < x) {
		ant = p;
		p = p->prox;
	}
	if (p != cabeca && p->chave == x)
		return p;
	else
		return NULL;
}

/* Insere a chave x na posição correta da lista que 
   começa em cabeça */
void llcirc_insere(int x, struct list *cabeca)
{
	struct list *ant, *p, *novo;	/* ponteiros anterior, atual e novo */
	ant = cabeca;
	cabeca->chave = x;
	p = cabeca->prox;
	while (p->chave < x) {
		ant = p;
		p = p->prox;
	}
	novo = malloc(sizeof(struct list));
	novo->prox = p;
	ant->prox = novo;
}

/* Remove a célula contendo a chave x da lista que 
   começa em cabeça */
void llcirc_remove(int x, struct list *cabeca)
{
	struct list *ant, *p, *lixo;	/* ponteiros anterior, atual e lixo */
	ant = cabeca;
	cabeca->chave = x;
	p = cabeca->prox;
	while (p->chave < x) {
		ant = p;
		p = p->prox;
	}
	if (p != cabeca && p->chave == x) {
		lixo = p;
		ant->prox = p->prox;
		free(lixo);
	}
}
