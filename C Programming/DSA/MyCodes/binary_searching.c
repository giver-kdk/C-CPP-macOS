#include <stdio.h>
#include <stdlib.h>


int binary_search(int a[], int l, int h, int key)
{
	if(l > h)
	{
		printf("Search Failure");
		return -1;
	}
	int mid = (l + h) / 2;
	if(key > a[mid])
	{
		// Don't forget to "return" here
		return binary_search(a, mid + 1, h, key);
	}
	else if(key < a[mid])
	{
		// Don't forget to "return" here
		return binary_search(a, l, mid - 1, key);
	}
	else
	{
		printf("Search Successfull");
		return (mid + 1);
	}
}

int main()
{
	int a[50], n, l, h, i, key, location;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	l = 0;
	h = n - 1;
	printf("Enter the array elements in ascending order: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the key to search: ");
	scanf("%d", &key);
	location = binary_search(a, l, h, key);
	printf("Required Location is: %d", location);
	return 0;
}