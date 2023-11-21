#include "sort.h"

/**
 * swap_values - swaps 2 values in an array of integers
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
 * bubble_sort - sorts an array of integers, uses bubble sort algorthm
 * @array: the array of integers
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t n = size;
	size_t new_idx, i;

	while (n > 1)
	{
		new_idx = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_values(&array, i, i + 1);
				print_array(array, size);
				new_idx = i + 1;
			}
		}
		n = new_idx;
	}
}
