/* Chaining hashtable. Bons numeros para no. de compartimentos 509,
   1021, 2053, 4093, 8191, 16381, 32771, 65521. */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#define HASHTABLEC_M 509
#define KEYLEN 512

union V {
	long I; /* no.s inteiros */
	double R; /* no.s reais */
	char *S; /* string */
};

struct hashtableC_entry {
	char *key;
	union V value;
	struct hashtableC_entry *rest;
};

struct hashtableC {
	struct hashtableC_entry **buckets;
	long n;
	long m;
};

extern struct hashtableC *hashtableC_new();
extern struct hashtableC_entry *hashtableC_get(struct hashtableC *table,
					       const char*key);
extern void hashtableC_free(struct hashtableC *table);
extern void hashtableC_visit(struct hashtableC *tab, 
            void visit(struct hashtableC_entry *ent));

#endif
