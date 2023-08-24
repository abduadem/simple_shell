#include "shell.h"

/**
 * main - The User Interface
 * @argc: Unused
 * @argv: an array of command line arguments passed to the command name
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int (*builtin)(char **, int, char *);
	char **tokkn;
	char *line;
	size_t ln = 0;
	ssize_t rd;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_prompt_init();

		rd = getline(&line, &ln, stdin);
		if (rd == -1)
			return (1);

		if (*line == '\n' || *line == '\0')
			continue;

		line = rm_nl(line);

		tokkn = input_parse(line);
		if (!tokkn || !tokkn[0])
			continue;

		builtin = check_builtins(tokkn);
		if (builtin)
		{
			status = builtin(tokkn, status, argv[0]);
			free_memory_pp(tokkn);
			continue;
		}
		else
			status = execute(tokkn, argv[0]);

		free_memory_pp(tokkn);
	}

	return (0);
}


