#include "shell.h"


/**
 * find_cmd - function that gets a path provided and gets from it a command  .
 * @info: It is a pointer to a structure of type info_t and   .
 *it contains a structure that contains inforamation related to the shell
 *
 *Description: function that gets a path provided and gets from it a command  .
 *
 *(path, the_path),  (i , z),  ( k, t)
 * Return: Nothing (void)
 */



void find_cmd(info_t *info)
{
	char *the_path  =  NULL;
	int z, t;


	info->path  =  info->argv[0];
	if (info->linecount_flag  ==  1)
	{
		info->line_count++;
		info->linecount_flag  =  0;
	}

	for (z  =  0, t  =  0; info->arg[z]; z++)
		if (!is_delim(info->arg[z], " \t\n"))
		{
			t++;
		}

	if (!t)
	{
		return;
	}

	the_path  =  find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (the_path)
	{
		info->path = the_path;
		fork_cmd(info);
	}

	else
	{
		if ((interactive(info)  ||  _getenv(info, "PATH=")
		|| info->argv[0][0] == '/')  &&  is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg)  !=  '\n')
		{
			info->status  =  100 + 27;
			print_error(info, "not found\n");
		}
	}
}


/**
 *fork_cmd -  function that  forks a child process
 *and executes a command using execve command.
 *@info:  It takes a pointer to the info struct as a parameter.
 *Return: Nothing (void)
 *
 *Description: function that  forks a child process .
 *
 *by
 */


void fork_cmd(info_t *info)
{
	pid_t the_child_pid  =  fork();


	if (the_child_pid  ==  -1)
	{
		perror("Error:");
		return;
	}



	if (the_child_pid  ==  0)
	{
		if (execve(info->path, info->argv, get_environ(info))  ==  -1)
		{
			free_info(info, 1);

			if (errno  ==  EACCES)
			{
				exit(126);
			}

			exit(1);
		}
	}


	wait(&(info->status));

	if (WIFEXITED(info->status))
	{
		info->status  =  WEXITSTATUS(info->status);

		if (info->status  ==  126)
		{
			print_error(info, "Permission denied\n");
		}
	}
}








