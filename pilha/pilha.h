typedef struct pilha Pilha;

Pilha *pilha_cria(); /* cria uma pilha vazia */
void pilha_push(Pilha *p, int k); /* insere k no topo da pilha */
int pilha_pop(Pilha *p); /* remove elemento do topo da pilha p */
int pilha_cheia(Pilha *p); /* verifica se a pilha p esta cheia */
int pilha_vazia(Pilha *p); /* verifica se a pilha p esta vazia */
void pilha_libera(Pilha *p); /* libera a memoria ocupada pela pilha p */
