#include "shell.h"

/**
 * _strcpy - function that copies a string
 * @dest: the destination of copied string
 * @src: the source of string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int y = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[y])
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = 0;
	return (dest);
}

/**
 * _strdup - function that duplicates a given string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - function that prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_putchar(str[y]);
		y++;
	}
}

/**
 * _putchar - function that writes the character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 *	On error, -1, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}
