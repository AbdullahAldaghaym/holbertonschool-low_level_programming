#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int new_word = 1; /* Flag to indicate start of new word */

	while (str[i] != '\0')
	{
		/* Check if current character is a word separator */
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		    str[i] == ',' || str[i] == ';' || str[i] == '.' ||
		    str[i] == '!' || str[i] == '?' || str[i] == '"' ||
		    str[i] == '(' || str[i] == ')' || str[i] == '{' ||
		    str[i] == '}')
		{
			new_word = 1;
		}
		/* If it's start of new word and character is lowercase */
		else if (new_word && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
			new_word = 0;
		}
		/* If it's not a separator and not start of word */
		else
		{
			new_word = 0;
		}
		i++;
	}
	return (str);
}
