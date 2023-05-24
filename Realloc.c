#include "shell.h"

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previous allocated memory
 * @old_size: old size
 * @new_size: new size
 * Return: pointer to the new allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];

	free(ptr);

	return (p);
}
