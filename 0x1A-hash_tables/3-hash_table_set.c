#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 *
 * @ht: The hash table
 * @key: The key
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *old_node, *new_node;

	if (!key || !ht || strcmp(key, "") == 0)
		return (0);

	index = key_index((unsigned char *) key, ht->size);
	old_node = ht->array[index];

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (1);

	new_node->key = strdup(key);
	new_node->value = strdup(value);

	if (!old_node)
		new_node->next = NULL;
	else if (old_node && strcmp(key, old_node->key) == 0)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);

		free(old_node->value);
		old_node->value = strdup(value);

		return (1);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
