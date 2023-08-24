#include "shell.h"

/**
 * _strdup - duplicates a string
 * @s: the given string
 *
 * Return: a pointer to the duplicate
 */
char *_strdup(char *s)
{
	int size, z;
	char *destn;

	if (!s)
		return (NULL);

	size = _strlen(s) + 1;
	destn = malloc(size * sizeof(char));
	if (!destn)
		return (NULL);

	for (z = 0; z < size; z++)
		*(destn + z) = *(s + z);

	*(destn + z) = '\0';

	return (destn);
}


