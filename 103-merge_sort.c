#include "sort.h"
#include <stdio.h>
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
	if (ptr == '\0')
		return ('\0');
	for (j = 0; j < (nmemb * size); j++)
		ptr[j] = '\0';
	return (ptr);
}
/**
 *merge - makes merge frm start to mid & mid to end
 *@arr: array from start to mid
 *@tmp: tmp array reduces the system calls
 *@start: first element idx
 *@mid: array in the middle
 *@end: last element index
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	/**
	*int *arr = array[] / 2
	*int end = sizeof((2 * arr) + 1 )/ 4;
	*int mid = (end + 1) / 2, start = 0;
	*/
	int size_right = end - mid, size_left = mid + 1 - start;
	int *array_right, *array_left;
	/* counters */
	int j, left, right = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = right = 0, j = start;
	/* merge tmp array into main arr*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[j] = array_left[left], left++;
		else
			arr[j] = array_right[right], right++;
		j++;
	}
	/* merge remaining left array into main array*/
	while (left < size_left)
		arr[j] = array_left[left], left++, j++;
	/* merge remaining right array into main array*/
	while (right < size_right)
		arr[j] = array_right[right], right++, j++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 *mergesort - function sorts an array of integers in
 *ascnding order using the Merge sort Algorithm
 *@array: an array of integers
 *@tmp: temp array used to reduce system calls
 *@start: 1st element index
 *@end: last element index
 *Return: void
 */
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((end + mid) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}
/**
 *merge_sort - function sorts an array of integers in asc.
 * order using the Merge sort algorithm
 *@size: size of the array
 *@array: an array of integers
 *Return: returns void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2 || !array)
		return;
	temp = _calloc(size, sizeof(int));
	mergesort(array, temp, 0, size - 1);
	free(temp);
}
