#include "shell.h"

/**
 * _atoi - convert a string to an integer.
 * @s: the string to be converted.
 *
 * Return: int.
 */
int _atoi(char *s)
{
	int ln, z = 0, FLAG = 0, d = 0, n = 0, dgt;

	for (ln = 0; s[ln] != '\0'; ln++)
		;

	while (z < ln && FLAG == 0)
	{
		if (s[z] == '-')
			++d;

		if (s[z] >= 48 && s[z] <= 57)
		{
			dgt = s[z] - '0';
			if (d % 2)
				dgt = -dgt;
			n = n * 10 + dgt;
			FLAG = 1;
			if (s[z + 1] < 48 || s[z + 1] > 57)
				break;
			FLAG = 0;
		}
		z++;
	}
	if (FLAG == 0)
		return (0);

	return (n);
}
