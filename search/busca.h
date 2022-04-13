#ifndef _SEARCH_H_
#define _SEARCH_H_

typedef union _info {
	int I; /* inteiro */
	long L; /* inteiro longo */
	float F; /* ponto flutuante de precisao unica */
	double D; /* ponto flutuante de dupla precisao */
	char *S; /* string */
	char *P; /* ponteiro */
} Info; /* Informacao */

typedef struct _registro {
	long chave; /* identificacao do registro */
	Info info; /* informacao associada a chave */
} Registro;

extern int BuscaSequencialS(int k, int N, int v[]);/* simples */
extern int BuscaSequencialQ(int k, int N, int v[]);/* rápida */
extern int BuscaSequencialT(int k, int N, int v[]);/* ordenada */

struct cel {
    int chave;
    struct cel *prox;
};

extern struct cel *BuscaSequencialL(int k, struct cel *l);

#endif
