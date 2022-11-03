#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int num)
{
	if(num == 0)
	{
		return 0;
	}
	else
	{
		return num + sum(num - 1);
	}
}

int main()
{
	int num, result;
	printf("Enter value of N: ");
	scanf("%d", &num);
	result = sum(num);
	printf("Sum of natural number upto N is: %d\n", result);
}
