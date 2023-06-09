#include "shell.h"

/**
 * set_info - function that Initializes info_t struct.
 * @INFO: ptr that points to Struct address
 * @AV: pointer to Argument vector
 */
void set_info(info_t *INFO, char **AV)
{
	int I = 0;

	INFO->fname = AV[0];
	if (INFO->arg)
	{
		INFO->argv = strtow(INFO->arg, " \t");
		if (!INFO->argv)
		{
			INFO->argv = malloc(sizeof(char *) * 2);

			if (INFO->argv)
			{
				INFO->argv[0] = _strdup(INFO->arg);
				INFO->argv[1] = NULL;
			}
		}

		for (I = 0; INFO->argv && INFO->argv[I]; I++)
			;
		INFO->argc = I;

		replace_alias(INFO);
		replace_vars(INFO);
	}
}


/**
 *free_info - function that Frees info_t struct fields.
 *@INFO: pointer to Struct address
 *@ALL: variable that is True if freeing all fields
 */
void free_info(info_t *INFO, int ALL)
{
	ffree(INFO->argv);
	INFO->argv = NULL;
	INFO->path = NULL;

	if (ALL)
	{
		if (!INFO->cmd_buf)
		{
			free(INFO->arg);
		}

		if (INFO->env)
		{
			free_list(&(INFO->env));
		}

		if (INFO->history)
		{
			free_list(&(INFO->history));
		}

		if (INFO->alias)
		{
			free_list(&(INFO->alias));
		}

		ffree(INFO->environ);
		INFO->environ = NULL;
		bfree((void **)INFO->cmd_buf);

		if (INFO->readfd > 2)
		{
			close(INFO->readfd);
		}

		_putchar(BUF_FLUSH);
	}
}


/**
 *clear_info - function used to initializes info_t struct .
 *@INFO: ptr to struct address
 *Return: void (Nothing)
 */
void clear_info(info_t *INFO)
{
	INFO->arg = NULL;
	INFO->argv = NULL;
	INFO->path = NULL;
	INFO->argc = 0;
}
