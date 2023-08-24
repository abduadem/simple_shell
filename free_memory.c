#include "shell.h"

/**
 * memory_free_ptr - Free a pointer
 *
 * @ptr: Pointer to free
 **/
void memory_free_ptr(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp - Free a double pointer
 *
 * @ptr: Double pointer to free
 **/
void free_memory_pp(char **ptr)
{
	char **n;

	for (n = ptr; *n != NULL; n++)
		memory_free_ptr(*n);

	free(ptr);
}
