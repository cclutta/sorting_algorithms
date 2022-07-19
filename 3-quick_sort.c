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
 * partition - selects a pivot point in the array
 *
 * @array: the array to sort
 * @lo: the lowest index of the partition to sort
 * @hi: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] < array[i])
	{
		swap(&array, i, hi);
		print_array(array, size);
	}

	return (i);
}

/**
 * sort - partitions the array, then sorts each partition
 *
 * @array: the array to sort
 * @lo: the lowest index of the partition to sort
 * @hi: the highest index of the partition to sort
 * @size: size of the array
 */

void sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		sort(array, lo, pivot - 1, size);
		sort(array, pivot + 1, hi, size);
	}
}

/**
* quick_sort - sorts an array of integers in ascending the Quick sort algorithm
* @array: array
* @size: size of the array
*
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	ssize_t l = 0;
	ssize_t h = (size - 1);

	if (!array || size < 2)
		return;

	sort(array, l, h, size);
}
