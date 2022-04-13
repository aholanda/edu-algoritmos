#include <stdio.h>
#include <stdlib.h>

/*
  Estrutura de dados lista encadeada.
*/
struct lista {
	int chave;          /* chave para identificacao do elemento na lista */
	struct lista *prox; /* ponteiro para o proximo elemento da lista */
};

/*
  Uma lista e inicializada vazia, ou seja, apontando para NULL.
*/
struct lista *lista_cria() 
{
	return NULL;
}

/*
  Insere um novo elemento do tipo struct lista contendo a chave k
  no inicio da lista passada como parametro.
*/
struct lista *lista_insere(struct lista *lst, int k)
{
	struct lista *nova = malloc(sizeof(struct lista));
	nova->chave = k;
	nova->prox = lst;
	
	return nova;
}

/*
  Percorre a lista e imprime a chave.
*/
void lista_imprime(struct lista *lst)
{
	struct lista *p;

	for (p = lst; p != NULL; p = p->prox)
		printf("chave=%d\n", p->chave);
}

/*
  Busca a chave k na lista passada como parametro.
*/
struct lista *lista_busca(struct lista *lst, int k)
{
	struct lista *p;

	for (p = lst; p != NULL; p = p->prox)
		if (p->chave == k)
			return p;

	return NULL;
}

/*
  Percorre a lista e libera a memoria reservada 
  para cada elemento da lista.
*/
void lista_libera(struct lista *lst)
{
	struct lista *t, *p = lst;

	while (p != NULL) {
		t = p->prox;
		free(p);
		p = t;
	}
}

/*
  Teste simples da lista encadeada.
*/
int main()
{
	struct lista *lst = lista_cria();

	lst = lista_insere(lst, 25);
	lst = lista_insere(lst, 11);
	lst = lista_insere(lst, 121);
	lst = lista_insere(lst, 33);

	lista_imprime(lst);

	lista_libera(lst);
	
	return 0;
}
