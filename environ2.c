#include "shell.h"


/**
 * _myunsetenv - function that Remove an environment variable
 * @INFO: INFo
 *
 * Description: descripton.
 * Return: Always Zero .
 */

int _myunsetenv(info_t *INFO)
{
	int z;

	if (INFO->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (z = 1; z <= INFO->argc; z++)
	{
		_unsetenv(INFO, INFO->argv[z]);
	}

	return (0);
}


/**
 * populate_env_list - function that populates env linked list
 * @INFO: INfo
 * Description: description
 * Return: Always 0
 */

int populate_env_list(info_t *INFO)
{
	list_t *NODE = NULL;
	size_t Z;

	for (Z = 0; environ[Z]; Z++)
	{
		add_node_end(&NODE, environ[Z], 0);
	}
	INFO->env = NODE;

	return (0);
}
