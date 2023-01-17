#include <stdio.h>

int rev(int num, int temp)
{
	if(num == 0) return temp;
	temp = temp * 10 + (num % 10);
	return (rev((num / 10), temp));
}

int main()
{
	int reverse, n, result;
	printf("Enter the value of n: ");
	scanf("%d", &n);
	reverse = rev(n, 0);
	if(n == reverse)
	{
		printf("PALINDROME");
	}
	else
	{
		printf("NOT PALINDROME");
	}
	return 0;
}	