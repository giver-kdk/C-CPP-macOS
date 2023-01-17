#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n, i, j, x[50], y[50], l[50], term, sum, p;

	printf("Enter the number of data points: ");
	scanf("%d", &n);

	printf("Enter the data points: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	printf("Enter point of evaluation: ");
	scanf("%d", &p);

	for(i = 0; i < n; i++)
	{
		term = 1;
		for(j = 0; j < n; j++)
		{
			if(i != j) 
			{
				term = term * ((p - x[j]) / (x[i] - x[j]));
			}
		}
		l[i] = term;
	}
	sum = 0;
	for(i = 0; i < n; i++)
	{
		sum = sum + (l[i] * y[i]);
	}
	printf("Interpolate value is: %d", sum);
}