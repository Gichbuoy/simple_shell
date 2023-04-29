#include "shell.h"

/**
 * _myenv - function that prints the current shell environment
 * @info: Structure that has potential arguments.
 *
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - function that gets the value of an environment variable
 * @info: Structure tht has possible arguments
 * @nm: environent variable name
 *
 * Return: env variable value
 */
char *_getenv(info_t *info, const char *nm)
{
	list_t *node1 = info->env;
	char *q;

	while (node1)
	{
		q = starts_with(node1->str, nm);
		if (q && *q)
			return (q);
		node1 = node1->next;
	}
	return (NULL);
}

/**
 * _mysetenv - function that Initialize  new environment variable,
 * or modify existing ones
 * @info: Structure that has arguments
 *
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - function that Removes an environment variable
 * @info: Structure containing potential arguments.
 *
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int y;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= info->argc; y++)
		_unsetenv(info, info->argv[y]);

	return (0);
}

/**
 * populate_env_list -function that  populates environmnt linked list
 * @info: Structure that has  arguments
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t y;

	for (y = 0; environ[y]; y++)
		add_node_end(&node, environ[y], 0);
	info->env = node;
	return (0);
}
