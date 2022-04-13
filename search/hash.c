#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem.h"
#include "atom.h"
#include "hash.h"

#define HT_NUMBER_OF_PRIMES 41

static long _primes[HT_NUMBER_OF_PRIMES] = {
	101, 199, 211, 293, 307, 397, 409, 499, 
	503, 599, 607, 677, 701, 797, 809, 877, 
	907, 977, 5003, 6163, 7177, 8933, 9619, 
	9973, 14983, 19991, 24989, 29989, 34981, 
	39989, 44987, 49999, 54983, 64997, 69997, 
	74959, 79999, 84991, 89989, 94999, 99991};

static unsigned hash_atom(const void*key);
static int cmpatom(const void*x, const void*y);

/* To insert a |key|/|value| in the |hash|, the |key| is lookup to
avoid duplications, and if it exists the new value is assigned to the
key. If it is the first time in the |hash|, it is inserted by placing
in the front of |buckets| and linking it to the rest of chain of
already inserted entries in the |buckets|. */

struct hash_table *hash_table_new(int hint, 
				  int (*cmp)(const void *x, const void *y),
				  unsigned (*hash)(const void *key),
				  void (*release)(void *val))
{
	struct hash_table *new;
	
	NEW(new);
	new->nbuckets = _primes[hint % HT_NUMBER_OF_PRIMES];
	new->buckets = CALLOC(new->nbuckets, sizeof(struct hash_table_entry*));
	new->cmp = cmp ? cmp : cmpatom;
	new->hash = hash ? hash : hash_atom;
	new->release = release ? release : free;
	new->nelems = 0;
	
	return new;
}

struct hash_table_entry *hash_table_insert(struct hash_table*table,
					   const void *key, 
					   void *val)
{
	struct hash_table_entry *np;
	unsigned hash_val;
	
	assert(key != NULL);
	assert(val != NULL);
	
	if ((np = hash_lookup(table, key)) == NULL) {
		NEW(np);
		
		hash_val = table->hash(key);
		np->key = key;
		np->val = val;
		np->next = table->buckets[hash_val];
		table->buckets[hash_val] = np;
		table->nelems++;
	} else /* key found */
		return NULL;
	
	return np;
}

static int cmpatom(const void*x, const void*y)
{
	return x != y;
}

static unsigned hash_atom(const void*key)
{
	return (unsigned long)key>>2;
}

struct hash_table_entry *hash_table_lookup(struct hash_table*table,
				       const void *key)
{
	struct hash_table_entry *ep;
	
	assert(key != NULL);
	
	for (ep=table->buckets[table->hash(key)]; ep != NULL; ep = ep->next)
		if (table->cmp(key, ep->key) == 0)
				return ep;
	return NULL;
}

void hash_table_free(struct hash_table *table)
{
	unsigned i;
	struct hash_table_entry *next_ptr, *cur_ptr;
	
	assert(table != NULL);
	assert(table->buckets != NULL);
	
	for (i=0; i<table->nbuckets; i++) {
		cur_ptr = table->buckets[i];
		
		if (cur_ptr!=NULL) {
			do {
				next_ptr = cur_ptr->next;
				table->release(cur_ptr);
			} while(next_ptr != NULL);
		}
	}
}
