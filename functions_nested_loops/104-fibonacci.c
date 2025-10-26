#include <stdio.h>
int main(void)
{
	int i = 3;
	unsigned long a = 1, b = 2, c;
	unsigned long a1, a2, b1, b2, c1, c2;
	printf("%lu, %lu", a, b);
	while (i <= 92)
	{
		c = a + b;
		printf(", %lu", c);
		a = b;
		b = c;
		i++;
	}
	a1 = a / 10000000000;
	a2 = a % 10000000000;
	b1 = b / 10000000000;
	b2 = b % 10000000000;
	while (i <= 98)
	{
		c1 = a1 + b1;
		c2 = a2 + b2;
		if (c2 > 9999999999)
		{
			c1 += 1;
			c2 %= 10000000000;
		}
		printf(", ");
		if (c1) printf("%lu%010lu", c1, c2);
		else printf("%lu", c2);
		a1 = b1;
		a2 = b2;
		b1 = c1;
		b2 = c2;
		i++;
	}
	printf("\n");
	return (0);
}
