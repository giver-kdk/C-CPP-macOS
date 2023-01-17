#include <stdio.h>
#define N 4

void pivoting(int a[10][10], int row, int col)
{
	int i, j, max = row;
	// float temp;
	int temp;
	for(i = row; i < N - 1; i++)
	{
		if(a[i + 1][col] > a[i][col])
		{
			max = i + 1;
		}
	}
	for (i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			temp = a[row][j];
			a[row][j] = a[max][j];
			a[max][j] = temp;

		}
	}
}
int main()
{
	int a[10][10] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}}, i, j;

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	pivoting(a, 0, 0);

	printf("\n");
	printf("\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

