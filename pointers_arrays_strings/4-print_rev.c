#include "main.h"

/**
 * print_rev - prints a string in reverse followed by a new line
 * @s: pointer to the string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	/* Find the length of the string */
	while (s[length] != '\0')
		length++;

	/* Print from the end to the beginning */
	for (i = length - 1; i >= 0; i--)
		_putchar(s[i]);

	_putchar('\n');
}
