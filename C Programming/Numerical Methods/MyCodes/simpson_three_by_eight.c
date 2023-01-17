#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (1 / (sqrt(1 + x*x)))

int main()
{
	int i, n;
	float a, b, h, IV, x[50], y[50];

	printf("Enter the lower limit: ");
	scanf("%f", &a);
	printf("Enter upper limit: ");
	scanf("%f", &b);
	printf("Enter number of segment: ");
	scanf("%d", &n);

	h = (b - a) / n;
	for(i = 0; i <= n; i++)
	{
		x[i] = a + i*h;
		y[i] = f(x[i]);
	}

	IV = y[0] + y[n];
	for(i = 1; i < n; i++)
	{
		if(i % 3 == 0)
		{
			IV = IV + 2*y[i];
		}
		else
		{
			IV = IV + 3*y[i];
		}
	}
	IV = (3*h) / 8;
	printf("The integral value is: %f", IV);
}