#include "main.h"
#include <stdio.h>
#include <ctype.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of buffer
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		/* Print position */
		printf("%08x: ", i);

		/* Print hex bytes */
		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x", (unsigned char)b[i + j]);
			else
				printf("  ");

			if (j % 2)
				printf(" ");
		}

		/* Print ASCII characters */
		for (j = 0; j < 10; j++)
		{
			if (i + j >= size)
				break;

			if (isprint(b[i + j]))
				printf("%c", b[i + j]);
			else
				printf(".");
		}

		printf("\n");
	}
}
