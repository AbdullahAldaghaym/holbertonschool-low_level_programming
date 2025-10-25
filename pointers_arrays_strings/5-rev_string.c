#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0;
	int start = 0;
	int end;
	char temp;

	/* Find the length of the string */
	while (s[length] != '\0')
		length++;

	end = length - 1;

	/* Reverse the string by swapping characters */
	while (start < end)
	{
		/* Swap characters */
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;

		/* Move towards the center */
		start++;
		end--;
	}
}
