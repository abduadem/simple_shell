#include "shell.h"

/**
 * _getenv - get the value of an environmental variable
 * @name: the variable name
 *
 * Return: the value of @name
 */
char *_getenv(const char *name)
{
	int z = 0, y = 0;

	while (environ[z])
	{
		while (environ[z][y] && *name)
		{
			if (environ[z][y] != *name || (environ[z][y] == '='))
				break;
			y++, name++;
		}

		if (environ[z][y] == '=' && !*name)
			return ((*(environ + z) + ++y));
		z++;
	}

	return (NULL);
}
