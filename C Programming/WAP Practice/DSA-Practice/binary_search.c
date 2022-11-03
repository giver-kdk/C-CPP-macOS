#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5

int search(int a[], int l, int h, int key)
{
	int mid;
	if(l > h)
	{
		printf("Search Failure");
		return -1;
	}
	mid = (l + h) / 2;
	if(key > a[mid])
	{
		return search(a, mid + 1, h, key);
	}
	else if(key < a[mid])
	{
		return search(a, l, mid - 1, key);
	}
	else
	{
		printf("Search Success\n");
		return (mid + 1);
	}

}

int main()
{
	int a[SIZE], l, h, key, n, i, loc;
	printf("Enter the array elements in ascending order: \n");
	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &a[i]);
	}
	l = 0;
	h = SIZE - 1;
	printf("Enter the key to search: ");
	scanf("%d", &key);
	loc = search(a, l, h, key);
	printf("Required location of key: %d\n", loc);
	return 0;
}
