#include "sort.h"

/**
 * swap_values - swaps 2 values in an array of integrs
 * @array: the array of int
 * @i1: index of first elem
 * @i2: index of sec elem
 * Return: the array with value
 */
void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int temp;

	temp = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = temp;
}

/**
 * selection_sort - sorts the array of ints using the selection sort
 * @array: an array of integers
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (!(min = i))
		{
			swap_values(&array, min, i);
			print_array(array, size);
		}
	}
}
