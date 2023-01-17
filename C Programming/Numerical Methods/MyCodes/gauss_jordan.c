#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	int i, j, k, n;
	float a[50][50], x[50] ,factor;

	printf("enter n: ");
	scanf("%d", &n);

	printf("Enter augmented matrix: ");
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n + 1; j++)
		{
			scanf("%f", &a[i][j]);
		}
	}

	// Gauss Jordan
	for(i = 0; i < n; i++)
	{
		if(a[i][i] == 0)
		{
			printf("error");
			exit(0);
		}
		for(j = 0; j < n; j++)
		{
			if(i != j)
			{
				factor = a[j][i] / a[i][i];
				for(k = 0; k < n + 1; k++)
				{
					a[j][k] = a[j][k] - factor * a[i][k];
				}
			}

		}
	}

	for(i = 0; i < n; i++)
	{
		x[i] = a[i][n] / a[i][i];
	}
}