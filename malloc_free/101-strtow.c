#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts words in string
 * @s: string
 *
 * Return: word count
 */
int count_words(char *s)
{
	int flag = 0, wc = 0;

	while (*s)
	{
		if (*s == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			wc++;
		}
		s++;
	}
	return (wc);
}

/**
 * strtow - splits string into words
 * @str: string to split
 *
 * Return: array of words
 */
char **strtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_words(str);
	if (words == 0)
		return (NULL);

	matrix = malloc((words + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= (int)_strlen(str); i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = malloc((c + 1) * sizeof(char));
				if (tmp == NULL)
				{
					for (k = 0; k < words; k++)
						free(matrix[k]);
					free(matrix);
					return (NULL);
				}
				for (len = 0; start < end; start++)
					tmp[len++] = str[start];
				tmp[len] = '\0';
				matrix[k] = tmp;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}
	matrix[k] = NULL;
	return (matrix);
}
