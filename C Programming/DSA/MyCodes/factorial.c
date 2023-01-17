#include <stdio.h>

int fact(int num)
{
	if(num == 1)
	{
		return 1;
	}
	else
	{
		return num * fact(num - 1);
	}
}

int main()
{
	int num, result;
	printf("Enter number to find factorial of: ");
	scanf("%d", &num);
	result = fact(num);
	printf("Factorial of %d is %d", num, result);
	return 0;
}	