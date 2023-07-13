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
shash_node_t *current;

if (!ht->shead)
{
ht->shead = new_node;
ht->stail = new_node;
}
else if (strcmp(new_node->key, ht->shead->key) < 0)
{
/* New node is the new head */
new_node->snext = ht->shead;
ht->shead->sprev = new_node;
ht->shead = new_node;
}
else
{
/* Find the correct position for the new node */
current = ht->shead;

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

