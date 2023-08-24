#include "shell.h"

/**
 * _strcpy - copies the content of a string to another
 * @destn: the destination string
 * @src: the source of the contents to be copied
 *
 * Return: @dest
 */
char *_strcpy(char *destn, const char *src)
{
	char *n = destn;

	while (*src)
		*n++ = *src++;

	*n = '\0';

	return (destn);
}

/**
 * _strcmp - Compares two strings
 * @a1: the first string
 * @a2: the second string
 *
 * Return: 0 if equal, -ve if @a1 < @a2, else +ve
 */
int _strcmp(char *a1, char *a2)
{
	int a;

	for (a = 0; a1[a]; a++)
		if (a1[a] != a2[a])
			return (a1[a] - a2[a]);

	return (0);
}



