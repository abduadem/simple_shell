#include "shell.h"

/**
 * cmp - checks if a string in another
 * @a1: the string to be searched
 * @a2: the string being searched for
 *
 * Description: This is different from the _strcmp function
 * Return: 1 if found, else 0
 */
int cmp(const char *a1, const char *a2)
{
	while (*a1 && *a2)
		if (*a1++ != *a2++)
			return (0);

	return (*a2 == '\0');
}

/**
 * _isalpha - checks if a character is a letter
 * @c: the given character
 *
 * Return: TRUE if true, else FALSE
 */
int _isalpha(char c)
{
	if ((c >= 48) && (c <= 57))
		return (FALSE);

	return (TRUE);
}
