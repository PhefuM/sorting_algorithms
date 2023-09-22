#include "sort.h"

/**
 * swap - swaps two integer values using pointers
 * @big: bigger integer valued to be swapped position
 * @small: smaller integer value to swap position with big
 */
void swap(int *big, int *small)
{
	int temp;

	temp = *big;
	*big = *small;
	*small = temp;
}

/**
 * selection_sort - implements selection sort to sort an array
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int *select_pos, *smallest_pos, smallest;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		select_pos = &array[i];
		smallest = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest_pos = &array[j];
				smallest = array[j];
			}
		}
		if (*select_pos != smallest)
		{
			swap(select_pos, smallest_pos);
			print_array(array, size);
		}
	}
}
