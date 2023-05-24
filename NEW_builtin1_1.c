#include "shell.h"


/**
 * unset_alias - function that  sets alias to string
 * @INFO: ptr to parameter struct
 * @STR: ptr to  the string alias
 *
 * Return: two option : Always 0 on success, 1 on error
 */


int unset_alias(info_t *INFO, char *STR)
{
	char *P, C;
	int RET;

	P = _strchr(STR, '=');
	if (!P)
	{
		return (1);
	}

	C = *P;
	*P = 0;

	RET = delete_node_at_index(&(INFO->alias),
	get_node_index(INFO->alias, node_starts_with(INFO->alias, STR, -1)));

	*P = C;

	return (RET);
}





/**
 * _myhistory - function that displays the history list.
 * Description:with line numbers, starting at 0.
 * @theinfo: the_info .
 *  Return:  0
 */


int _myhistory(info_t *theinfo)
{
	print_list(theinfo->history);
	return (0);
}

/**
 * set_alias - function that sets alias to string
 * @INFO: ptr to parameter struct
 * @STR: ptr to the string alias
 *
 * Return: two options  Always 0, 1 on error
 */

int set_alias(info_t *INFO, char *STR)
{
	char *P;

	P = _strchr(STR, '=');

	if (!P)
	{
		return (1);
	}

	if (!*++P)
	{
		return (unset_alias(INFO, STR));
	}

	unset_alias(INFO, STR);

	return (add_node_end(&(INFO->alias), STR, 0) == NULL);
}

