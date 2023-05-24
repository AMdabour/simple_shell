#include "shell.h"


/**
 * _eputchar - function  that writes the character c to stderr
 * @C: The character to print
 *
 * Description: description .
 * Return: two  values which is 1 on success and -1 on error  .
 */


int _eputchar(char C)
{
	static int I;
	static char BUF[WRITE_BUF_SIZE];

	if (C == BUF_FLUSH || I >= WRITE_BUF_SIZE)
	{
		write(2, BUF, I);
		I = 0;
	}
	if (C != BUF_FLUSH)
		BUF[I++] = C;
	return (1);
}





/**
 *_eputs - function that prints an input string .
 *@STR: ptr to the string to be printed .
 *
 *Description: description .
 *Return: Nothing ( void )  .
 */

void _eputs(char *STR)
{
	int z = 0;

	if (!STR)
	{
		return;
	}

	while (STR[z] != '\0')
	{
		_eputchar(STR[z]);
		z++;
	}
}
