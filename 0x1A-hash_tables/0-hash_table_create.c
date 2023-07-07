#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 *
 * @size: size of hash table
 *
 * Return: created hash table on success, NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i = 0;
	hash_table_t *table;

	table = malloc(sizeof(hash_table_t));
	if (!table || !size)
		return (NULL);

	table->array = malloc(sizeof(hash_node_t *) * size);
	if (!(table->array))
		return (NULL);

	table->size = size;
	for (i = 0 ; i < size; i++)
		table->array[i] = NULL;

	return (table);
}
