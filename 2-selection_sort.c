#include "sort.h"
void swap_int(int *a, int *b);
/**
* selection_sort - a function that sorts an array of integers in ascending
* order using the selection sort algorithm
* @array: array of integers
* @size: size of array
**/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *tmp = NULL, z;

	for (i = 0; array && i < size - 1; i++)
	{
		tmp = NULL;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				if (tmp && array[j] < *tmp)
					tmp = &array[j];
				if (!tmp)
					tmp = &array[j];
			}
		}
		if (tmp)
		{
			z = *tmp;
			*tmp = array[i];
			array[i] = z;
			print_array(array, size);
		}
	}
}
