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
 * partition - splits the array around a pivot with left being less
 * @array: array to be pivoted
 * @first: index of first element in the partition
 * @last: index of last element in the partition
 * @size: size of the array
 *
 * Return: returns the index of pivot
 */
size_t partition(int *array, size_t first, size_t last, size_t size)
{
	unsigned int right_start, index;
	int pivot = array[last], set_right = 0;

	for (index = first; index < last; index++)
	{
		if (array[index] > pivot)
		{
		/*sets the right partition for the first value > pivot*/
			if (set_right == 0)
			{
				right_start = index;
				set_right = 1;
			}
		}
		else if (array[index] <= pivot && set_right == 1)
		{
			swap(&array[right_start], &array[index]);
			right_start++;
			print_array(array, size);
		}
	}
	if (set_right == 1)/*Atleast a value was bigger than pivot*/
	{
		swap(&array[right_start], &array[last]);
		print_array(array, size);
		return (right_start);
	}
	else/*pivot was the biggest value*/
		return (last);
}

/**
 * recur_quick_sort - implements recursion in the quick sort algorithm
 * @array: array being sorted
 * @first: first element of this partition
 * @last: last element of this partition
 * @size: actual size of array which woul be used when printing
 */
void recur_quick_sort(int *array, size_t first, size_t last, size_t size)
{
	size_t pivot;

	if (first == last)
		return;
	pivot = partition(array, first, last, size);
	/*sort left partition*/
	if (pivot != first)
		recur_quick_sort(array, first, pivot - 1, size);
	/*sort right partition*/
	if (pivot != last)
		recur_quick_sort(array, pivot + 1, last, size);
}

/**
 * quick_sort - implements quick sort to sort an array
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	recur_quick_sort(array, 0, size - 1, size);
}
