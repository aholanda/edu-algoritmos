#ifndef _TREE_H_
#define _TREE_H_

/*
   Estrutura de dados para representacao da
   arvore binaria. Cada noh contem uma chave e
   um ponteiro para as subarvores a esquerda e
   a direita.
 */
struct arvbin {
	int chave;
	struct arvbin *esq;
	struct arvbin *dir; 
};

/* Protótipos */
/* chave=key=k */
extern struct arvbin *arvbin_busca(struct arvbin*, int chave);

#endif
