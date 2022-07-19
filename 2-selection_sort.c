#include "sort.h"

/**
* swap - swaps two values
* @array: array
* @n1: first number
* @n2: second number
*
* Return: void
*/
void swap(int **array, ssize_t n1, ssize_t n2)
{
	int temp;

	temp = (*array)[n1];
	(*array)[n1] = (*array)[n2];
	(*array)[n2] = temp;
}

/**
* selection_sort - sorts linked list using insertion sort
* @array: array
* @size: size of the array
*
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			swap(&array, min, i);
			print_array(array, size);
		}
	}
}
