#include "main.h"

/**
 * _strlen - calculates length of string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * reverse_string - reverses a string
 * @s: string to reverse
 * @len: length of string
 */
void reverse_string(char *s, int len)
{
	int i, j;
	char temp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

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
	int len1, len2, carry, sum, i, j, k;

	len1 = _strlen(n1);
	len2 = _strlen(n2);

	/* Check if result fits in buffer */
	if (len1 > size_r - 1 || len2 > size_r - 1)
		return (0);

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

	r[k] = '\0';
	reverse_string(r, k);

	return (r);
}
