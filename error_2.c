#include "shell.h"


/**
 * _putfd - function that writes the character c to given fd
 * @C:  The character to  be printed
 * @FD: The filedescriptor to write to
 *
 *Description: description .
 *Return: two  values IT gives 1 on success and -1 on error .
 */


int _putfd(char C, int FD)
{
	static int I;
	static char BUF[WRITE_BUF_SIZE];

	if (C == BUF_FLUSH || I >= WRITE_BUF_SIZE)
	{
		write(FD, BUD, I);
		I = 0;
	}

	if (C != BUF_FLUSH)
	{
		BUF[I++] = C;
	}

	return (1);
}


/**
 *_putsfd - function that prints an input string  .
 * @STR: ptr to the string to be printed .
 * @FD: an integer .
 *
 *Description: description .
 * Return: the number of chars put
 */

int _putsfd(char *STR, int FD)
{
	int I = 0;

	if (!STR)
	{
		return (0);
	}

	while (*STR)
	{
		I += _PUTFD(*STR++, FD);
	}

	return (I);
}
