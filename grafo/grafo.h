#include <stdio.h>
#include <stdlib.h>

#define NV 128 /* numero de vertices ou nos */

typedef enum {DIRECIONADO, NAO_DIRECIONADO} GrafoTipo;

/*
  Arcos de um grafo são pares ordenados de vertices adjascentes.
 */

typedef struct arco {
	int Ponta; /* indice no vetor Adjs[] da estrutura Grafo */
	struct arco *Prox;
	int Peso;
} Arco;
	
/*
  Cada vertice de um grafo eh representado por um valor inteiro, 
  que corresponde ao indice do vetor de adjascencias Adjs[]. 
  Cada elemento do vetor Adjs[] aponta para o primeiro elemento 
  da lista ligada, que contem os vizinhos do elemento.
 */

typedef struct grafo {
	Arco *Adjs[NV]; /* lista de adjascencias */
	int N; /* no. de nos */
	int M; /* no. de arcos */
	GrafoTipo Tipo;
} Grafo;

extern Grafo *GrafoCriar(int n, GrafoTipo tipo);
extern void GrafoInserir(Grafo *grafo, int u, int v, int peso);
extern void GrafoLiberar(Grafo **grafo);
extern void DFS(Grafo *grafo, int v, void visitar(int v));
extern void BFS(Grafo *grafo, int v, void visitar(int v));
