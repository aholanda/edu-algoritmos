#ifndef EDU_ALG_FILA_H
#define EDU_ALG_FILA_H

typedef struct fila Fila;

Fila *fila_cria(); /* cria uma fila vazia */
void fila_insere(Fila *p, int k); /* insere k no fim da fila */
int fila_retira(Fila *p); /* remove elemento do inicio da fila p */
int fila_cheia(Fila *p); /* verifica se a fila p esta cheia */
int fila_vazia(Fila *p); /* verifica se a fila p esta vazia */
void fila_libera(Fila *p); /* libera a memoria ocupada pela fila p */

#endif
