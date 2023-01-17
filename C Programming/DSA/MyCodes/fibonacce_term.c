#include <stdio.h>

int fibo(int num)
{
	if(num == 1) return 0;
	if(num == 2) return 1;

	return (fibo(num - 2) + fibo(num - 1));
}

int main()
{
	int n, result;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	result = fibo(n);
	printf("%d", result);
	return 0;
}	