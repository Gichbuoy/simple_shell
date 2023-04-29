#include "shell.h"

/**
 * **strtow - functon that splits a string into words,
 * repeated delimiters are ignored
 * @str: the input string to split
 * @d: the delimeter string
 *
 * Return: a pointer to an array of strings,
 * NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, y, a, b, numwords = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	p = malloc((1 + numwords) * sizeof(char *));
	if (!p)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], d))
			x++;
		a = 0;
		while (!is_delim(str[x + a], d) && str[x + a])
			a++;
		p[y] = malloc((a + 1) * sizeof(char));
		if (!p[y])
		{
			for (a = 0; a < y; a++)
				free(p[a]);
			free(p);
			return (NULL);
		}
		for (b = 0; b < a; b++)
			p[y][b] = str[x++];
		p[y][b] = 0;
	}
	p[y] = NULL;
	return (p);
}

/**
 * **strtow2 - function that splits a string into words
 * @str: the input string
 * @d: the delimeter
 *
 * Return: a pointer to an array of strings,
 * NULL on error
 */
char **strtow2(char *str, char d)
{
	int x, y, a, b, numwords = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	p = malloc((1 + numwords) * sizeof(char *));
	if (!p)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		a = 0;
		while (str[x + a] != d && str[x + a] && str[x + a] != d)
			a++;
		p[y] = malloc((a + 1) * sizeof(char));
		if (!p[y])
		{
			for (a = 0; a < y; a++)
				free(p[a]);
			free(p);
			return (NULL);
		}
		for (b = 0; b < a; b++)
			p[y][b] = str[x++];
		p[y][b] = 0;
	}
	p[y] = NULL;
	return (p);
}
