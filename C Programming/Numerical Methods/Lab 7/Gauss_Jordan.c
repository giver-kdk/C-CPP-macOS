#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
	float a[SIZE][SIZE], x[SIZE], factor;
	int i, j, k, n;
	/* Read number of unknowns */
	printf("Enter number of unknowns: ");
	scanf("%d", &n);							//  Use: 3
	printf("Enter the augmented matrix: ");
	/* Read Augmented Matrix */
	// Use: 
	// 2, 4, -6, -8
	// 1, 3, 1, 10
	// 2, -4, -2, -12
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n + 1; j++)
		{
			scanf("%f", &a[i][j]);					
		}
	}
	/* Applying Gauss Jordan */
	for (i = 1; i <= n; i++)
	{
		if (a[i][i] == 0.0)
		{
			printf("Mathematical Error!");
			exit(0);
		}
		for (j = 1; j <= n; j++)
		{
			if(i != j)
			{
				factor = a[j][i] / a[i][i];

				for (k = 1; k <= n + 1; k++)
				{
					a[j][k] = a[j][k] - factor * a[i][k];
				}
			}
		}
	}
	/* Obtain Solution */
	for (i = 1; i <= n; i++)
	{
		x[i] = a[i][n + 1] / a[i][i];
	}
	/* Display Solution */
	// Ans: 1, 2, 3
	printf("\nSolution is:\n");
	for (i = 1; i <= n; i++)
	{
		printf("x[%d] = %0.3f\n", i, x[i]);
	}
	return (0);
}
