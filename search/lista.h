#ifndef LISTA_H
#define LISTA_H

struct lista {
	int chave;
	struct lista *prox; /* link para o restante da lista */
};

struct dlista {
	int chave;
	struct dlista *dir; /* link para o no da direita */
	struct dlista *esq; /* link para o no da esquerda */
};


/* PROTOTYPES */

extern int vetor_busca(int x, int v[], int N);

/************************ Lista ************************/

extern struct lista *lista_busca(int x, struct lista *lst);
extern void lista_remove(struct lista*p);
extern void lista_insere(int y, struct lista *p);
extern void lista_busca_remove(int x, struct lista *lst);
extern void busca_insere(int x, int y, struct lista *lst);

/************************ Pilha ************************/

typedef struct lista Pilha;

extern void pilha_empilha(int y, Pilha *p);
extern void pilha_desempilha(Pilha *lst);

#endif
