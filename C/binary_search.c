#include <stdio.h>
#include <stdlib.h>

size_t binary_search(int *arr, size_t size, int target)
{
	size_t left;
	size_t right;
	size_t mid;

	if (size == 0)
		return (-1);
	right = size - 1;
	left = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == target)
			return (mid);
		else if ((mid == 0 && target < arr[mid]) || (mid == size - 1 && target > arr[mid]))
			return (-1);
		else if (target < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

int	main(void)
{
	int 	arr[] = {1, 2, 4, 6, 8, 10, 20, 30, 50, 80, 100};
	int		targets[] = {80, 2, 1, 100, 200};
	size_t	size;
	size_t	index;
	size_t	size_targets;

	size = sizeof(arr) / sizeof(arr[0]);
	size_targets = sizeof(targets) / sizeof(targets[0]);
	for (size_t iterator = 0; iterator < size_targets; iterator++)
	{
		index = binary_search(arr, size, targets[iterator]);
		if (index == -1)
			printf("Element %d not found\n", targets[iterator]);
		else
			printf("Element %d found at index %zu\n", targets[iterator], index);
	}
	return (0);
}
