#include "grafo.h"

/* 
	Vetor representado um fila.
	inicio maior que fim significa fila vazia 
*/
static int fila[NV], ini=0, fim=-1; /* fila, inicio da fila, fim da fila */

/*
	GrafoCriar aloca espaco para um grafo com n vertices e do tipo DIRECIONADO 
	ou NAO_DIRECIONADO, inicializa os valores da estrutura Grafo e retorna o 
	ponteiro para a estrutura recem-criada.
*/
Grafo *GrafoCriar(int n, GrafoTipo tipo)
{
	Grafo *g;

	if (n>NV) {
		printf("Sem espaco para %d nos ou vertices.\n", n);
		exit(-1);
	}
	
	g = malloc(sizeof (Grafo));
	g->N = n;
	g->M = 0;
	g->Tipo = tipo;

	return g;
}

/* 
	GrafoLiberar libera o espaco alocado para os arcos percorrendo a lista 
	de adjascencias e depois libera o espaco ocupado pela estrutura Grafo.
*/
void GrafoLiberar(Grafo **grafo)
{
	int i;
	Arco *a, *b;
	Grafo *g = *grafo;
	
	for (i = 0; i < g->N; i++) {
		for (a = g->Adjs[i]; a; a = b) {
			b = a->Prox;
			
			if (a)
				free(a);
		}
	}
	
	if (*grafo)
		free(*grafo);
	*grafo = NULL;
}

/*
	GrafoInserir adiciona um arco tendo como ponto de partida a chave u e 
	destino (ponta) a chave v no Grafo apontado pelo ponteiro *grafo, tomando
	os seguintes cuidados:
	1. Se o arco ja existir, o peso atual do arco eh acrescido do peso fornecido
	  como argumento.
	2. Se arco nao existir, eh alocado espaco para um novo arco, que eh 
	  inicializado e colocado no inicio da lista de adjascencias da chave 
	  u. O numero de arcos M do grafo eh incrementado de 1 elemento.
	3. Se o grafo for NAO_DIRECIONADO, GrafoInserir eh invocada novamente 
	   para inserir o arco tendo como origem a chave v e destino (ponta) a
	   chave u. (v -> u + u -> v = u -- v)
*/
void GrafoInserir(Grafo *grafo, int u, int v, int peso)
{
	struct arco *a;

	for (a=grafo->Adjs[u]; a; a=a->Prox)
		if (a->Ponta==v)
			a->Peso += peso ;

	/* 1. Cria um novo arco */
	if (a==NULL) {
		a = malloc(sizeof (struct arco));
		a->Ponta = v;
		a->Prox = NULL;
		a->Peso = peso;
		grafo->M++;
	}
	/* 2. Posiciona o novo arco */
	a->Prox = grafo->Adjs[u];
	grafo->Adjs[u] = a;

	/* 3. grafos nao direcionados */
	if (grafo->Tipo == NAO_DIRECIONADO)
		GrafoInserir(grafo, v, u, peso);
}

/* O procedimento visitar() fornecido simplesmente imprime o valor da chave k */
static void _visitar(int k)
{
	printf("%d ", k);
}

/* 
	Percurso em profundidade
	DFS: Depth-First Search
*/
void DFS(Grafo *grafo, int v, void visitar(int v))
{
	static int visitado[NV]; /* marca os nos visitados */
	struct arco *a;
	
	if (v<0 || v>=grafo->N)
		return;

	if (!visitar)
		visitar = _visitar;
		
	visitado[v] = 1; /* marca v */
	visitar(v);
	
	for (a=grafo->Adjs[v]; a; a=a->Prox) {
		int w = a->Ponta;
		if (!visitado[w])
			DFS(grafo, w, visitar);
	}
}

/* Insere a chave k no final da fila representada como vetor circular */
static void enfileirar(int k)
{
	fim++;
	if ((fim-ini) >= NV) {
		printf("overflow da fila\n");
		exit(-1);
	}
	fila[fim % NV] = k;
}

/* Remove a chave k do inicio da fila */
static int desenfileirar()
{
	int k;
	
	if (ini>fim)
		return -1; /* indica fila vazia */
		
	k = fila[ini % NV];
	ini++;

	return k;
}

/*
	Percurso em largura
	BFS: Breadth-First Search
*/

void BFS(Grafo *grafo, int v, void visitar(int v))
{
	static int visitado[NV]; /* marca os nos visitados */
	int k; /* chave */
	struct arco *a;
	
	if (v<0 || v>=grafo->N)
		return;

	if (!visitar)
		visitar = _visitar;

	enfileirar(v);
	visitado[v] = 1; /* marca v */
	visitar(v);

	while ((k=desenfileirar()) >= 0) {
		for (a=grafo->Adjs[k]; a; a=a->Prox) {
			int w = a->Ponta;
			if (!visitado[w]) {
				enfileirar(w);
				visitado[w] = 1;
				visitar(w);
			}
		}
	}
}

int main(int argc, char **argv)
{
	Grafo *g;

	g = GrafoCriar(8, DIRECIONADO);
	GrafoInserir(g, 0, 2, 1);
	GrafoInserir(g, 0, 1, 1);
	GrafoInserir(g, 1, 4, 1);
	GrafoInserir(g, 1, 3, 1);
	GrafoInserir(g, 2, 6, 1);
	GrafoInserir(g, 2, 5, 1);
	GrafoInserir(g, 4, 7, 1);

	printf("percurso em profundidade: ");
	DFS(g, 0, NULL);
	printf("\n");

	printf("percurso em largura: ");
	BFS(g, 0, NULL);
	printf("\n");

	GrafoLiberar(&g);
	
	return 0;
}
	
