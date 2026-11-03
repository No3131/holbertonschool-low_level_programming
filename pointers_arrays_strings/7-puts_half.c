#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: String to print
 *
 * Return: Nothing
 */
void puts_half(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
	{
		len++;
	}

	i = len / 2;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
