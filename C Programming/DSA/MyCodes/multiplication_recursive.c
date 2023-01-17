#include <stdio.h>


int mul(int x, int y)
{
	if(y == 0)
	{
		return 0;
	}
	else
	{
		return x + mul(x, y - 1);
	}
}

int main()
{
	int x, y, result;
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	result = mul(x, y);
	printf("Product is: %d", result);
}