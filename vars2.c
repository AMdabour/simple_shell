#include "shell.h"


/**
 * replace_alias - Function used to Replaces an alias in the tokenized string.
 *
 * @my_info: The parameter struct.
 *
 * Return: two options:  1 if replaced, 0 otherwise.
 */


int replace_alias(info_t *my_info)
{
	int z;
	list_t *node;
	char *myp;

	for (z = 0; z < 10; z++)
	{
		node = node_starts_with(my_info->alias, my_info->argv[0], '=');
		if (!node)
		{
			return (0);
		}

		free(my_info->argv[0]);
		myp = _strchr(node->str, '=');

		if (!myp)
		{
			return (0);
		}

		myp = _strdup(myp + 1);

		if (!myp)
		{
			return (0);
		}

		my_info->argv[0] = myp;
	}

	return (1);
}


/**
 * replace_vars - function to replaces variables.
 * @INFO: The parameter struct.
 *
 *Return: two options which are 1 if replaced, 0 otherwise.
 */
int replace_vars(info_t *INFO)
{
	int z = 0;
	list_t *NODE;

	for (z = 0; INFO->argv[z]; z++)
	{
		if (INFO->argv[z][0] != '$' || !INFO->argv[z][1])
			continue;

		if (!_strcmp(INFO->argv[z], "$?"))
		{
			replace_string(&(INFO->argv[z]),
				_strdup(convert_number(INFO->status, 10, 0)));
			continue;
		}

		if (!_strcmp(INFO->argv[z], "$$"))
		{
			replace_string(&(INFO->argv[z]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}

		NODE = node_starts_with(INFO->env, &(INFO->argv[z][1]), '=');
		if (NODE)
		{
			replace_string(&(INFO->argv[z]),
				_strdup(_strchr(NODE->str, '=') + 1));
			continue;
		}

		replace_string(&(INFO->argv[z]), _strdup(""));
	}

	return (0);
}



/**
 * replace_string - function used to Replaces a string.
 * @OLD: Address of the old string.
 * @NEW: New string.
 *
 * Return: two option : 1 if replaced, 0 otherwise.
 */

int replace_string(char **OLD, char *NEW)
{
	free(*OLD);
	*OLD = NEW;
	return (1);
}

