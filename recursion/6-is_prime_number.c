#include "main.h"

/**
 * is_divisible - checks if n is divisible by divisor
 * @n: number to check
 * @divisor: current divisor to test
 *
 * Return: 1 if divisible, 0 otherwise
 */
int is_divisible(int n, int divisor)
{
	if (divisor * divisor > n)
	{
		return (0);
	}

	if (n % divisor == 0)
	{
		return (1);
	}

	return (is_divisible(n, divisor + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	if (n == 2)
	{
		return (1);
	}

	return (!is_divisible(n, 2));
}
