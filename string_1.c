#include "shell.h"

/**
 * _strlen - function that prints the length of a string
 * @r:  string whose length to be printed
 *
 * Return: int length of string
 */
int _strlen(char *r)
{
	int y = 0;

	if (!r)
		return (0);

	while (*r++)
		y++;
	return (y);
}
/**
 * starts_with - function that checks whether  needle begins with haystack
 * @haystack: string to be searched for
 * @needle: the substring to be sought
 *
 * Return: address of next character of haystack or NULL if otherwise
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - function that concatenates desti and srce
 * @desti: destination buffer to concatenate
 * @srce:  source buffer to concatenate
 *
 * Return: ptr to desti buffer
 */
char *_strcat(char *desti, char *srce)
{
	char *p = desti;

	while (*desti)
		desti++;
	while (*srce)
		*desti++ = *srce++;
	*desti = *srce;
	return (p);
}
/**
 * _strcmp -  function that compares of two strings.
 * @str1:  first string
 * @str2:  second string
 *
 * Return: negative if str1 < str2,
 *	positive if str1 > str2,
 *	zero if str1 == str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

