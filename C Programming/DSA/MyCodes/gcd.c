#include <stdio.h>


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
	printf("Enter 1st number: ");
	scanf("%d", &x);
	printf("Enter 2nd number: ");
	scanf("%d", &y);
	result = gcd(x, y);
	printf("GCD is: %d", result);
}