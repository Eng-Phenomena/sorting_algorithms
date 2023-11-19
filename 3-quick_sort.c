#include "sort.h"

void swap_int(int *a, int *b);
void divide(int beg, int pivot, int *i, size_t size);
int partition(int beg, int pivot, int *i, size_t size);

/**
 * quick_sort - sorts an array of ints
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int st = 0, pi;

	if (array && size > 1)
	{
		pi = (size - 1);
		divide(st, pi, array, size);
	}
}

/**
* divide - recursively partition
* @st: beginning of divided array
* @pi: end of divided array
* @i: the beginning of the array
* @size: size of array
**/
void divide(int st, int pi, int *i, size_t size)
{
	int f, s, np;

	if (st < pi)
	{
		s = partition(st, pi, i, size);
		f = st;
		np = s - 1;
		if (f != np && s != pi)
			np--;
		divide(f, np, i, size);
		divide(s, pi, i, size);
	}
}

/**
* partition - divides an array
* @beg: beginning of array separated
* @pivot: end of array separated
* @i: beg of array
* @size: size of array
* Return: new start
**/
int partition(int beg, int pivot, int *i, size_t size)
{
	int tmp = beg;

	while (tmp != pivot)
	{
		if (i[tmp] < i[pivot])
		{
			if (tmp != beg)
			{
				swap_int(i + tmp, i + beg);
				print_array(i, size);
			}
			tmp++;
			beg++;
		}
		else
			tmp++;
	}
	if (beg != pivot)
	{
		if (i[beg] > i[pivot])
		{
			swap_int(i + pivot, i + beg);
			print_array(i, size);
		}
		beg++;
	}
	return (beg);
}

/**
  * swap_int - swaps the values of two integers
  * @a: int
  * @b: int
  */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
