#include "main.h"

/**
 * infinite_add - adds two numbers
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l1, l2, s, c;
	char t;

	for (l1 = 0; n1[l1]; l1++)
		;
	for (l2 = 0; n2[l2]; l2++)
		;

	if (l1 >= size_r || l2 >= size_r)
		return (0);

	i = l1 - 1;
	j = l2 - 1;
	k = 0;
	c = 0;

	while (i >= 0 || j >= 0 || c)
	{
		s = c;
		if (i >= 0) s += n1[i--] - '0';
		if (j >= 0) s += n2[j--] - '0';
		if (k >= size_r - 1) return (0);
		r[k++] = (s % 10) + '0';
		c = s / 10;
	}

	r[k] = '\0';

	for (i = 0, j = k - 1; i < j; i++, j--)
		t = r[i], r[i] = r[j], r[j] = t;

	return (r);
}
