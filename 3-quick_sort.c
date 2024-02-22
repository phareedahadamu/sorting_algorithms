#include "sort.h"
/**
 * partition_array - A function that partitions an array in order to sort it
 * using Lomuto partition scheme
 * @array: The array to be sorted
 * @lb: The lower base
 * @ub: THe upper base
 * @size: Number of elements in the array
 * Return: The position of the properly placed element
 */
int partition_array(int *array, int lb, int ub, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[ub];
	i = lb;
	for (j = lb; j < ub; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		tmp = array[i];
		array[i] = array[ub];
		array[ub] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * _sort - Sorts the partitioned array
 * @array: The array to be sorted
 * @lb: The lower base
 * @ub: THe upper base
 * @size: Number of elements in the array
 */
void _sort(int *array, int lb, int ub, size_t size)
{
	int pos;

	if (lb < ub)
	{
		pos = partition_array(array, lb, ub, size);
		_sort(array, lb, pos - 1, size);
		_sort(array, pos + 1, ub, size);
	}
}

/**
 * quick_sort - A function that
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	int lb = 0, ub = (int)size - 1;

	if (!array || size < 2)
		return;
	_sort(array, lb, ub, size);
}
