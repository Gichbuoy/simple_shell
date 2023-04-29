#include "shell.h"

/**
 * is_cmd - function that determines if a file is an executable file
 * @info: the info struct containing arguments
 * @path: path to the file
 *
 * Return: 1 if true,
 *	0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - function that duplicates a set of characters
 * @pathstr: the PATH of string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[y++] = pathstr[x];
	buf[y] = 0;
	return (buf);
}

/**
 * find_path - function that finds a command in the PATH string
 * @info: the info struct containing arguments
 * @pathstr: the PATH of the string to find_path
 * @cmd: the command to find
 *
 * Return: command path
 *	NULL on error
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int t = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[t] || pathstr[t] == ':')
		{
			path = dup_chars(pathstr, curr_pos, t);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[t])
				break;
			curr_pos = t;
		}
		t++;
	}
	return (NULL);
}
