#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 *
 * @ht: Hash table
 *
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int com = 0;
	const hash_table_t *p;

	if (!ht || !(ht->array))
		return;

	p = ht;

	putchar('{');
	for (i = 0; i < p->size; i++)
	{
		if (p->array[i])
		{
			while (p->array[i])
			{
				if (com)
					printf(", ");
				com = 1;

				printf("'%s': '%s'", (p->array[i])->key,
						(p->array[i])->value);

				p->array[i] = p->array[i]->next;
			}
		}
	}
	printf("}\n");
}
