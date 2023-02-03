#include <stdio.h>
#define f(x) (3*x*x*x + 2*x*x + x + 1)
#define E 0.001

int main()
{
	int n, i;
	float x0, a[10], b[10];
	printf("Enter order of polynomial: ");
	scanf("%d", &n)

	printf("enter point of evaluation: ");
	scanf("%f", &x0);
	printf("enter the co-efficients of polynomial: ");
	for(i = 0; i <= n; i++)
	{
		scanf("%f", a[i]);
	}
	b[n] = a[n];
	for(i = n - 1; i >= 0; i--)
	{
		b[i] = a[i] + b[i + 1]*x0;
	}
	printf("Functional Value is %f", x0);
}