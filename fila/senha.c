/** 
    Este programa simula a distribuição de senhas de 
    atendimento a clientes. São 3 opcoes possiveis:
    1. Atribuir senha ao cliente que chegou
    2. Chamar o proximo cliente a ser atendido
    3. Sair do programa
    Na opcao 1, o proximo numero do contador eh adicionado 
    na fila usando a funcao fila_insere().
    Na opcao 2, a senha do cliente a ser atendido eh 
    retirada da fila usando a funcao fila_retira().
    
    Neste programa vamos supor que o atendimento ocorra 
    em um ritmo satisfatorio, e portanto, não ha a 
    possibilidade de repeticao de numeros na fila.
*/

#include<stdio.h>
#include <stdlib.h>

/* o arquivo de cabecalho fila.h foi inserido aqui */

typedef struct fila Fila;

/* prototipos */
Fila *fila_cria(); /* cria uma fila vazia */
void fila_insere(Fila *p, int k); /* insere k no fim da fila */
int fila_retira(Fila *p); /* remove elemento do inicio da fila p */
int fila_cheia(Fila *p); /* verifica se a fila p esta cheia */
int fila_vazia(Fila *p); /* verifica se a fila p esta vazia */
void fila_libera(Fila *p); /* libera a memoria ocupada pela fila p */

/* o arquivo fila_vetor.c foi inserido aqui */

#define TAM_FILA 100 /* tamanho da fila */

struct fila {
	int v[TAM_FILA];
	int ini; /* inicio da fila */
	int n;
};

Fila *fila_cria()
{
	Fila *p;

	p = malloc(sizeof(Fila));
	p->ini = 0;
	p->n = 0;

	return p;
}

void fila_insere(Fila *p, int k)
{
	int fim;

	if (fila_cheia(p)) {
		printf("Capacidade da fila excedida!\n");
		exit(-1);
	}
	
	fim = (p->ini + p->n) % TAM_FILA;
	p->v[fim] = k;
	p->n++;
}

int fila_retira(Fila *p)
{
	int k;
	
	if (fila_vazia(p)) {
		printf("Fila vazia!\n");
		exit(-1);
	}
	k = p->v[p->ini];
	p->ini = (p->ini + 1) % TAM_FILA;
	p->n--;

	return k;
}

int fila_cheia(Fila *p)
{
	if (p->n == TAM_FILA)
		return 1;
	else
		return 0;
}


int fila_vazia(Fila *p)
{
	if (p->n == 0)
		return 1;
	else
		return 0;
}

void fila_libera(Fila *p)
{
	free(p);
}


int main() {
	int cont=0, opcao, senha;
	Fila *p;
	
	p = fila_cria();	

	while (1) {	
		printf("1. Atribuir senha ao cliente!\n");
		printf("2. Atender o proximo da fila!\n");
		printf("3. Sair!\n");
		printf("Escolha uma das opcoes: ");
		scanf("%d", &opcao);
	
		if (opcao == 1) {
			/* cont retorna a 1 apos a senha 100 */
			cont = (cont % TAM_FILA) + 1;
			fila_insere(p, cont);
			printf("\n\tSenha %d atribuida.\n\n", cont);
		} else if (opcao == 2) {
			if (fila_vazia(p)) {
				printf("\n\tNão ha clientes na fila. Espere alguem chegar!\n\n");
				continue;
			}			
			senha = fila_retira(p);
			printf("\n\tChamando %d...\n\n", senha);
		} else if (opcao == 3) {
			break;
		} else {
			printf("\n\tErro: escolha incorreta, tente de novo!\n\n");
			continue;
		}
	}	
	fila_libera(p);

	return 0;
}
