#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of list_t list
 * @head: pointer to pointer of list head
 * @str: string to duplicate
 *
 * Return: address of new node, or NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new, *tmp;
    unsigned int len = 0;

    new = malloc(sizeof(list_t));
    if (!new)
        return (NULL);

    new->str = strdup(str);
    if (!new->str)
    {
        free(new);
        return (NULL);
    }

    while (str[len])
        len++;

    new->len = len;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return (new);
    }

    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = new;

    return (new);
}
