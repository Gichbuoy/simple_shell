#include "shell.h"

/**
 **_strncpy - functions that copies a string
 *@desti:  destination of the string to copy
 *@srce: source string to be copied
 *@m: number of characters to be copied
 *
 *Return: the copied string
 */
char *_strncpy(char *desti, char *srce, int m)
{
	int l, k;
	char *s = desti;

	l = 0;
	while (srce[l] != '\0' && l < m - 1)
	{
		desti[l] = srce[l];
		l++;
	}
	if (l < m)
	{
		k = l;
		while (k < m)
		{
			desti[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - function that concatenates two strings
 *@dest: first string to concatenate
 *@src: second string to concatenate
 *@m: the no of bytes to be used
 *
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int l, k;
	char *s = dest;

	l = 0;
	k = 0;
	while (dest[l] != '\0')
		l++;
	while (src[k] != '\0' && k < m)
	{
		dest[l] = src[k];
		l++;
		k++;
	}
	if (k < m)
		dest[l] = '\0';
	return (s);
}

/**
 **_strchr - function that locates a character in a string
 *@str: the string  parsed
 *@d: character to be located
 *
 *Return:string pointer to memory area
 */
char *_strchr(char *str, char d)
{
	do {
		if (*str == d)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
