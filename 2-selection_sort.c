#include "sort.h"
/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, n = size, tmp;

	if (!array || n < 2)
		return;
	for (i = 0; i < (n - 1); i++)
	{
		min = i;
		for (j = 1 + i; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
