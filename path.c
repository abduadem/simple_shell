#include "shell.h"

/**
 * path_build - build the path to a command
 * @tokkn: the given command
 * @value: the path to build for @tokkn
 *
 * Return: @value/@tokkn - the path of command
 */
char *path_build(char *tokkn, char *value)
{
	char *cmmd;
	size_t ln;

	ln = _strlen(value) + _strlen(tokkn) + 2;
	cmmd = malloc(sizeof(char) * ln);
	if (!cmmd)
		return (NULL);
	memset(cmmd, 0, ln);

	cmmd = _strcat(cmmd, value);
	cmmd = _strcat(cmmd, "/");
	cmmd = _strcat(cmmd, tokkn);

	return (cmmd);
}

/**
 * check_cmd_path - check if command is in path
 * @cmmd: an array of command strings
 *
 * Return: 0 if found, else 1
 */
int check_cmmd_path(char **cmmd)
{
	char *path, *value, *cmd_path;
	struct stat buff;

	path = _getenv("PATH");
	value = strtok(path, ":");
	while (value)
	{
		cmd_path = path_build(*cmmd, value);

		if (stat(cmd_path, &buff) == 0)
		{
			*cmmd = _strdup(cmd_path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}

	return (1);
}
