#include "shell.h"

/**
 * execute - execute user's parsed input
 * @cmmd: the command entered by user
 * @fname: Name of the shell program
 *
 * Return: void
 */
int execute(char **cmmd, char *fname)
{
	int status;
	pid_t pid;

	if (!*cmmd)
		exit(-1);

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(-1);
	}

	if (pid == 0)
	{
		if (strncmp(cmmd[0], "./", 2) && strncmp(cmmd[0], "/", 1))
			check_cmmd_path(cmmd);

		if (execve(cmmd[0], cmmd, environ) == -1)
		{
			perror(fname);
			free_memory_pp(cmmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}

