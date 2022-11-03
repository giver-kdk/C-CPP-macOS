/*This program sorts the array elements in ascending order using quick sorting(Clz)*/
#include <stdio.h>

void quick_sort(int a[10], int l, int h);
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
    quick_sort(a, 0, n - 1);
    //Output
    printf("\nAfter Sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
	printf("\n");
	return 0;
}

void quick_sort(int a[10], int l, int h)
{
	int pivot, p, q, temp;
	pivot = a[l];
	p = l;
	q = h;
	if(l >= h) return;
	while(p < q)
	{
		while(a[p] <= pivot && l < h)
		{p++;}
		while(a[q] > pivot)
		{q--;}
		if(p < q)
		{
			temp = a[p];
			a[p] = a[q];
			a[q] = temp;
		}
	}
	a[l] = a[q];
	a[q] = pivot;
	quick_sort(a, l, q - 1);
	quick_sort(a, q + 1, h);
}
