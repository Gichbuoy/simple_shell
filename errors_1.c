#include "shell.h"

/**
 *_eputs - function that prints an input string
 * @string: the string tht is to be printed
 *
 * Return: Nothing
 */
void _eputs(char *string)
{
	int y = 0;

	if (!string)
		return;
	while (string[y] != '\0')
	{
		_eputchar(string[y]);
		y++;
	}
}

/**
 * _eputchar - function that writes the char d to stderr
 * @d: The character to written
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno  printed.
 */
int _eputchar(char d)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(2, buf, y);
		y = 0;
	}
	if (d != BUF_FLUSH)
		buf[y++] = d;
	return (1);
}

/**
 * _putfd - function that writes the character d to  fd
 * @d:  character to be printed
 * @fd:  filedescriptor to write to or modify if it already exists
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is returned.
 */
int _putfd(char d, int fd)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(fd, buf, y);
		y = 0;
	}
	if (d != BUF_FLUSH)
		buf[y++] = d;
	return (1);
}

/**
 *_putsfd -function that  prints  input string
 * @string: the string to  print
 * @fd:  file-descriptor to write,
 * or modify if it exists
 *
 * Return: the number of chars put
 */
int _putsfd(char *string, int fd)
{
	int y = 0;

	if (!string)
		return (0);
	while (*string)
	{
		y += _putfd(*string++, fd);
	}
	return (y);
}
