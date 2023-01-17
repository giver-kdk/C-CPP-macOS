#include <stdio.h>

int fibo(int num)
{
	if(num == 1) return 0;
	if(num == 2) return 1;

	return (fibo(num - 2) + fibo(num - 1));
}

int main()
{
	int i, n, result;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		printf("%d\t", fibo(i));
	}
	return 0;
}	