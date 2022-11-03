#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int x, int y)
{
	if(y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}
}

int main()
{
	int x, y, result;
	printf("Enter two number to find gcd: ");
	scanf("%d%d", &x, &y);
	result = gcd(x, y);
	printf("GCD of two numbers is: %d\n", result);
}
