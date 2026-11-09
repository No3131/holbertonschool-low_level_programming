
#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string in newly allocated memory
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);

	i = 0;
	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}

	return (copy);
}
