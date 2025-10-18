#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char digit;

	/* Print digits 0-9 */
	digit = '0';
	while (digit <= '9')
	{
		putchar(digit);
		digit++;
	}

	/* Print letters a-f */
	digit = 'a';
	while (digit <= 'f')
	{
		putchar(digit);
		digit++;
	}

	putchar('\n');

	return (0);
}
