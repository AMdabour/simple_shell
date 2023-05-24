#inlcude "shell.h"

/**
 *_mycd - function thatchanges the current directory of the process
 *@INFO: Structure containing potential arguments. Used to maintain
 *
 *Description: description.
 * Return: Always 0
 */


int _mycd(info_t *INFO)
{
	char *S, *DIR, BUFFER[1024];
	int CHDIR_RET;

	S = getcwd(BUFFER, 1024);
	if (!S)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!INFO->argv[1])
	{
		DIR = _getenv(INFO, "HOME=");
		if (!DIR)
			chdir_ret = /*: what should this be? */
			chdir((DIR = _getenv(INFO, "PWD=")) ? DIR : "/");
		else
			CHDIR_RET = chdir(DIR);
	}
	else if (_strcmp(INFO->argv[1], "-") == 0)
	{
		if (!_getenv(INFO, "OLDPWD="))
		{
			_puts(S);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(INFO, "OLDPWD=")), _putchar('\n');
		CHDIR_RET = /* : what should this be? */
			chdir((DIR = _getenv(INFO, "OLDPWD=")) ? DIR : "/");
	}
	else
		CHDIR_RET = chdir(INFO->argv[1]);
	if (CHDIR_RET == -1)
	{
		print_error(INFO, "can't cd to ");
		_eputs(INFO->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(INFO, "OLDPWD", _getenv(INFO, "PWD="));
		_setenv(INFO, "PWD", getcwd(BUFFER, 1024));
	}
	return (0);
}
