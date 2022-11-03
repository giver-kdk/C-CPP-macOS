#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int multiply(int a, int b)
{
	if(b == 0)
	{
		return 0;
	}
	else
	{
		return a + multiply(a, b - 1);
	}
}

int main()
{
	int a, b, result;
	printf("Enter value of a and b: ");
	scanf("%d%d", &a, &b);
	result = multiply(a, b);
	printf("Product of two numbers: %d\n", result);
}