#include <stdio.h>

/**
 * main - prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2, next;
	unsigned long a_h, a_l, b_h, b_l, n_h, n_l;

	printf("%lu, %lu", a, b);

	for (i = 3; i <= 92; i++)
	{
		next = a + b;
		printf(", %lu", next);
		a = b;
		b = next;
	}

	a_h = a / 10000000000;
	a_l = a % 10000000000;
	b_h = b / 10000000000;
	b_l = b % 10000000000;

	for (; i <= 98; i++)
	{
		n_l = a_l + b_l;
		n_h = a_h + b_h + (n_l / 10000000000);
		n_l %= 10000000000;

		printf(", ");
		if (n_h)
			printf("%lu%010lu", n_h, n_l);
		else
			printf("%lu", n_l);

		a_h = b_h;
		a_l = b_l;
		b_h = n_h;
		b_l = n_l;
	}
	printf("\n");
	return (0);
}
