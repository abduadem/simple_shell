#include "shell.h"

/**
 * _prompt_init - initialize prompt
 *
 * Return: void
 */
void _prompt_init(void)
{
	int x1, y1, z1;
	char *u, *n, *t = "# ";
	char *prompt = NULL;

	u = _getenv("USER");
	n = _getenv("NAME");

	x1 = _strlen(u);
	y1 = _strlen(n);
	z1 = _strlen(t);

	prompt = malloc(x1 + y1 + z1 + 1);
	if (!u || !n || !prompt)
	{
		_prints("#cisfun$ ");
		return;
	}

	prompt = _strcpy(prompt, u);
	prompt = _strcat(prompt, "@");
	prompt = _strcat(prompt, n);
	prompt = _strcat(prompt, t);

	_prints(prompt);

	free(prompt);
}
