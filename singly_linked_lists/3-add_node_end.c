#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds node at end of list
 * @head: pointer to pointer of head
 * @str: string to duplicate
 *
 * Return: address of new node, or NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp;
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
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new;

	return (new);
}

