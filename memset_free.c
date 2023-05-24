#include "shell.h"

/**
 *_memset - fills memory with a constant byte
 *@s: the pointer to the memory block.
 *@b: the byte to fill
 *@num: the number of bytes to be filled
 *Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		s[i] = b;

	return (s);
}

/**
 * ffree - frees an array of strings
 * @pp: array of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;

	while (*pp)
		free(*pp++);

	free(a);
}
