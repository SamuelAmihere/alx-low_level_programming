#include "hash_tables.h"

/**
 * shash_table_create - Creates new sorted hash table
 *
 * @size: size of hash table
 *
 * Return: created hash table on success, NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i = 0;
	shash_table_t *table;

	table = malloc(sizeof(shash_table_t));
	if (!table || !size)
		return (NULL);

	table->array = malloc(sizeof(shash_node_t *) * size);
	if (!(table->array))
	{
		free(table);
		return (NULL);
	}

	table->size = size;
	table->shead = NULL;
	table->stail = NULL;

	for (; i < size; i++)
		table->array[i] = NULL;

	return (table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 *
 * @ht: The sorted hash table
 * @key: The key
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *old_node, *new_node;

	if (!key || !ht || strcmp(key, "") == 0)
		return (0);

	index = key_index((unsigned char *) key, ht->size);
	old_node = ht->array[index];
	while (old_node)
	{
		if (strcmp(old_node->key, key) == 0)
		{
			free(old_node->value);
			old_node->value = strdup(value);
			return (1);
		}
		old_node = old_node->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (!new_node)
		return (1);

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = old_node;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	ht->array[index] = new_node;

	if (old_node)
		old_node->sprev = new_node;

	insert_sorted_node(ht, new_node);

	return (1);
}

/**
 * insert_sorted_node - Inserts node into sorted hash table
 *
 * @ht: The sorted hash table
 * @new_node: New node to insert
 *
 * Return: Nothing
 */
void insert_sorted_node(shash_table_t *ht, shash_node_t *new_node)
{
	if (!ht->shead)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	} else if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		/* New node is the new head */
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	} else
	{
		/* Find the correct position for the new node */
		shash_node_t *current = ht->shead;

		while (current->snext &&
				strcmp(new_node->key, current->snext->key) >=
				0)
		{
			current = current->snext;
		}

		new_node->sprev = current;
		new_node->snext = current->snext;

		if (current->snext)
			current->snext->sprev = new_node;
		else
			ht->stail = new_node;

		current->snext = new_node;
	}
}


/**
 * shash_table_get - Retrieves a key's value
 *
 * @ht: Hash table
 * @key: Key to search its value
 *
 * Return: key's value, NULL if value does not exists
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node = NULL;
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
	return (node->value);
}

/**
 * shash_table_print - Prints a sorted hash table.
 *
 * @ht: Hash table
 *
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current = NULL;
	unsigned int sep_flag = 0;

	if (!ht)
		return;

	printf("{");

	current = ht->shead;
	while (current)
	{
		if (sep_flag == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		sep_flag = 1;
		current = current->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash tables key/value pairs in
 * reverse order using the sorted linked list
 *
 * @ht: sorted hash table
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *curr_node = ht->stail;

	printf("{");

	if (ht != NULL)
	{
		while (curr_node)
		{
			printf("'%s': '%s'", curr_node->key, curr_node->value);

			if (curr_node->sprev)
				printf(", ");

			curr_node = curr_node->sprev;
		}
	}

	printf("}\n");
}

/**
 * shash_table_delete - Deletes sorted hash table
 *
 * @ht: sorted hash table
 *
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node = NULL;
	shash_node_t *tmp = NULL;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
