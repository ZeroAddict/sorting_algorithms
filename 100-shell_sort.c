#include "sort.h"

/**
*swap - the positions of 2 elems in an array are swapped
*@item1: array element 1
*@item2: array element2
*@array: array to be sorted
* Return: void
*/

void swap(int *array, int item1, int item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}

/**
* shell_sort - function sorts an array in ascdng order by Shell sort
*algorithm following the Knuth sequence
*@array: array to be sorted
*@size: array size
* Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t j = 0;
	size_t idx = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (j = gap; j < size; j++)
		{
			for (idx = j; idx >= gap &&
			(array[idx] < array[idx - gap]); idx -= gap)
				swap(array, idx, idx - gap);
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
