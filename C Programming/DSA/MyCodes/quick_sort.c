#include <stdio.h>


void quick_sort(int a[], int l, int h)
{
	int pivot = a[l], p = l, q = h;
	if(l >= h) return;
	while(p < q)
	{
		while(a[p] <= pivot && l < h)
		{
			p++;
		}
		while(a[q] > pivot && l < h)
		{
			q--;
		}
		if(p < q)
		{
			int temp = a[p];
			a[p] = a[q];
			a[q] = temp;
		}
	}
	a[l] = a[q];
	a[q] = pivot;
	quick_sort(a, l, q - 1);
	quick_sort(a, q + 1, h);
}

int main()
{
    int  n, i, a[50], l, h;
	printf("Enter value of n: ");
	scanf("%d", &n);
	printf("\nEnter %d elemenet in an array: ", n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	l = 0;
	h = n - 1;
	printf("\nBefore Sorting: ");
	for(i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
    quick_sort(a, l, h);
    //Output
    printf("\nAfter Sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
	printf("\n");
	return 0;
}

