#include "shell.h"


/**
 * convert_number - function used to convert fucntion .
 * @NUM: number (long int) .
 * @BASE: base (int) .
 * @FLAGS: argument flags .
 *
 *Description: description .
 * Return: string returned .
 */

char *convert_number(long int NUM, int BASE, int FLAGS)
{
	static char *ARRAY;
	static char BUFFER[50];

	char SIGN = 0;
	char *PTR;
	unsigned long N = NUM;

	if (!(FLAGS & CONVERT_UNSIGNED) && NUM < 0)
	{
		N = -NUM;
		SIGN = '-';

	}

	ARRAY = FLAGS & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";
	PTR = &BUFFER[49];
	*PTR = '\0';

	do	{
		*--PTR = ARRAY[N % BASE];
		N /= BASE;
	} while (N != 0);

	if (SIGN)
	{
		*--PTR = SIGN;
	}

	return (PTR);
}


/**
 * remove_comments - function that remove comments .
 * @BUF: ptr to  buffer .
 *
 *Description: description .
 *Return: zero always  .
 */

void remove_comments(char *BUF)
{
	int I;

	for (I  =  0; BUF[I]  !=  '\0'; I++)
	{
		if (BUF[I]  ==  '#' && (!I || BUF[I - 1]  ==  ' '))
		{
			BUF[I]  =  '\0';
			break;
		}
	}
}
