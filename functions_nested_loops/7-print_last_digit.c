#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to extract last digit from
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
	int last_digit;

	/* Get the last digit using modulo 10 */
	last_digit = n % 10;

	/* Handle negative numbers - make last digit positive */
	if (last_digit < 0)
	{
		last_digit = -last_digit;
	}

	/* Print the last digit */
	_putchar(last_digit + '0');

	/* Return the last digit value */
	return (last_digit);
}
