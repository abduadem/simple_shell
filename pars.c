#include "shell.h"

/**
 * rm_nl - Removes the new line from User's input
 * @line: the line inputted by user
 *
 * Return: input without newline
 */
char *rm_nl(char *line)
{
	char *n = line;

	n = strtok(n, "\n");
	return (n);
}

/**
 * parse_input - parses the line entered by the user
 * @line: the given input
 *
 * Return: an array of tokkn present in @line
 */
char **input_parse(char *line)
{
	char **tokkn;
	char *tok, *n;
	int z;

	if (!line)
		return (NULL);

	tokkn = malloc(sizeof(char *) * _strlen(line));
	if (!tokkn)
	{
		perror("Gsh");
		return (NULL);
	}

	line = rm_nl(line);

	n = _strdup(line);
	tok = strtok(n, " ");
	for (z = 0; tok; z++)
	{
		tokkn[z] = _strdup(tok);
		tok = strtok(NULL, " ");
	}
	tokkn[z] = NULL;

	free(n);

	return (tokkn);
}
