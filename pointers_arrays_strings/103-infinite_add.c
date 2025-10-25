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

	/* Get lengths of both strings */
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	/* Check if result fits in buffer */
	if (len1 + 1 > size_r || len2 + 1 > size_r)
		return (0);

	/* Start from the end of strings */
	i = len1 - 1;
	j = len2 - 1;
	k = 0;
	carry = 0;

	/* Add digits from right to left */
	while (i >= 0 || j >= 0 || carry != 0)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';

		carry = sum / 10;
		sum = sum % 10;

		/* Check if we have space in buffer */
		if (k >= size_r - 1)
			return (0);

		r[k] = sum + '0';
		k++;
		i--;
		j--;
	}

	/* Add null terminator */
	r[k] = '\0';

	/* Reverse the result string */
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}

	return (r);
}
