#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
   Author: Adriano J. Holanda
   Versao: 20190912
   Dominio Publico
 */

/*********************************************************************

                    GRAFO USANDO LISTA DE ADJACENCIAS

*********************************************************************/

#define MAX_N_VERTICES 0x100
#define MAX_N_ARCOS 0x1000

struct vertice {
	long id;
	struct arco *arcos; /* lista de arcos para os vertices adjacentes */
        /* aponta para o vertice que o precede em um caminhamento */
	struct vertice *precede;
	long dist; /* distancia ate o ponto de origem do caminhamento */

	/* Usado na implementacao fila de prioridades */
	struct vertice *esq; /* aponta para o vertice a esquerda na fila */
	struct vertice *dir; /* aponta para o vertice a direita na fila */
};

struct arco {
	struct vertice *ponta; /* ponta do arco */
	long comp; /* comprimento do arco ou aresta */
	struct arco *prox; /* proximo elemento da lista */
};

struct grafo {
	struct vertice *vertices; /* vetor de vertices */
	long n; /* número de vértices */
	long m; /* número de arcos ou arestas */
	struct arco *area; /* area de memoria para todos os arcos */
};

/* Alguns prototipos e variaveis de funcoes auxiliares */
void dijkstra_escrever(struct grafo*, long);
void grafo_escrever(struct grafo *g);
/* Prototipos para a fila de prioridades */
static struct vertice cabeca[128]; /* somente o 1o. elemento sera usado */
static void fila_criar();
static void fila_inserir(struct vertice *v, long d);
static void fila_diminuir_chave(struct vertice *v, long d);
static struct vertice *fila_remover_min();
static int fila_esta_vazia();

struct grafo *grafo_criar() {
	struct grafo *g;

	g = (struct grafo*)malloc(sizeof(struct grafo));
	g->vertices = (struct vertice*)calloc(MAX_N_VERTICES,
					      sizeof(struct vertice));
	g->area = (struct arco*)calloc(MAX_N_ARCOS,
				       sizeof(struct arco));
	g->n = 0;
	g->m = 0;

	return g;
}

/* Retorna o ponteiro para o vertice com identificacao id, se este
   não existir, um novo vertice eh criado. */
struct vertice *grafo_buscar_vertice(struct grafo *g, long id) {
	long i;
	assert(g && (g->n+1 < MAX_N_VERTICES));

	for (i=0; i<g->n; i++)
		if (g->vertices[i].id == id)
			return &(g->vertices[i]);

	g->n++;
	g->vertices[g->n-1].id = id;
	g->vertices[g->n-1].arcos = NULL;

	return &(g->vertices[g->n-1]);
}

/* Adiciona arco onde o vertice com id uid como origem e vid como
 ponta e comprimento eh comp. Esta funcao busca os ponteiros para os
 vertices com os ids forncecidos e atribui os campos da estrutura
 arco com estes valores. */
struct arco *grafo_adicionar_arco(struct grafo *g,
				  long uid, long vid,
				  long comp) {
	struct vertice *u, *v;
	struct arco *a;

	assert(g);

	u = grafo_buscar_vertice(g, uid);
	v = grafo_buscar_vertice(g, vid);

	/* Apenas adiciona o arco, nao leva em conta arcos repetidos */
	a = &g->area[g->m++];
	a->ponta = v;
	a->comp = comp;
	a->prox = u->arcos;
	u->arcos = a;

	return a;
}

/* Libera memoria alocada para o grafo */
void grafo_liberar(struct grafo *g) {
	free(g->area);
	free(g->vertices);
	free(g);
}

/**********************************************************************

     PREENCHA A FUNCAO DIJKSTRA COM AS INSTRUCOES  QUE FALTAM


*********************************************************************/

/********************************************************************

  Algoritmo de DIJKSTRA implementado usando lista de adjacencias e
  fila de prioridades.

********************************************************************/
#define INFINITO INT_MAX
#define para_cada_vertice(g, i)  for((i)=0;(i)<(g)->n;(i)++)
/* pega o vertice pelo indice no vetor g->vertices */
#define grafo_pega_vertice_pelo_indice(g, i) &(g)->vertices[(i)]
#define para_cada_arco(v, a) for((a)=(v)->arcos; (a); (a)=(a)->prox)
#define set_precede(v, u)  (v)->precede=(u)

