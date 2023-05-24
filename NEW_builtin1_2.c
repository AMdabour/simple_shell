#include "shell.h"


/**
 * print_alias - function that prints an alias string
 * @NODE: ptr to  the alias node
 *Description: description .
 * Return: two options :  Always 0 on success, 1 on error
 */

int print_alias(list_t *NODE)
{
	char *P = NULL, *A = NULL;

	if (NODE)
	{
		P = _strchr(NODE->str, '=');

		for (A = NODE->str; A <= P; A++)
		{
			_putchar(*A);
		}

		_putchar('\'');
		_puts(P + 1);
		_puts("'\n");

		return (0);
	}

	return (1);
}

/**
 * _myalias - function that add the alias button
 * @INFO: the info .
 *
 * Description: description .
 *
 * Return: zero
 */


int _myalias(info_t *INFO)
{
	int i = 0;
	char *P = NULL;
	list_t *NODE = NULL;

	if (INFO->argc == 1)
	{
		NODE = INFO->alias;
		while (NODE)
		{
			print_alias(NODE);
			NODE = NODE->next;
		}

		return (0);
	}

	for (i = 1; INFO->argv[i]; i++)
	{
		P = _strchr(INFO->argv[i], '=');

		if (P)
		{
			set_alias(INFO, INFO->argv[i]);
		}

		else
		{
			print_alias(node_starts_with(INFO->alias,
				INFO->argv[i], '='));
		}
	}

	return (0);
}
