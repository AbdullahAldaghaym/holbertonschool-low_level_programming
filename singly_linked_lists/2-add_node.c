#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new node at the beginning of list_t
 * @head: pointer to pointer of head
 * @str: string to duplicate
 *
 * Return: address of new node, or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		free(dup);
		return (NULL);
	}

	new->str = dup;
	new->len = strlen(str);
	new->next = *head;
	*head = new;

	return (new);
}

