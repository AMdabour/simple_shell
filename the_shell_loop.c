#include "shell.h"



/**
 *hsh - the main c function of the our shell .
 *@info: Its a pointer to the structure of type info_t.
 *@av:  Its the main function argument verctor .
 *
 *Description:  The hsh function runs the main loop of a shell .
 *(r,RE) , (builin_ret, btvalue)
 *Return:three outputs on three conditions 1 or 0 or error .
 */



int hsh(info_t *info, char **av)
{
	ssize_t RE = 0;
	int btvalue = 0;


	while (RE != -1 && btvalue != -2)
	{
		clear_info(info);

		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		RE = get_input(info);

		if (RE != -1)
		{
			set_info(info, av);
			btvalue = find_builtin(info);
			if (btvalue == -1)
				find_cmd(info);
		}

		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}

	write_history(info);
	free_info(info, 1);

	if (!interactive(info) && info->status)
		exit(info->status);
	if (btvalue == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (btvalue);
}



/**
 * find_builtin - searches for  a builtin command from a list of builtin cmds
 * @info: Its a pointer to the structure of type info_t.
 *
 *Return: It has three return values which are 0 , 1 and -2.
 *
 *(i, iterator) , ( built_in_ret , btinret)
 *Description: searches for a built-in command in a table of built-in commands
 *             and executes the corresponding function if a match is found.
 *
 */


int find_builtin(info_t *info)
{
	int iterator, btinret = -1;
	/**
	 *the command lists to choose from .
	 *for example if the input is exit It calls the function -myexit .
	 */
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};


	for (iterator = 0; builtintbl[iterator].type; iterator++)
		if (_strcmp(info->argv[0], builtintbl[iterator].type) == 0)
		{
			info->line_count++;
			btinret = builtintbl[iterator].func(info);
			break;
		}

	return (btinret);
}
