#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates program arguments
 * @ac: argument count
 * @av: argument vector
 *
 * Return: concatenated string
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0, len = 0;

	if (!ac || !av)
		return (NULL);

	for (i = 0; i < ac; i++)
		for (j = 0; av[i][j]; j++)
			len++;
	len += ac + 1;

	str = malloc(len);
	if (!str)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[k++] = av[i][j];
		str[k++] = '\n';
	}
	str[k] = '\0';

	return (str);
}
