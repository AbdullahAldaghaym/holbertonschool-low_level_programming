#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: string containing acceptable characters
 *
 * Return: number of bytes in initial segment of s with only accept chars
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found;
	char *a;

	while (*s)
	{
		found = 0;
		a = accept;

		while (*a)
		{
			if (*s == *a)
			{
				found = 1;
				break;
			}
			a++;
		}

		if (!found)
			break;

		count++;
		s++;
	}

	return (count);
}
