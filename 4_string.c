#include "shell.h"

/**
 * _strlen - finds the length of a string
 * @s: the given string
 *
 * Return: the length
 */
int _strlen(const char *s)
{
	int z = 0;

	if (!s)
		return (0);

	while (*s++)
		z++;

	return (z);
}

/**
 * _strstr - Implementation of the strstr function
 * @haystack: Just as the name suggests
 * @needle: the string to be searched for
 *
 * Return: a pointer to the first character of @needle
 * in @haystack if found, else NULL
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if ((*haystack == *needle) && cmp(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (NULL);
}
