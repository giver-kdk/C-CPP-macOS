/*This program sorts the array elements in ascending order using insertion sorting(Clz)*/
#include <stdio.h>

void insertion_sort(int a[10], int n);
int main()
{
    int  n, i, a[10];
	printf("Enter value of n: ");
	scanf("%d", &n);
	printf("\nEnter %d elements in an array: ", n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\nBefore Sorting:\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
    insertion_sort(a, n);
    //Output
    printf("\nAfter Sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
	printf("\n");
	return 0;
}

void insertion_sort(int a[10], int n)
{
	int i, j, temp;
	for(i = 1; i < n; i++)
	{
		temp = a[i];
		j = i -  1;
		while(temp < a[j] && j >= 0)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = temp;
	}
}
