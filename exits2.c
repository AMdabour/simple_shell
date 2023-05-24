#include "shell.h"


/**
 * _strchr - function that Locates a character in a string.
 * @S: ptr to The string to be parsed.
 * @C: ptr to The character to look for.
 * Return: NULL .
 */


char *_strchr(char *S, char C)
{
	do {
		if (*S == C)
		{
			return (S);
		}
	} while (*S++ != '\0');

	return (NULL);
}
