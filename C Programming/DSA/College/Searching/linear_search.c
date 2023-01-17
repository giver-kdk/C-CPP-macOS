#include <stdio.h>
void linear_search(int L[], int n, int key);

int main()
{
	int L[50], n, i, key;
	printf("How many elements: ");
	scanf("%d", &n);
	printf("\nEnter %d elements in the list: ", n);
	for (i = 0; i < n; i++)
		scanf("%d", &L[i]);
	printf("\nEnter search key: ");
	scanf("%d", &key);
	linear_search(L, n, key);
	return 0;
}

void linear_search(int L[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (key == L[i])
		{
			break;
		}
	}
	if (i == n)
		printf("\n Search Failure");
	else
		printf("\nSearch Success. Key %d is at location %d", key, i + 1);
}