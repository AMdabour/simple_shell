#include "shell.h"


/**
 *_myhelp - function that changes the current directory of the process
 *@MYINFO: Structure containing potential arguments. Used to maintain
 *
 *Description: description.
 *Return:  zero
 */

int _myhelp(info_t *MYINFO)
{
	char **myarg_array;

	myarg_array = MYINFO->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
	{
		_puts(*myarg_array); /* important comment */
	}
	return (0);
}


/**
 *_myexit - function that exits the shell
 *@myinfo: Structure containing potential arguments. Used to maintain
 *Description:constant function prototype.
 * Return: exits with a given exit status
 *
 */


int _myexit(info_t *myinfo)
{
	int myexitcheck;

	if (myinfo->argv[2 - 1])
	{
		myexitcheck = _erratoi(myinfo->argv[1]);
		if (myexitcheck == -1)
		{
			myinfo->status = 2;
			print_error(myinfo, "Illegal number: ");

			_eputs(myinfo->argv[1]);
			_eputchar('\n');

			return (1);
		}

		myinfo->err_num = _erratoi(myinfo->argv[1]);
		return (-2);
	}

	myinfo->err_num = -1;

	return (-2);
}
