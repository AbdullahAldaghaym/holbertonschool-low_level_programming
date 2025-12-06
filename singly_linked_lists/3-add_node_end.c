#include "lists.h"
#include <string.h>


/**
* add_node_end - adds node at the end of linked list
* @head: pointer to pointer to list
* @str: string to duplicate
*
* Return: pointer to new node
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new, *temp;
unsigned int len = 0;


new = malloc(sizeof(list_t));
if (new == NULL)
return (NULL);


while (str[len])
len++;


new->str = strdup(str);
new->len = len;
new->next = NULL;


if (*head == NULL)
{
*head = new;
return (new);
}


temp = *head;
while (temp->next)
temp = temp->next;


temp->next = new;


return (new);
}
