#include "shell.h"

/**
 * interactive - function that checks if shell is in interactive mode or not
 * @info: the struct address containing arguments
 *
 * Return: 1 if shell is in interactive mode,
 *	0 if shell is not interactive
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function that checks if char is a delimeter
 * @c:  character to check
 * @delim:  this is the delimeter string
 *
 * Return: 1 if @c is a delim,
 *	0 if @c is not a delim
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function that looks for alphabetic characters in shell
 *@c: character to look for
 *
 *Return: 1 if @c is alphabetic,
 *	0 if @c is not alphabetic
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - this is a function that converts a string to an int
 *@z: string to be converted
 *Return: 0 if no is still string,
 *othewise return the converted number
 */

int _atoi(char *z)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  z[i] != '\0' && flag != 2; i++)
	{
		if (z[i] == '-')
			sign *= -1;

		if (z[i] >= '0' && z[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (z[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
