#include <stdio.h>

/**
 * main - prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int count;
	unsigned long int fib1 = 0, fib2 = 1, next;
	unsigned long int fib1_half1, fib1_half2, fib2_half1, fib2_half2;
	unsigned long int half1, half2;

	for (count = 1; count <= 92; count++)
	{
		next = fib1 + fib2;
		printf("%lu", next);
		fib1 = fib2;
		fib2 = next;
		if (count != 92)
			printf(", ");
	}

	fib1_half1 = fib1 / 10000000000;
	fib1_half2 = fib1 % 10000000000;
	fib2_half1 = fib2 / 10000000000;
	fib2_half2 = fib2 % 10000000000;

	for (count = 93; count <= 98; count++)
	{
		half1 = fib1_half1 + fib2_half1;
		half2 = fib1_half2 + fib2_half2;
		if (fib1_half2 + fib2_half2 > 9999999999)
		{
			half1 += 1;
			half2 %= 10000000000;
		}

		printf("%lu%010lu", half1, half2);
		if (count != 98)
			printf(", ");

		fib1_half1 = fib2_half1;
		fib1_half2 = fib2_half2;
		fib2_half1 = half1;
		fib2_half2 = half2;
	}
	printf("\n");
	return (0);
}
