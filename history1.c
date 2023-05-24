#include "shell.h"


/**
 * get_history_file - fucntion used to Get the history file.
 *
 * @INFO: The parameter struct.
 *
 * Return: return the allocated string containing history file.
 */


char *get_history_file(info_t *INFO)
{
	char *BUF, *DIR;

	DIR = _getenv(INFO, "HOME=");

	if (!DIR)
	{
		return (NULL);
	}

	BUF = malloc(sizeof(char) * (_strlen(DIR) + _strlen(HIST_FILE) + 2));

	if (!BUF)
	{
		return (NULL);
	}

	BUF[0] = 0;
	_strcpy(BUF, DIR);
	_strcat(BUF, "/");
	_strcat(BUF, HIST_FILE);

	return (BUF);
}



/**
 * write_history - function to creates a file, or appends to an existing file.
 *
 *@INFO: The parameter struct.
 *
 * Return: two option which are : 1 on success, else -1.
 */


int write_history(info_t *INFO)
{
	ssize_t fd;
	char *FILENAME = get_history_file(INFO);
	list_t *NODE = NULL;


	if (!FILENAME)
	{
		return (-1);
	}

	fd = open(FILENAME, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(FILENAME);

	if (fd == -1)
	{
		return (-1);
	}

	for (NODE = INFO->history; NODE; NODE = NODE->next)
	{
		_putsfd(NODE->str, fd);
		_putfd('\n', fd);
	}

	_putfd(BUF_FLUSH, fd);
	close(fd);

	return (1);
}





