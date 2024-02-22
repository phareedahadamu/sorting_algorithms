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
	i = lb - 1;
	j = lb;
	while (j <= ub - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[ub];
	array[ub] = tmp;
	print_array(array, size);
	return (i + 1);
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
	int lb = 0, ub = (int)size;

	if (!array || size < 2)
		return;
	_sort(array, lb, ub, size);
}
