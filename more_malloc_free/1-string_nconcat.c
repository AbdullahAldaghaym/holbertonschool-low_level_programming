#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to concatenated string, or NULL if fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* Use entire s2 if n >= length of s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory (s1 + n bytes from s2 + null terminator) */
	concat = malloc(len1 + n + 1);
	if (concat == NULL)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copy first n bytes of s2 */
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	/* Add null terminator */
	concat[i + j] = '\0';

	return (concat);
}
