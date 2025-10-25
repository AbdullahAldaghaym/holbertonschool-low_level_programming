#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string to append
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	/* Move to the end of dest */
	while (*ptr != '\0')
		ptr++;

	/* Copy src to end of dest */
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	/* Add null terminator */
	*ptr = '\0';

	return (dest);
}
