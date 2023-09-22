#include "sort.h"

/**
 * swap - swaps two integer values using pointers
 * @big: bigger integer vlued to be swapped position
 * @small: smaller intger value to swap position with big
 */
void swap(int *big, int *small)
{
	int temp;

	temp = *big;
	big = *small;
	small = temp;
}

/**
 * bubble_sort - sorts an array of integers using bubble sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, swapped;

	if (size < 2)
		return;
	for (i = 0; i < size - 1, i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
