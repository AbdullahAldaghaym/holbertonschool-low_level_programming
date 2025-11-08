#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string, or NULL if fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, total_len = 0;

	/* Check for invalid inputs */
	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length needed */
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			total_len++;
			j++;
		}
		total_len++; /* For newline character */
	}
	total_len++; /* For null terminator */

	/* Allocate memory */
	str = malloc(total_len * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Copy arguments with newlines */
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			str[k] = av[i][j];
			j++;
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return (str);
}
