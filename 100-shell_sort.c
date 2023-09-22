#include "sort.h"

/**
 * shell_sort - implements shell sort using Knuth sequence to sort an array
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t start_gap = 0;
	int temp, i, j, gap;

	if (size < 2)
		return;
	for (start_gap = 0; start_gap < size; start_gap = (start_gap * 3) + 1)
	{
		if (((start_gap * 3) + 1) > size)
			break;
	}
	for (gap = (int) start_gap; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int) size; i++)
		{
			temp = array[i];
			/*compare at intervals and enter loop if not in order*/
			for (j = i; (j - gap) >= 0 && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
