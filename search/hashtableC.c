#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtableC.h"

struct hashtableC *hashtableC_new() {
	struct hashtableC *table;

	table = (struct hashtableC*)calloc(1, sizeof(struct hashtableC));
	assert(table);

	table->m = HASHTABLEC_M;
	table->n = 0;

	table->buckets = (struct hashtableC_entry**)
		calloc(table->m, sizeof(struct hashtableC_entry*));
	assert(table);
	
	return table;
}

struct hashtableC_entry *hashtableC_get(struct hashtableC *table,
					const char*key) {
	long h; /* indice de dispersao/espalhamento (hash) */
	long i, len; /* contador e tamanho da string  */
	char *k; /* chave atual */
	struct hashtableC_entry *p; /* ponteiro para entrada na tabela */

	assert(key);

        len = strlen(key);

	/* calcula o indice de dispersao (espalhamento) */
	for (i=0; i<strlen(key); i++)
		h += key[i];
	h = h % table->m;

	for (p=table->buckets[h]; p; p=p->rest) {
		k = p->key;
                
                if (strncmp(k, key, len+1)==0)
                   return p;		

	}
	p = malloc(sizeof(struct hashtableC_entry) + len + 1);
	p->key = (char *)(p + 1);
	if (len>0)
		memcpy(p->key, key, len);
	p->key[len] = '\0';
	p->rest = table->buckets[h];
	table->buckets[h] = p;

	return p;
}

void hashtableC_free(struct hashtableC *table) {
	long i;
	struct hashtableC_entry *p, *q; /* ponteiros para entradas da tabela */
	
	if (table==NULL)
		return;

	for (i=0; i<table->m; i++)
		for(p=table->buckets[i]; p; p = q) {
			q = p->rest;
			if (p)
				free(p);
		}

	free(table->buckets);
	free(table);
}

void hashtableC_visit(struct hashtableC *tab, 
     void visit(struct hashtableC_entry *ent)) {
     long i;
     struct hashtableC_entry *p;

     assert(tab);

     for (i=0; i<tab->m; i++) {
         for (p = tab->buckets[i]; p; p = p->rest) {
             if (p) {
                visit(p);
             }
         }
     }
}

/* Hashtable application. Word frequency. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtableC.h"

#define BUFLEN 256
#define SEP " '[]()-;*:,.!?\"\t\r\n" /* separador das palavras */
#define freq value.I

static void imprime_freq(struct hashtableC_entry *ent) {
        assert(ent);
       
        printf("<%s, %ld>\n", ent->key, ent->freq);
 }

int main(int argc, char**argv) {
    char *fn; /* nome do arquivo de entrada */    
    FILE*fp; /* ponteiro para o arquivo */
    char linha[BUFLEN]; /* linha do arquivo */
    char *w; /* aponta palavra */
    struct hashtableC *tab; /* tabela de dispersao */
    struct hashtableC_entry *ent; /* entrada na tabela */

    if (argc==2) {
       fn = argv[1];    
       assert(fn);
    }
    
    fp = fopen(fn, "r");
    if (!fp) {
       fprintf(stderr, "error: fopen(%s)\n", fn);
       exit(-1);
    }

    tab = hashtableC_new();

    while(fgets(linha, BUFLEN, fp)!=NULL) {
    
       w = strtok(linha, SEP);
       while (w != NULL) {
           ent = hashtableC_get(tab, w);
           ent->freq++;
           w = strtok (NULL, SEP);
       }
   }
    
    hashtableC_visit(tab, imprime_freq);
    
    hashtableC_free(tab);

    fclose(fp);

    return 0;
}
