#include "sort.h"

/**
 * swap_values - swaps 2 values in an array of ints
 * @array: the array of integers
 * @i1: index of first value
 * @i2: index of 2nd value
 * Return: the array value
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int tmp = (*array)[i1];

	(*array)[i1] = (*array)[i2];
	(*array)[i2] = tmp;
}

/**
 * partition - selects a pivot (piv) point in the array
 * @array: the array to be sorted
 * @lo: lowest index of the partition of interest
 * @hi: highest index of the partition to sort
 * @size: size of the array
 * Return: idx of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int piv;
	ssize_t i, j;

	piv = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < piv)
		{
			if (i != j)
			{
				swap_values(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] < array[i])
	{
		swap_values(&array, i, hi);
		print_array(array, size);
	}
	return (i);
}

/**
 * _quick_sort - partitions the array, then sorts the partitions
 * @array: array to be sorted
 * @lo: lowest index of the partition for sorting
 * @hi: highest index of the partition for sorting
 * @size: array size
 */

void _quick_sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t piv;

	if (lo < hi)
	{
		piv = partition(array, lo, hi, size);
		_quick_sort(array, lo, piv - 1, size);
		_quick_sort(array, piv + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers using quicksort
 * @array: an array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	ssize_t low = 0;
	ssize_t hi = (size - 1);

	if (!array || size < 2)
		return;
	_quick_sort(array, low, hi, size);
}
