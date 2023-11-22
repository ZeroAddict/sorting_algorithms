#ifndef SORT_H
#define SORT_H


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void *_calloc(unsigned int nmemb, unsigned int size);
void merge(int *arr, int *tmp, int start, int mid, int end);
void mergesort(int *array, int *tmp, int start, int end);
void _quick_sort(int *array, ssize_t lo, ssize_t hi, size_t size);
void swap(int *array, int item1, int item2);
void swap_values(int **array, ssize_t i1, ssize_t i2);
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif
