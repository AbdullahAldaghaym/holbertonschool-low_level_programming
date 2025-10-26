#include <stdio.h>

/**
 * main - prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	unsigned long a = 1, b = 2, c;
	unsigned long a1, a2, b1, b2, c1, c2;

	printf("%lu, %lu", a, b);

	for (i = 3; i <= 92; i++)
	{
		c = a + b;
		printf(", %lu", c);
		a = b;
		b = c;
	}

	a1 = a / 10000000000;
	a2 = a % 10000000000;
	b1 = b / 10000000000;
	b2 = b % 10000000000;

	for (; i <= 98; i++)
	{
		c1 = a1 + b1;
		c2 = a2 + b2;
		if (c2 > 9999999999)
		{
			c1 += c2 / 10000000000;
			c2 %= 10000000000;
		}

		printf(", ");
		if (c1)
			printf("%lu%010lu", c1, c2);
		else
			printf("%lu", c2);

		a1 = b1;
		a2 = b2;
		b1 = c1;
		b2 = c2;
	}
	printf("\n");
	return (0);
}
