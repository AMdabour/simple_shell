#include "shell.h"


/**
 *is_chain - Determines the type of command chaining .
 * .
 *
 * @my_info: a Pointer to the info_t structure .
 * @mybuffer:  a Pointer to the buffer containing the command .
 * @myindex:    a Pointer to the index in the buffer .
 *
 *Description: Determines the type of command chaining based on the characters
 *in its buffer .
 *
 * Return: It have two options : 1 if command chaining is identified, 0 IF not.
 */



int is_chain(info_t *my_info, char *mybuffer, size_t *myindex)
{
	size_t position  =  *myindex;


	if (mybuffer[position]  ==  '|' && mybuffer[position + 1]  ==  '|')
	{
		mybuffer[position]  =  '\0';
		position++;
		my_info->command_buffer_type  =  CMD_OR;
	}

	else if (mybuffer[position]  ==  '&' && mybuffer[position + 1]  == '&')
	{
		mybuffer[position]  =  '\0';
		position++;
		my_info->command_buffer_type  =  CMD_AND;
	}

	else if (mybuffer[position]  ==  ';') /* Found end of this command */
	{
		mybuffer[position]  =  '\0';
		my_info->command_buffer_type  =  CMD_CHAIN;
	}

	else
	{
		return (0);
	}

	*myindex  =  position;
	return (1);	/* there are no Command chaining identified */
}


/**
 *check_chain - Checks the command chain status
 *and modifies the buffer if necessary.
 *
 * @myinfo: the P to the info_.
 * @mybuf:  the P to the buffer containing the command.
 * @myp:    the P to the index in the buffer.
 *
 * @z:      the now index position.
 * @l:  the length of  buffer.
 *Return: void ( Nothing) .
 */

void check_chain(info_t *myinfo, char *mybuf, size_t *myp, size_t z, size_t l)
{
	size_t j = *myp;

	if (myinfo->command_buffer_type == CMD_AND)
	{
		if (myinfo->status)
		{
			mybuf[z] = '\0';
			j = l;
		}
	}

	else if (myinfo->command_buffer_type == CMD_OR)
	{
		if (!myinfo->status)
		{
			mybuf[z] = '\0';
			j = l;
		}
	}

	*myp = j;
}
