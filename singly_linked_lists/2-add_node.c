#include "lists.h"
#include <string.h>


/**
* add_node - adds a new node at the beginning of list
* @head: pointer to pointer to list head
* @str: new string to store
*
* Return: pointer to new node
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *new;
unsigned int len = 0;


new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);


while (str[len])
len++;


new->str = strdup(str);
new->len = len;
new->next = *head;
*head = new;


return (new);
}
