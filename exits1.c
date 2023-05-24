#include "shell.c"

/**
 * _strncat - function that Concatenates two strings.
 *
 * @DEST: ptr to The first string.
 * @SRC: ptr to The second string.
 * @N: It's and integer that storesThe amount of bytes to be maximally use .
 *
 * Return: (char )The concatenated string.
 */


char *_strncat(char *DEST, char *SRC, int N)
{
	int I, J;
	char *S = DEST;

	I = 0;
	J = 0;

	while (DEST[I] != '\0')
	{
		I++;
	}

	while (SRC[J] != '\0' && J < N)
	{
		DEST[I] = SRC[J];
		I++;
		J++;
	}

	if (J < N)
	{
		DEST[I] = '\0';
	}

	return (S);
}


/**
 * _strncpy - function that Copies a string.
 *
 * @DEST: ptr to The destination string to be copied to.
 * @SRC: ptr to The source string.
 *
 * @N: integer :The amount of characters to be copied.
 *
 * Return: The string that was concatenated .
 */
char *_strncpy(char *DEST, char *SRC, int N)
{
	int I, J;
	char *S = DEST;

	I = 0;
	while (SRC[I]  !=  '\0' && I < N - 1)
	{
		DEST[I]  =  SRC[I];
		I++;
	}
	if (I < N)
	{
		J  =  I;
		while (J < N)
		{
			DEST[J]  =  '\0';
			J++;
		}
	}
	return (S);
}



