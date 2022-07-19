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
* bubble_sort - that sorts an array in ascending order using Bubble Sort
* @array: array
* @size: size of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t n = size, new, i;

	while (n > 1)
	{
		new = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array, i - 1, i);
				print_array(array, size);
				new = i;
			}
		}
		n = new;
	}
}
