#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars and initializes it with a specific char
 * @size: size of the array
 * @c: character to initialize the array with
 *
 * Return: pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	/* Check if size is 0 */
	if (size == 0)
		return (NULL);

	/* Allocate memory for the array */
	array = malloc(size * sizeof(char));

	/* Check if malloc failed */
	if (array == NULL)
		return (NULL);

	/* Initialize the array with the specified character */
	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
