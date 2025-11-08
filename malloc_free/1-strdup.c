#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL if fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate length of string */
	while (str[len] != '\0')
		len++;

	/* Allocate memory for duplicate (+1 for null terminator) */
	dup = malloc((len + 1) * sizeof(char));

	if (dup == NULL)
		return (NULL);

	/* Copy string */
	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
