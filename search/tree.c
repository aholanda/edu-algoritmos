#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static void visita(struct arvbin *arv)
{
	printf("%d\n", arv->chave);
}

/* Percurso em pre-ordem */
void pre(struct arvbin *r)
{
	if (r == NULL)
		return;
	visita(r);
	pre(r->esq);
	pre(r->dir);
}

/* Percurso em ordem simetrica */
void simet(struct arvbin *r)
{
	if (r == NULL)
		return;
	simet(r->esq);
	visita(r);
	simet(r->dir);
}

/* Percurso em pos-ordem */
void pos(struct arvbin *r)
{
	if (r == NULL)
		return;
	pos(r->esq);
	pos(r->dir);
	visita(r);
}

struct arvbin *arvbin_nova(int chave)
{
	struct arvbin *nova = malloc(sizeof(struct arvbin));
	nova->chave = chave;
	nova->esq = NULL;
	nova->dir = NULL;
}

struct arvbin *arvbin_insere(struct arvbin *t, int chave)
{
	if (t->esq != NULL)
		t->esq = arvbin_nova(chave);
	else
		t->chave = chave;

	return t;
}

/* Busca a chave $k$ na arvore binaria com raiz em $t$ */
struct arvbin *arvbin_busca(struct arvbin *t, int k)
{
	if (t == NULL || t->chave == k)
		return t;
	if (t->chave > k)
		return arvbin_busca(t->esq, k);
	else
		return arvbin_busca(t->dir, k);
}
#include <stdio.h>
#include <stdlib.h>

struct arvbin {
	int chave;
	struct arvbin *dir;
	struct arvbin *esq;
};

struct pilha {
	struct arvbin *cel;
	struct pilha *prox;
};

static struct pilha topo;

static struct arvbin *arvbin_nova(int chave)
{
	struct arvbin *nova;
	nova = malloc(sizeof(struct arvbin));
	nova->chave = chave;
	return nova;
}

static struct arvbin *arvbin_insere(struct arvbin *t, int chave)
{
	if (t == NULL)
		t = malloc(sizeof(struct arvbin));
	t->chave = chave;
	return t;
}

static void empilha(struct arvbin *t)
{
	struct pilha *nova;
	nova = (struct pilha *)malloc(sizeof(struct pilha));
	nova->cel = t;
	nova->prox = topo.prox;
	topo.prox = nova;
}

static struct arvbin *desempilha()
{
	struct pilha *lixo;
	struct arvbin *t;
	lixo = topo.prox;
	topo.prox = topo.prox->prox;;
	t = lixo->cel;
	free(lixo);
	return t;
}

struct arvbin *expmat_parse(const char *exp)
{
	char ch;
	struct arvbin *p, *root;
	p = root = arvbin_nova(-1);
	for (ch = *exp; ch != '\0'; exp++, ch = *exp) {
		if (ch == '(') {
			p->esq = arvbin_insere(p->esq, (int)'\0');
			empilha(p);
			p = p->esq;
		} else if (ch == ')')
			if (p != root)
				p = desempilha();
			else if (ch == '+' || ch == '-' || ch == '*'
				 || ch == '/') {
				p->chave = (int)ch;
				p->dir = arvbin_insere(p->dir, (int)'\0');
				empilha(p);
				p = p->dir;
			} else if (isdigit(ch)) {
				p->chave = (int)ch;
				p = desempilha();
			} else {
				fprintf(stderr, "Que expressao ehn?\n");
			}
	}			/* rof ch */

	return root;
}

int main(int argc, char **argv)
{
	struct arvbin *root;
	char *exp = "(2+4)";

	root = expmat_parse(exp);

	return 0;
}
