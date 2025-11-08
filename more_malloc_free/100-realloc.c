#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: pointer to reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i, min_size;

	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));

	/* If new_size is 0 and ptr is not NULL, equivalent to free(ptr) */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If new_size == old_size, do nothing */
	if (new_size == old_size)
		return (ptr);

	/* Allocate new memory block */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Copy contents from old block to new block */
	old_ptr = ptr;
	min_size = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < min_size; i++)
		new_ptr[i] = old_ptr[i];

	/* Free old memory block */
	free(ptr);

	return (new_ptr);
}
