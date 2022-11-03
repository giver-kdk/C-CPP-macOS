#include <stdio.h>
#define SIZE 20

int main()
{
	int i, j;
	for(i = 0; i <= SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(j == 1 || j == SIZE - 1) printf("*\t");
			else if(i < SIZE / 2)
			{
				if(j == i + 1) printf("*\t");
				else printf("\t");
			}
			else if(i == SIZE / 2)
			{
				if(i == j) printf("*\t");
				else printf("\t");
			}
			else if(i > SIZE / 2)
			{
				if(j == i - 1) printf("*\t");
				else printf("\t");
			}
		}
		printf("\n\n");
	}
}
