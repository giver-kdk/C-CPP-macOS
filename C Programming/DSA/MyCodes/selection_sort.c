#include <stdio.h>

void selection_sort(int a[], int n);
int main()
{
    int  n, i, a[50];
	printf("Enter value of n: ");
	scanf("%d", &n);
	printf("\nEnter %d elemenet in an array: ", n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\nBefore Sorting: ");
	for(i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
    selection_sort(a, n);
    //Output
    printf("\nAfter Sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
	printf("\n");
	return 0;
}

void selection_sort(int a[], int n)
{
	int i, j, temp;
	for(i = 0; i < n - 1; i++)
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