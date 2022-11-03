#include <stdio.h>
#include <math.h>

void selection_sort(int a[], int n)
{
	int i, j, temp;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int array[10], num, i;
	printf("Enter the size of array: ");
	scanf("%d", &num);

	printf("Enter the elements of array: \n");
	for(i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("Array before sorting is: \n");
	for(i = 0; i < num; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
	selection_sort(array, num);
	printf("Array after sorting is: \n");
	for(i = 0; i < num; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}