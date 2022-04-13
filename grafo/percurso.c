#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* Percursos */

#define MAX_N_VERTS 0x100 /* numero maximo de vertices */
#define MAX_N_ARCOS 0x1000 /* numero maximo de arcos */

/* Prototipos */
struct grafo *grafo_criar();
struct vertice *grafo_buscar_vertice(struct grafo*g, int id);
struct vertice *grafo_adicionar_vertice(struct grafo*g, int id);
struct arco *grafo_adicionar_arco(struct grafo*g, int uid, int vid);
void grafo_reset(struct grafo*);
// Fila
void enfileirar(struct grafo*g, struct vertice*v);
struct vertice *desenfileirar(struct grafo*);
int fila_esta_vazia(struct grafo*);

struct vertice {
	int id; /* identificador */
	struct arco *arcos; /* lista de adjacencias */
	int visitado; /* booleano */
};

struct arco {
	struct vertice *ponta; /* vertice destino */
	struct arco *prox; /* proximo arco na lista de adjacencias */
};

struct grafo {
	struct vertice vertices[MAX_N_VERTS]; /* vetor de vertices */
	int n; /* numero de vertices */
	int m; /* numero de arcos */
	struct arco area[MAX_N_ARCOS];
	/* Campos auxiliares usado pela estrutura de dados pilha */
	struct vertice *fila[MAX_N_VERTS];
	int s; /* indice do inicio da fila */
	int t; /* indice do final, apos ultimo elemento */
};

/* Torna o campo visitado(v)=VERDADEIRO e imprime o identificador de v */
#define visitado(v) (v)->visitado
#define imprimir(v) printf("%d ",(v)->id)
#define FALSO 0
#define VERDADEIRO 1

/* somente o primeiro elemento sera usado */
static struct grafo __g[128];

static void visitar(struct vertice *v) {
	visitado(v) = VERDADEIRO;
	imprimir(v);
}

/* Percurso em profundidade */
void dfs_explorar(struct grafo *g, struct vertice *v) {
	struct vertice *w;
	struct arco *a;

        /* visita os vizinhos */
	for (a=v->arcos; a != NULL; a=a->prox) {
		w = a->ponta;

		if (visitado(w) != VERDADEIRO) {
			visitar(w);
			dfs_explorar(g, w);
		}
	}
}

void dfs(struct grafo *g, int s) {
	struct vertice *v;

	grafo_reset(g);

	v = grafo_buscar_vertice(g, s);
	visitar(v);

	dfs_explorar(g, v);
}

/* Percurso em largura */
void bfs_explorar(struct grafo *g, struct vertice *v) {
	struct vertice *w;
	struct arco *a;

	visitar(v);
	enfileirar(g, v);
	while (fila_esta_vazia(g) != VERDADEIRO) {
		v = desenfileirar(g);
		/* visita os vizinhos */
		for (a=v->arcos; a != NULL; a=a->prox) {
			w = a->ponta;

			if (visitado(w) != VERDADEIRO) {
				visitar(w);
				enfileirar(g, w);
			}
		}
	}
}

void bfs(struct grafo *g, int s) {
	struct vertice *v;

	grafo_reset(g);

	v = grafo_buscar_vertice(g, s);

	bfs_explorar(g, v);
}

int main (int argc, char**argv) {
	struct grafo *g;
	int s=0; /* inicio do percurso */

	g = grafo_criar();

	grafo_adicionar_arco(g, 0, 3);
	grafo_adicionar_arco(g, 0, 2);
	grafo_adicionar_arco(g, 0, 1);
	grafo_adicionar_arco(g, 3, 5);
	grafo_adicionar_arco(g, 1, 4);

	dfs(g, s);
	printf(" <- DFS\n");

	/* Atribui novamante valor inicial ao campo 'visitado'=FALSO
	   nos vertices.
	*/
	bfs(g, s);
	printf(" <- BFS\n");
}

/*********************************************************************
                              GRAFOS
                         FUNCOES AUXILIARES
********************************************************************/
struct grafo *grafo_criar() {
	__g[0].n = 0;
	__g[0].m = 0;

	__g[0].s = __g[0].t = 0;

	return &__g[0];
}

struct vertice *grafo_adicionar_vertice(struct grafo *g, int i) {
	struct vertice *v;

	assert(g != NULL);

	v = &g->vertices[g->n++];
	v->id = i;

	return v;
}

struct vertice *grafo_buscar_vertice(struct grafo *g, int i) {
	int k;
	struct vertice *v;

	for (k=0; k<g->n; k++) {
		v = &g->vertices[k];
		if (v->id == i)
			return v;
	}
	/* chegou aqui, nao encontrou o vertice, criar novo */
	v = grafo_adicionar_vertice(g, i);

	assert(v != NULL);

	return v;
}


struct arco *grafo_adicionar_arco(struct grafo *g, int uid, int vid) {
	struct vertice *u, *v;
	struct arco *a;

	u = grafo_buscar_vertice(g, uid);
	v = grafo_buscar_vertice(g, vid);

	a = &g->area[g->m++];
	a->ponta = v;
	a->prox = u->arcos;
	u->arcos = a;

	return a;
}

void grafo_reset(struct grafo *g) {
	int i;

	for (i=0; i<g->n; i++)
		g->vertices[i].visitado = FALSO;
}

void enfileirar(struct grafo *g, struct vertice *v) {
	g->fila[g->t++] = v;

	if (g->t == MAX_N_VERTS)
		g->t = 0;
}


struct vertice *desenfileirar(struct grafo *g) {
	struct vertice *v;

	v = g->fila[g->s++];

	if (g->s == MAX_N_VERTS) /* circunda a fila */
		g->s = 0;

	return v;
}

/* Checa se a fila esta vazia */
int fila_esta_vazia(struct grafo *g) {
	if (g->t == g->s)
		return VERDADEIRO;

	return FALSO;
}
