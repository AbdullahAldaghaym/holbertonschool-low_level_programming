#include "dog.h"
#include <stdlib.h>

/**
 * get_string_length - gets length of string
 * @s: string to measure
 *
 * Return: length
 */
int get_string_length(char *s)
{
	int length = 0;

	while (s[length])
		length++;

	return (length);
}

/**
 * copy_string - copies string to new memory
 * @dest: destination
 * @src: source
 *
 * Return: dest
 */
char *copy_string(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates new dog with copied strings
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 *
 * Return: new dog pointer
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *name_cpy, *owner_cpy;
	int name_len, owner_len;

	dog = malloc(sizeof(dog_t));
	if (!dog)
		return (NULL);

	name_len = get_string_length(name);
	owner_len = get_string_length(owner);

	name_cpy = malloc(name_len + 1);
	if (!name_cpy)
	{
		free(dog);
		return (NULL);
	}
	copy_string(name_cpy, name);

	owner_cpy = malloc(owner_len + 1);
	if (!owner_cpy)
	{
		free(name_cpy);
		free(dog);
		return (NULL);
	}
	copy_string(owner_cpy, owner);

	dog->name = name_cpy;
	dog->age = age;
	dog->owner = owner_cpy;

	return (dog);
}
