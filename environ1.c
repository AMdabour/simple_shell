#include "shell.h"

/**
 * _getenv - function that gets the value of an environ var  .
 * @INFO: Structure containing potential arguments. Used to maintain .
 * @NAME: env var name .
 *
 *Description: description .
 * Return: NUll or the char value .
 */


char *_getenv(info_t *INFO, const char *NAME)
{
	list_t *NODE = INFO->env;
	char *P;

	while (NODE)
	{
		P = starts_with(NODE->str, NAME);
		if (P && *P)
		{
			return (P);
		}
		NODE = NODE->next;
	}

	return (NULL);
}


/**
 * _myenv - function that prints the current environment
 * @myinfo: myinfo
 *
 * Description: description .
 * Return: zero
 */


int _myenv(info_t *myinfo)
{
	print_list_str(myinfo->env);

	return (0);
}


/**
 * _mysetenv - function function function .
 *
 *@INFO: ptr to info .
 *Description: description .
 *
 *Return: Zero .
 */

int _mysetenv(info_t *INFO)
{
	if (INFO->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	if (_setenv(INFO, INFO->argv[1], INFO->argv[2]))
	{
		return (0);
	}

	return (1);
}
