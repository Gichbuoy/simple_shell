#include "shell.h"

/**
 * clear_info - function that initializes info_t struct and clears it
 * @info: the struct address
 *
 * Return: nothing
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - function that sets info_t struct
 * @info: is the struct address containing arguments
 * @av: the argument vector
 *
 * Return: nothing
 */
void set_info(info_t *info, char **av)
{
	int y = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (y = 0; info->argv && info->argv[y]; y++)
			;
		info->argc = y;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - function that frees info_t struct
 * @info: is struct address that has arguuments
 * @al: true if freeing all
 *
 * Return: nothing
 */
void free_info(info_t *info, int al)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (al)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
