#include "shell.h"

/**
 * interactive - function that prints true if shell is in interactive mode
 * @info: the struct address containing arguments
 *
 * Return: 1 if interactive mode,
 * 0 if opposite
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function that checks if a character is a delimeter
 * @c:  char to checked
 * @delim:  delimeter string
 * Return: 1 if true, 0 if opposite
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function that looks for alphabetic character
 *@c: character to input
 *Return: 1 if d is alphabetic, 0 opposite
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function tht converts  string to  integer
 *@z: string to be converted
 *Return: 0 if no is still string, converted number otherwise
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
