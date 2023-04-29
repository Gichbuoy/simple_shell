#include "shell.h"

/**
 * _erratoi - function tht converts a string to an integer
 * @str:  string to be converted
 *
 * Return: 0 if no no in string,
 *	-1 on error
 *	-converted number if it works
 */
int _erratoi(char *str)
{
	int j = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;  /*   does this make main print 255? */
	for (j = 0;  str[j] != '\0'; j++)
	{
		if (str[j] >= '0' && str[j] <= '9')
		{
			result *= 10;
			result += (str[j] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - function that prints an error message on occurrence
 * @info:  parameter info struct
 * @est: string containing  error
 * Return: 0 if no numbers in string,
 *	-1 on error
 *	converted number if worked
 *
 */
void print_error(info_t *info, char *est)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(est);
}

/**
 * print_d - function that  prints  decimal number of base 10
 * @inp: input value
 * @fd: file-descriptor to write or modify
 *
 * Return: number of chars printed
 */
int print_d(int inp, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - function that converts a number from a string
 * @nm: the number to convert
 * @base:  the base
 * @flag: the argument flags
 *
 * Return: the converted string
 */
char *convert_number(long int nm, int base, int flag)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *pt;
	unsigned long m  = nm;

	if (!(flag & CONVERT_UNSIGNED) && nm < 0)
	{
		m = -nm;
		sign = '-';

	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buffer[49];
	*pt = '\0';

	do	{
		*--pt = arr[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
		*--pt = sign;
	return (pt);
}

/**
 * remove_comments - function that removes comments in shell
 * @buff: address of the string that will be modified
 *
 * Return: Always 0;
 */
void remove_comments(char *buff)
{
	int y;

	for (y = 0; buff[y] != '\0'; y++)
		if (buff[y] == '#' && (!y || buff[y - 1] == ' '))
		{
			buff[y] = '\0';
			break;
		}
}
