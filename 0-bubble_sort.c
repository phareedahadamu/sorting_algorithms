#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: An array of integers
 * @size: The number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, n = size;
	int tmp;

	if (array != NULL)
	{
		for (i = 0; i < (size - 1); i++)
		{
			for (j = 0; j < (n - 1); j++)
			{
				if (array[j] > array[j + 1])
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
					print_array(array, size);
				}
			}
			n--;
		}
	}
}
