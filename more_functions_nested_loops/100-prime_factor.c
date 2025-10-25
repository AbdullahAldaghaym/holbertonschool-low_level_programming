#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long num = 612852475143;
	long factor = 2;
	long max_prime = 0;

	while (num > 1)
	{
		if (num % factor == 0)
		{
			max_prime = factor;
			num /= factor;
			while (num % factor == 0)
				num /= factor;
		}
		factor++;
	}

	printf("%ld\n", max_prime);

	return (0);
}
