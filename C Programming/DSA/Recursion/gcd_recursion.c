#include <stdio.h>

int gcd(int x, int y);

int main()
{
	int x, y, result;
	printf("Enter the first number: ");
	scanf("%d", &x);
	printf("Enter the second number: ");
	scanf("%d", &y);

	result = gcd(x, y);
	printf("The GCD is: %d\n", result);
}
int gcd(int x, int y)
{
	if(y == 0) return x;
	else return (gcd(y, x % y));
}