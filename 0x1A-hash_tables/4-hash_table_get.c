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
	hash_node_t *node = NULL;
	unsigned long int index;

	if (!key || !ht)
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);
	node = ht->array[index];

	if (!node)
		return (NULL);

	while (strcmp(node->key, key) != 0)
	{
		/* traverse a node*/
		node = node->next;
	}
	return ((ht->array[index])->value);
}
