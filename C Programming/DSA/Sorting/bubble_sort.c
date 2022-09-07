/*This program sorts the array elements in ascending order using bubble sorting(Clz)*/
#include <stdio.h>

void bubble_sort(int a[], int n);
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
    bubble_sort(a, n);
    //Output
    printf("\nAfter Sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
	printf("\n");
	return 0;
}
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    //Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < (n - i) - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp; 
            }
        }
    }
}