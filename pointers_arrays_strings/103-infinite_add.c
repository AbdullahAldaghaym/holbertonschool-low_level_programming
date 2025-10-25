#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number string
 * @n2: second number string
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result or 0 if error
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, carry = 0, sum, i, j, k;
	char temp;

	/* Get lengths */
	while (n1[len1]) len1++;
	while (n2[len2]) len2++;

	if (len1 > size_r - 1 || len2 > size_r - 1)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	k = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0) sum += n1[i--] - '0';
		if (j >= 0) sum += n2[j--] - '0';

		if (k >= size_r - 1) return (0);

		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}

	r[k] = '\0';

	/* Reverse result */
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}

	return (r);
}
