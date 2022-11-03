#include <stdio.h>

void merging(int a[10], int low, int mid, int high)
{
	int i, j, k, temp[10];
	i = low;
	j = mid + 1;
	k = low;
	while(i <= mid && j <= high)
	{
		if(a[i] < a[j])
			temp[k++] = a[i];		// Assign t "k"th index and increment "k"
		else 
			temp[k++] = a[j++];
	}

	while (i <= mid)
		temp[k++] = a[i++];

	while (j <= high)
		temp[k++] = a[j++];

	for (i = low; i <= high; i++)
		a[i] =temp[i];
}

void merge_sort(int a[10], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		merging(a, low, mid, high);
	}
	else
	{
		return;
	}
}

int main()
{
	int i, size, a[10];
	printf("Enter the size of array: ");
	scanf("%d", &size);
	printf("Enter %d elements: ", size);
	for(i = 0; i < size; i++)
		scanf("%d", &a[i]);
	printf("List before merge_sorting\n");
	for (i = 0; i <= size; i++)
		printf("%d ", a[i]);

	merge_sort(a, 0, size);
	printf("\nList after merge_sorting\n");
	for (i = 0; i <= size; i++)
		printf("%d ", a[i]);
}