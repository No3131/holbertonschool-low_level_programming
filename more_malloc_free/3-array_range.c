
#include "main.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * array_range - Creates an array of integers
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: Pointer to the array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	size_t i, size;

	if (min > max)
		return (NULL);

	size = (size_t)((int64_t)max - (int64_t)min) + 1;
	if (size > (size_t)-1 / sizeof(int))
		return (NULL);

	array = malloc(size * sizeof(int));
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = (int)((int64_t)min + (int64_t)i);

	return (array);
}

