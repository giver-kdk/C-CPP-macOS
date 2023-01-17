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
	for (i = 0; i < n; i++)					// Matrix "row" and "column" starts from 1
	{
		for (j = 0; j < n + 1; j++)
		{
			scanf("%f", &a[i][j]);					
		}
	}
	/* Applying Gauss Jordan */
	for (i = 0; i < n; i++)
	{
		if (a[i][i] == 0.0)						// Diagonal "zero" condition
		{
			printf("Mathematical Error!");
			exit(0);
		}
		for (j = 0; j < n; j++)
		{
			if(i != j)
			{
				// The factor number that results "0" when multiplied and subtracted with pivot element
				factor = a[j][i] / a[i][i];
				// Make "0" below pivot element
				for (k = 0; k < n + 1; k++)
				{
					a[j][k] = a[j][k] - factor * a[i][k];
				}
			}
		}
	}
	/* Obtain Solution by dividing last "column" with "pivot" which is equivalent to reduced echelon */
	for (i = 0; i < n; i++)
	{
		x[i] = a[i][n] / a[i][i];
	}
	/* Display Solution */
	// Ans: 1, 2, 3
	printf("\nSolution is:\n");
	for (i = 0; i < n; i++)
	{
		printf("x[%d] = %0.3f\n", i, x[i]);
	}
	return (0);
}
