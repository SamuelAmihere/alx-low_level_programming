#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a key's value
 *
 * @ht: Hash table
 * @key: Key to search its value
 *
 * Return: key's value, NULL if value does not exists
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;

	if (!key || !ht || strcmp(key, "") == 0)
		return (NULL);

	index = key_index((unsigned char *) key, ht->size);

	if (!(ht->array[index]))
		return (NULL);

	return ((ht->array[index])->value);
}
