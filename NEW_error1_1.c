#include "shell.h"


/**
 * print_error - function that prints an error message
 * @myinfo: INFO
 * @myestr: string containing specified error type
 *Description: description .
 * Return: two options 0 and -1 .
 */


void print_error(info_t *myinfo, char *myestr)
{
	_eputs(myinfo->fname);
	_eputs(": ");

	print_d(myinfo->line_count, STDERR_FILENO);
	_eputs(": ");

	_eputs(myinfo->argv[0]);
	_eputs(": ");

	_eputs(myestr);
}


/**
 * _erratoi - function that converts a string to an integer .
 * @S: ptr to the string to be converted .
 *
 *Description: description .
 * Return: two options 0 and - 1 .
 */


int _erratoi(char *S)
{
	int I = 0;
	unsigned long int RESULT = 0;

	if (*S == '+')
	{
		S++;
	}

	for (I = 0; S[I] != '\0'; I++)
	{
		if (S[I] >= '0' && S[I] <= '9')
		{
			RESULT *= 10;
			RESULT += (S[I] - '0');

			if (RESULT > INT_MAX)
			{
				return (-1);
			}
		}

		else
		{
			return (-1);
		}
	}

	return (RESULT);
}



/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @INPUT: the input (integer ) .
 * @FD: integer .
 *
 *Description: description .
 * Return: number of characters printed (integer) .
 */


int print_d(int INPUT, int FD)
{
	int (*__PUTCHAR)(char) = _putchar;
	int I, COUNT = 0;
	unsigned int _ABS_, CURRENT;

	if (FD == STDERR_FILENO)
	{
		__PUTCHAR = _eputchar;
	}

	if (INPUT < 0)
	{
		_ABS_ = -INPUT;
		__PUTCHAR('-');
		COUNT++;
	}

	else
	{
		_ABS_ = INPUT;
	}

	CURRENT = _ABS_;

	for (I = 1000000000; I > 1; I /= 10)
	{
		if (_ABS_ / I)
		{
			__PUTCHAR('0' + CURRENT / I);
			COUNT++;
		}

		CURRENT %= I;
	}

	__PUTCHAR('0' + CURRENT);
	COUNT++;

	return (COUNT);
}