void dijkstra(struct grafo *g, long s) {
	struct vertice *u, *v;
	struct arco *a;
	long i, l;

#warning 0. Inicializar a fila de prioridades

	para_cada_vertice(g, i) {
		v = grafo_pega_vertice_pelo_indice(g, i);
#warning 1. Inserir o vertice v na fila de prioridades com valor INFINITO

#warning 2. Atribuir o valor nulo ao precede de cada vertice

	}

	u = grafo_buscar_vertice(g, s);
#warning 3. Diminuir valor da chave da origem para o valor 0

	while (!fila_esta_vazia()) {
#warning 4. Remover vertice com menor chave da fila

		para_cada_arco(u, a) {
			v = a->ponta;
			l = a->comp;
			if (v->dist > u->dist + l) {
#warning 5. Marca o caminho  usando set_precede()

#warning 6. Diminui o valor da chave do vertice v para u->dist + l

			}
		}
	}
}

int main(int argc, char **argv) {
	struct grafo *g;
	long s = 0; /* nao esqueca de alterar o ponto de origem */
    long t;

	g = grafo_criar();

#warning 7. Adicionar os arcos
	/* Exemplo */
	(void)grafo_adicionar_arco(g, 0, 1, 4);

	grafo_escrever(g);

	dijkstra(g, s);

	dijkstra_escrever(g, t);

	grafo_liberar(g);
}

/*********************************************************************

                     FUNCOES AUXILIARES

*********************************************************************/
/* Escreve o grafo g em um arquivo usando o formato graphviz dot */
void grafo_escrever(struct grafo *g) {
	long i;
	struct vertice *u, *v;
	struct arco *a;
	FILE *f;

	f = fopen("grafo.dot", "w");

/* Escreve a saida no formato graphviz dot */
	fprintf(f, "digraph {\n");
	for (i=0; i<g->n; i++) {
		u = &g->vertices[i];
		for (a=u->arcos; a; a=a->prox) {
			v = a->ponta;
			fprintf(f, "\t%ld -> %ld [weight=\"%f\"];\n",
				u->id, v->id, (float)a->comp);
		}
	}
	fprintf(f, "}\n");
	fclose(f);
	printf("Execute: dot grafo.dot -Tpng >grafo.png\n");
	printf("Abra: eog grafo.png &\n\n");
}

/* Escreve o grafo g com os caminho mínimo a partir de t em um arquivo
 * usando o formato graphviz dot */
void dijkstra_escrever(struct grafo *g, long t) {
	struct vertice *u, *v;
	struct arco *a;
	FILE *f;

	f = fopen("dijkstra.dot", "w");
	fprintf(f, "digraph dijkstra {\n");

	v = grafo_buscar_vertice(g, t);

	u = v->precede;
	while (u!=NULL) {
		for(a=u->arcos; a->ponta!=v; a=a->prox) ;

		fprintf(f, "\t%ld -> %ld [weight=\"%f\"];\n", u->id, v->id, (float)a->comp);
		v = u;
		u = v->precede;
	}
	fprintf(f, "}\n");
	fclose(f);
	printf("Execute: dot dijkstra.dot -Tpng >dijkstra.png\n");
	printf("Abra: eog dijkstra.png &\n");
}

/*********************************************************************

                          FILA DE PRIORIDADES

              implementada usando lista encadeada dupla

*********************************************************************/

/*
  Para evitar as complicações da implementação de uma heap, vamos
  usar a estrutura de lista encadeada dupla, com as distancias em
  ordem crescente e rearranjando sempre que houver alteração da chave de
  elementos da fila. Nao eh a estrutura mais eficiente, mas para
  valores nao tao grandes de N, quebra bem o galho.
*/

static void fila_criar() {
	cabeca->esq = cabeca->dir = cabeca;
	cabeca->dist = -1; /* uma distancia que seja menor que qualquer outra distancia */
}

/*
  Atribui o novo valor de distancia ao vertice v a insere
  o insere na posicao que mantenha a invariante de ordem
  decrescente de distancia dos vertices ate o ponto s.
*/
static void fila_inserir(struct vertice *v, long d) {
	struct vertice *t = cabeca->esq;

	v->dist = d;
	while (d < t->dist)
		t = t->esq;

	v->esq = t;
	(v->dir = t->dir)->esq = v;
	t->dir = v;
}

/*
  Atualiza a distancia de v e o reposiciona na fila de prioridades.
*/
static void fila_diminuir_chave(struct vertice *v, long d) {
	struct vertice *t = v->esq;

	(t->dir = v->dir)->esq = v->esq; /* remove v */

	v->dist = d;
	while (d < t->dist)
		t = t->esq;
	v->esq = t;
	(v->dir = t->dir)->esq = v;
	t->dir = v;
}

static struct vertice *fila_remover_min() {
	struct vertice *t;

	t = cabeca->dir;
	if (t==cabeca)
		return NULL;
	(cabeca->dir = t->dir)->esq = cabeca;

	return t;
}

static int fila_esta_vazia() {
	return cabeca->dir==cabeca;
}
