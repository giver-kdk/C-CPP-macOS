#include <stdio.h>
long int factorial(int N);

int main()
{
    int N;
	long int fact;
    printf("Enter positive integer N: ");
    scanf("%d", &N);
    fact = factorial(N);
    printf("Factorial of the number is %ld\n", fact);
}
long int factorial(int N)
{
	// Acts as condition to terminate recursion
    if (N == 0) return 1;
    else return N * factorial(N - 1);
}
