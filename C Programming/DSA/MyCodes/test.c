#include <stdio.h>




void merging(int a[], int l, int m, int h)
{
	int i = l, j = m + 1, k = l, temp[50];
	while(i <= m && j <= h)
	{
		if(a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while(i <= m)
	{
		temp[k++] = a[i++];
	}
	while(j <= h)
	{
		temp[k++] = a[j++];
	}
	for(i = l; i < k; i++)
	{
		a[i] = temp[i];
	}
}



void merge_sort(int a[], int l, int h)
{
	if(l < h)
	{
		int m = (l + h) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, h);
		merging(a, l, m, h);
	}
}

int main()
{
    int  n, i, a[50], l , h;
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
	l = 0;
	h = n - 1;
	merge_sort(a, l, h);

    //Output
    printf("\nAfter Sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
	printf("\n");
	return 0;
}

