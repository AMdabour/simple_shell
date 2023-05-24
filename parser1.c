#include "shell.h"



/**
 * is_cmd - function used to Determines if a file is an executable command.
 *
 * @INFO: a ptr to The info struct.
 * @PATH: the pointer to a Path to the file.
 *
 * Return:two option which are : 1 if true, 0 otherwise.
 */



int is_cmd(info_t *INFO, char *PATH)
{
	struct stat ST;

	(void)INFO;

	if (!PATH || stat(PATH, &ST))
	{
		return (0);
	}

	if (ST.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}



/**
 * dup_chars - function to Duplicates characters.
 *
 * @PATHSTR:a ptr to  The PATH string.
 * @START: the Starting index.
 * @STOP: the Stopping index.
 *
 * Return: the Ptr to the  new buffer.
 */
char *dup_chars(char *PATHSTR, int START, int STOP)
{
	static char BUF[1024];
	int I = 0, K = 0;


	for (K = 0, I = START; I < STOP; I++)
	{
		if (PATHSTR[I] != ':')
		{
			BUF[K++] = PATHSTR[I];
		}
	}

	BUF[K] = 0;
	return (BUF);
}


