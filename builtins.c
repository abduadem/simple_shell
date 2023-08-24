#include "shell.h"

/**
 * is_builtin - checks if a command is a builtin command
 * @cmmd: the given command
 *
 * Return: the position of @cmmd in the builtins array, else -1
 */
t_builtin is_builtin(char *cmmd)
{
	t_builtin builtins[] = {
		{"exit", cmmd_exit},
		{"env", cmmd_env},
		{NULL, NULL}
	};

	int z;

	for (z = 0; builtins[z].cmmd; z++)
		if (_strcmp(builtins[z].cmmd, cmmd) == 0)
			return (builtins[z]);

	return (builtins[z]);
}

/**
 * check_builtins - If command is a builtin command
 * @cmmd: an array of command and its arguments
 *
 * Return: the appropriate function to be executed, else NULL
 */
int (*check_builtins(char **cmmd))(char **, int, char *)
{
	t_builtin b = is_builtin(cmmd[0]);

	if (b.cmmd)
		return (b.f);

	return (NULL);
}

/**
 * cmmd_env - builtin implementation of env command
 * @cmmd: Unused
 * @status: the status code
 * @fname: filename
 *
 * Return: Always 0
 */
int cmmd_env(char **cmmd, int status, char *fname)
{
	int z;

	(void) cmmd;
	(void) status;
	(void) fname;

	for (z = 0; environ[z]; z++)
	{
		_prints(environ[z]);
		_putchar('\n');
	}
	return (0);
}

/**
 * cmmd_exit - builtin Implementation of exit command
 * @cmmd: an array of given command and its arguments
 * @status: the status code
 * @fname: filename
 *
 * Return: exit with the status code given by user, or
 * previous execution status code
 */
int cmmd_exit(char **cmmd, int status, char *fname)
{
	int z = 0;

	if (!cmmd[1])
	{
		free_memory_pp(cmmd);
		exit(status);
	}

	while (cmmd[1][z])
	{
		if (_isalpha(cmmd[1][z]) && cmmd[1][z] != '-')
		{
			_prints(fname);
			_prints(": ");
			_prints(cmmd[0]);
			_prints(": ");
			_prints("Illegal number: ");
			_prints(cmmd[1]);
			_putchar('\n');
			return (1);
		}

		z++;
	}

	status = _atoi(cmmd[1]);
	free_memory_pp(cmmd);

	exit(status);
}


