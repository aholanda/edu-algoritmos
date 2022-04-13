#include <assert.h>
#include <limits.h> /* MAX_INT */
#include <stdio.h>

#define INFINITO INT_MAX

/*
  Representacao e algoritmos de grafos utilizando matriz
  de adjacências.
*/
#define MAX_NVERTICES 8 /* capacidade de vértices */

struct grafo {
	int V; /* número de vértices utilizados */
	int E; /* número de arcos ou arestas utilizadas */
	int adj[MAX_NVERTICES][MAX_NVERTICES];
	int precede[MAX_NVERTICES]; /* Guarda o indice do vertice que precede o atual. */
	int dist[MAX_NVERTICES]; /* Guarda a distancia do vertice a um ponto de origem qualquer */
};

/* Variável global usada para evitar alocação dinâmica. */
struct grafo g;

/* Inicializa a matriz de adjacências e os campos da estrutura do grafo */
void grafo_inicializar(int n, int m) {
	int i, j;

	g.V = n;
	g.E = m;

	for (i=0; i<MAX_NVERTICES; i++)
		for (j=0; j<MAX_NVERTICES; j++)
			if (i==j)
				g.adj[i][j] = 0;
			else
				g.adj[i][j] = INFINITO;
}

/*
  Adiciona o arco u->v no grafo g com o peso weight.
*/
void grafo_adicionar_arco(int u, int v, int peso) {
	assert(u>=0 && u<g.V);
	assert(v>=0 && v<g.V);

	g.adj[u][v] = peso;
}

/* Imprime a tabela com os valores intermediarios do algoritmo de Dijkstra */
void imprimir_tabela(int k) {
	int i;
	printf("\nvert:");
	for (i=0; i<g.V; i++)
		printf("\t%d", i);
	printf("\ndist:");
	for (i=0; i<g.V; i++)
		printf("\t%d", g.dist[i]);
	printf("\nprec:");
	for (i=0; i<g.V; i++)
		printf("\t%d", g.precede[i]);
	printf("\nk=%d\n\n", k);
}

/*
  Imprime a saida do algoritmo de Dijkstra.
*/
void dijkstra_imprime(int s, int t) {
	int i, v;

	v = t;
	while (v != s) {
		printf("%d -> %d\n", g.precede[v], v);
		v = g.precede[v];
	}
}

/*
  Algoritmo de Dijkstra implementado usando matriz de adjacências.
  Calcula as menores distâncias no caminho de s para t.
  Baseado no livro do Tenenbaum.
*/
#define TRUE 1
#define FALSE 0
void dijkstra(int s, int t) {
	int visitado[MAX_NVERTICES]; /* Guarda a visita a cada vertice */
	int menor_dist, nova_dist; /* menor distancia e nova distancia */
	int dist_v; /* distancia atual do vertice v */
	int v, i, k;

	/* Inicializacao */
	for (i=0; i<g.V; i++) {
		visitado[i] = FALSE;
		g.dist[i] = INFINITO;
	}
	visitado[s] = TRUE;
	g.dist[s] = 0;
	v = s;
	while (v != t) {
		menor_dist = INFINITO;
		dist_v = g.dist[v];
		for (i=0; i<g.V; i++) {
			if (visitado[i] == FALSE) {
				nova_dist = dist_v + g.adj[v][i];
				/* A distancia de s a i atraves de current eh
				   menor que dist[i] */
				if (nova_dist < g.dist[i]) {
					g.dist[i] = nova_dist;
					g.precede[i] = v;
				}
				if (g.dist[i] < menor_dist) {
					menor_dist = g.dist[i];
					k = i;
				}
			}
		}
		imprimir_tabela(k);
		v = k;
		visitado[v] = TRUE;
	}
}


int main(int argc, char **argv) {
	int s=0, t=3; /* origem e destino */
	int n=5, m=9; /* numero de vertices e arcos */
	grafo_inicializar(n, m);

	/* conjunto de dados 1 */
	grafo_adicionar_arco(0, 1, 4);
	grafo_adicionar_arco(0, 2, 2);
	grafo_adicionar_arco(1, 2, 3);
	grafo_adicionar_arco(1, 3, 2);
	grafo_adicionar_arco(1, 4, 3);
	grafo_adicionar_arco(2, 1, 1);
	grafo_adicionar_arco(2, 3, 4);
	grafo_adicionar_arco(2, 4, 5);
	grafo_adicionar_arco(4, 3, 1);

	dijkstra(s, t);

	dijkstra_imprime(s,t);
}
