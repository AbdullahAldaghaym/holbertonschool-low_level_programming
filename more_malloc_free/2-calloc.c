#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL if fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i, total_size;

	/* Check for zero parameters */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Calculate total memory needed */
	total_size = nmemb * size;

	/* Allocate memory */
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	/* Initialize memory to zero */
	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return (ptr);
}
