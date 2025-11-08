#include "main.h"
#include <stdlib.h>

/**
 * is_space - checks if character is space
 * @c: character to check
 *
 * Return: 1 if space, 0 otherwise
 */
int is_space(char c)
{
	return (c == ' ');
}

/**
 * skip_spaces - moves pointer past spaces
 * @str: string pointer
 *
 * Return: pointer to next non-space character
 */
char *skip_spaces(char *str)
{
	while (is_space(*str))
		str++;
	return (str);
}

/**
 * word_length - calculates length of current word
 * @str: string
 *
 * Return: length of word
 */
int word_length(char *str)
{
	int len = 0;

	while (*str && !is_space(*str))
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * count_words - counts words in string
 * @str: string
 *
 * Return: word count
 */
int count_words(char *str)
{
	int count = 0;

	if (str == NULL || *str == '\0')
		return (0);

	str = skip_spaces(str);
	while (*str)
	{
		count++;
		str += word_length(str);
		str = skip_spaces(str);
	}
	return (count);
}

/**
 * copy_word - copies a word to new memory
 * @str: source string
 * @len: word length
 *
 * Return: pointer to new word, or NULL if fails
 */
char *copy_word(char *str, int len)
{
	char *word;
	int i;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		word[i] = str[i];
	word[i] = '\0';

	return (word);
}

/**
 * free_words - frees allocated words array
 * @words: words array
 * @count: number of words allocated
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - splits string into words
 * @str: string to split
 *
 * Return: array of words
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, words_count, len;

	if (str == NULL || *str == '\0')
		return (NULL);

	words_count = count_words(str);
	if (words_count == 0)
		return (NULL);

	words = malloc((words_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	str = skip_spaces(str);
	while (*str && i < words_count)
	{
		len = word_length(str);
		words[i] = copy_word(str, len);
		if (words[i] == NULL)
		{
			free_words(words, i);
			return (NULL);
		}
		str += len;
		str = skip_spaces(str);
		i++;
	}
	words[i] = NULL;
	return (words);
}
