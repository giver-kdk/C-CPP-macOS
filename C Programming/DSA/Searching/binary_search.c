#include <stdio.h>
#include <math.h>

int binary_search(int a[50], int l, int h, int key)
{
	int mid;
	if(l > h)
	{
		printf("\nSearch Failure");
		return -1;
	}
	mid = (l + h) /2;
	if(key > a[mid]) return binary_search(a, mid + 1, h, key);
	else if(key < a[mid]) return binary_search(a, l, mid - 1, key);
	else
	{
		printf("\nSearch Success");
		return (mid + 1);
	}
}

int main()
{
	int a[50], i, n, l, h, key, loc;
	printf("Enter value of n: ");
	scanf("%d", &n);
	l = 0;
	h = n - 1;
	printf("\nEnter array elemnets: ");
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("\nEnter the key: ");
	scanf("%d", &key);
	loc = binary_search(a, l, h, key);
	printf("\nRequired Location: %d\n", loc);
}