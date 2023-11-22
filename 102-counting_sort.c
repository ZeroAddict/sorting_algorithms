#include "sort.h"
#include <stdio.h>
/**
 *_calloc - calloc function impl
 *@nmemb: number of elements
 *@size: size in bits of each element
 *Return: ptr to memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int j = 0;

	if (nmemb == 0 || size == 0)
		return ('\0');
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return ('\0');
	for (j = 0; j < (nmemb * size); j++)
		ptr[j] = '\0';
	return (ptr);
}
/**
 * counting_sort - counting sort method implementation
 * @array: array to be sorted
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int idx, max = 0, *counter = '\0', *tmp = '\0';
	size_t j;

	if (array == NULL || size < 2)
		return;
	/* loop obtains max elem*/
	for (j = 0; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	counter = _calloc(max + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	/*obtain num of elements in array*/
	for (j = 0; j < size; j++)
		counter[array[j]]++;

	for (idx = 1; idx <= max; idx++)
		counter[idx] += counter[idx - 1];
	print_array(counter, max + 1);
	/* get the new calloc'ed array sorted */
	for (j = 0; j < size; ++j)
	{
		tmp[counter[array[j]] - 1] = array[j];
		counter[array[j]]--;
	}
	/* replace old array with sorted new array  */
	for (j = 0; j < size; j++)
		array[j] = tmp[j];
	free(tmp);
	free(counter);
}
