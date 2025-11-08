#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the number of words in a string
 * @str: the string to count words in
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (*str == ' ')
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to array of strings, or NULL if fails
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, word_count;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	i = 0;
	while (*str && i < word_count)
	{
		if (*str != ' ')
		{
			len = 0;
			while (str[len] && str[len] != ' ')
				len++;

			words[i] = malloc((len + 1) * sizeof(char));
			if (words[i] == NULL)
			{
				for (j = 0; j < i; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}

			for (k = 0; k < len; k++)
				words[i][k] = str[k];
			words[i][k] = '\0';
			i++;
			str += len;
		}
		else
		{
			str++;
		}
	}
	words[i] = NULL;
	return (words);
}
