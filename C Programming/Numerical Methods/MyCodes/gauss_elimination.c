#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int i, j, k, n;
	float a[50][50], x[50], factor;

	printf("Enter n: ");
	scanf("%d", &n);

	printf("Enter augmented matrix: ");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n + 1; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}

	// Gauss Elimination
	for(i = 0; i < n - 1; i++)
	{
		if(a[i][i] == 0)
		{
			printf("error");
			exit(0);
		}
		for(j = i + 1; j < n; j++)
		{
			factor = a[j][i] / a[i][i];
			for(k = 0; k < n + 1; k++)
			{
				a[j][k] = a[j][k] - factor * a[i][k];
			}
		}
	}

	x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];


	for(i = n - 2; i >= 0; i--)
	{
		x[i] = a[i][n];
		for(j = i + 1; j < n; j++)
		{
			x[i] = x[i] - a[i][j] * x[j];
		}
		x[i] = x[i] / a[i][i];
	}

	printf("\nSolution is:\n");

	return 0;
}