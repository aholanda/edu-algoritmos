/* Hash table. The implementation of hash tables follows the one
   described in the K\&R book. */

#ifndef __HASH_H__
#define __HASH_H__
extern struct hash_table *hash_table_new(int hint,
					 int (*cmp)(const void *x, const void *y),
					 unsigned (*hash)(const void*key),
					 void (*release)(void *val));
extern struct hash_table_entry *hash_table_lookup(struct hash_table*table,
						  const void *key);
extern struct hash_table_entry *hash_table_insert(struct hash_table*table,
						  const void *key, 
						  void *value);
extern void hash_table_free(struct hash_table *table);

struct hash_table_entry {
	const void*key; /* key */
	void*val; /* value */
	struct hash_table_entry *next; /* next entry */
};

struct hash_table {
	int (*cmp)(const void *x, const void *y);
	unsigned (*hash)(const void*key);
	void (*release)(void*data);
	unsigned long nelems; /* number of elements in the hash table */
	struct hash_table_entry **buckets;
	unsigned long nbuckets;
};

#endif
