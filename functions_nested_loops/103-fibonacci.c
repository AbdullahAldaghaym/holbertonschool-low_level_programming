#include <stdio.h>

/**
 * main - finds and prints the sum of even Fibonacci numbers below 4,000,000
 *
 * Return: Always 0
 */
int main(void)
{
	long int a = 1, b = 2, next;
	long int sum = 2;  /* Start with 2 (the first even number) */

	while (b < 4000000)
	{
		next = a + b;
		a = b;
		b = next;

		if (b % 2 == 0 && b < 4000000)
			sum += b;
	}

	printf("%ld\n", sum);

	return (0);
}
