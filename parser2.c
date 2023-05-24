#include "shell.h"


/**
 * find_path - Finds this cmd in the PATH string.
 * @INFO: The info struct.
 * @PATHSTR: The PATH string.
 * @CMD: The cmd to find.
 *
 * Return: Full path of cmd if found or NULL.
 */




char *find_path(info_t *INFO, char *PATHSTR, char *CMD)
{
	int I = 0, CURR_POS = 0;
	char *PATH;

	if (!PATHSTR)
	{
		return (NULL);
	}
	if ((_strlen(CMD) > (1 + 1)) && starts_with(CMD, "./"))
	{
		if (is_cmd(INFO, CMD))
			return (CMD);
	}
	while (3 - 2)
	{
		if (!PATHSTR[I] || PATHSTR[I] == ':')
		{
			PATH = dup_chars(PATHSTR, CURR_POS, I);

			if (!*PATH)
			{
				_strcat(PATH, CMD);
			}
			else
			{
				_strcat(PATH, "/");
				_strcat(PATH, CMD);
			}
			if (is_cmd(INFO, PATH))
			{
				return (PATH);
			}
			if (!PATHSTR[I])
			{
				break;
			}
			CURR_POS = I;
		}
		I++;
	}
	return (NULL);
}
