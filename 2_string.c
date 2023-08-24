#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @destn: the destination string
 * @src: the source string
 *
 * Return: the result of concatenation
 */
char *_strcat(char *destn, const char *src)
{
	int destn_len, z = 0;

	destn_len = _strlen(destn);

	while (src[z])
		destn[destn_len++] = src[z++];
	destn[destn_len] = '\0';

	return (destn);
}
