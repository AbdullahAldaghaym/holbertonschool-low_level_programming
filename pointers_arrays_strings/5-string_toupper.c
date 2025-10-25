#include "main.h"

/**
 * string_toupper - changes all lowercase letters to uppercase
 * @str: string to modify
 *
 * Return: pointer to the modified string
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		/* Check if character is lowercase */
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			/* Convert to uppercase by subtracting 32 */
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
