#include <stdio.h>

#define MAX_DIGITS 100

/**
 * add_strings - adds two numbers represented as strings
 * @a: first number string
 * @b: second number string
 * @result: buffer to store result
 */
void add_strings(char a[], char b[], char result[])
{
	int carry = 0;
	int i, digit_sum;
	char temp;

	/* Add digits from right to left */
	for (i = 0; i < MAX_DIGITS; i++)
	{
		digit_sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = digit_sum / 10;
		result[i] = (digit_sum % 10) + '0';
	}
}

/**
 * print_number - prints a number stored as string (without leading zeros)
 * @num: number as string (stored in reverse)
 */
void print_number(char num[])
{
	int i = MAX_DIGITS - 1;

	/* Skip leading zeros */
	while (i > 0 && num[i] == '0')
		i--;

	/* Print the number */
	for (; i >= 0; i--)
		putchar(num[i]);
}

/**
 * main - prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	char a[MAX_DIGITS] = {0};
	char b[MAX_DIGITS] = {0};
	char next[MAX_DIGITS] = {0};
	int i;

	/* Initialize first two Fibonacci numbers */
	a[0] = '1';  /* 1 */
	b[0] = '2';  /* 2 */

	/* Print first two numbers */
	print_number(a);
	printf(", ");
	print_number(b);

	/* Generate and print next 96 numbers */
	for (i = 3; i <= 98; i++)
	{
		add_strings(a, b, next);
		printf(", ");
		print_number(next);

		/* Shift numbers: a = b, b = next */
		for (int j = 0; j < MAX_DIGITS; j++)
		{
			a[j] = b[j];
			b[j] = next[j];
		}
	}

	printf("\n");
	return (0);
}
