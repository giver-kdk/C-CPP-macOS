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
	scanf("%d", &n); // Use: 3
	printf("Enter the augmented matrix: ");
	/* Read Augmented Matrix */
	// Use:
	// 3, 2, 1, 10
	// 2, 3, 2, 14
	// 1, 2, 3, 14
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}
	/* Applying Gauss Elimination */
	for (i = 0; i < n - 1; i++)
	{
		if (a[i][i] == 0.0) // Diagonal "zero" condition
		{
			printf("Mathematical Error!");
			exit(0);
		}
		for (j = i + 1; j < n; j++)
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
	/* Do Backward Subsitution */
	// Find x, y and z value and put it in "x[]" array
	x[n - 1] = a[n - 1][n] / a[n - 1][n - 1]; // Assign "z" value on last place of "x[]" array
	// Solving the equation for "y" and "x"
	for (i = n - 2; i >= 0; i--)
	{
		x[i] = a[i][n];
		for (j = i + 1; j < n; j++)
		{
			x[i] = x[i] - a[i][j] * x[j];
		}
		x[i] = x[i] / a[i][i];
	}
	/* Display Solution */
	// Ans: 1, 2, 3
	printf("\nSolution is:\n");
	for (i = 0; i < n; i++)
	{
		printf("x[%d] = %0.3f\n", i, x[i]); // Print x, y and z stored in "x[]" array
	}
	return (0);
}
