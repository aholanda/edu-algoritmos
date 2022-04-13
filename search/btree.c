/* B-Tree */

#include <stdio.h>

#define M 4 /* B-Tree order, change order here */

struct paginaB {
	int nk;
	int k[M-1];
	struct paginaB *p[M];
	void *data[M-1];
};

void *buscaB(struct paginaB *raiz, int x)
{
	struct paginaB *pg = raiz;
	int i = 0;

	if (pg == NULL)
		return NULL;

	while (i <= pg->nk && x > pg->k[i])
		i++;

	if (i <= pg->nk && x == pg->k[i])
		return pg->data[i];

	return buscaB(pg->p[i], x);
}
