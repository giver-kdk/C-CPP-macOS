#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int n, i, a[50], b[50], x0;

	printf("Enter order of polynomial: ");
	scanf("%d", &n);
	printf("Enter co-efficients of polynomial: ");
	for(i = 0; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter point of evaluation: ");
	scanf("%d", &x0);
	b[n] = a[n];
	for(i = n - 1; i >= 0; i--)
	{
		b[i] = a[i] + b[i + 1] * x0;
	}
	printf("Funcitonal value is %d", b[0]);
}