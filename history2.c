#include "shell.h"



/**
 * read_history - function that Reads history from file.
 * @INFO: The parameter struct.
 *
 * Return:two options : an int (histcount on success) or  0 otherwise.
 */

int read_history(info_t *INFO)
{
	int i, LAST = 0, LINECOUNT = 0;
	ssize_t FD, RDLEN, FSIZE = 0;
	struct stat ST;
	char *BUF = NULL, *FILENAME = get_history_file(INFO);

	if (!FILENAME)
		return (0);

	FD = open(FILENAME, O_RDONLY);
	free(FILENAME);
	if (FD == -1)
		return (0);
	if (!fstat(FD, &ST))
		FSIZE = ST.st_size;
	if (FSIZE < 2)
		return (0);
	BUF = malloc(sizeof(char) * (FSIZE + 1));
	if (!BUF)
		return (0);
	RDLEN = read(FD, BUF, FSIZE);
	BUF[FSIZE] = 0;
	if (RDLEN <= 0)
		return (free(BUF), 0);
	close(FD);
	for (i = 0; i < FSIZE; i++)
		if (BUF[i] == '\n')
		{
			BUF[i] = 0;
			build_history_list(INFO, BUF + LAST, LINECOUNT++);
			LAST = i + 1;
		}
	if (i != LAST)
		build_history_list(INFO, BUF + LAST, LINECOUNT++);
	free(BUF);
	INFO->histcount = LINECOUNT;
	while (INFO->histcount-- >= HIST_MAX)
		delete_node_at_index(&(INFO->history), 0);
	renumber_history(INFO);
	return (INFO->histcount);
}





/**
 * build_history_list - function that adds an entry to a history linked list.
 * @INFO: ptr to info_t Structure containing potential arguments
 * @BUF: used as a buffer .
 * @LINECOUNT: int value used to count The history linecount, histcount
 *
 * Return:  0 ( NON Changable)
 */

int build_history_list(info_t *INFO, char *BUF, int LINECOUNT)
{
	list_t *NODE = NULL;

	if (INFO->history)
	{
		NODE = INFO->history;
	}
	add_node_end(&NODE, BUF, LINECOUNT);

	if (!INFO->history)
	{
		INFO->history = NODE;
	}
	return (0);
}




/**
 * renumber_history - function that is used to Renumbers the history linked ls
 * @INFO: type of info_t Structure containing potential arg and used to
 *
 * Return: only one option : int value : The new histcount
 */
int renumber_history(info_t *INFO)
{
	list_t *NODE = INFO->history;
	int I = 0;


	while (NODE)
	{
		NODE->num = I++;
		NODE = NODE->next;
	}

	return (INFO->histcount = I);
}
