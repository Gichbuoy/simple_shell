#include "shell.h"

/**
 * _myexit - this is the main exits function
 * @info: Structure that has possible arguments.
 *
 *  Return: exits with  exit status
 *         (0) when info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If info arguement exists*/
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - function that changes current directory in shell,
 * using the cd command
 * @info: Structure that contains has possible arguments.
 *
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *z, *dr, buffer[1024];
	int chdir_ret;

	z = getcwd(buffer, 1024);
	if (!z)
		_puts("TODO: >>getcwd failure msg here<<\n");
	if (!info->argv[1])
	{
		dr = _getenv(info, "HOME=");
		if (!dr)
			chdir_ret = /*  return change directory */
				chdir((dr = _getenv(info, "PWD=")) ? dr : "/");
		else
			chdir_ret = chdir(dr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(z);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /*  return change directory */
			chdir((dr = _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - function that lists help in shell
 * @info: Structure tht has potential arguments, maintains
 * constant function prototype.
 *
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts(" Function not yet implemented \n");
	if (0)
		_puts(*arg_arr); /* print the argument array  */
	return (0);
}
