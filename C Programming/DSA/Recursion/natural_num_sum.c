#include <stdio.h>
long int sum(int N);

int main()
{
    int N;
	long int s;
    printf("Enter positive integer N: ");
    scanf("%d", &N);
    s = sum(N);
    printf("The sum of natural numbers is %ld\n", s);
}
long int sum(int N)
{
    if(N == 0)                         //Acts as condition to terminate recursion
		return 0;
    else
        return (N + sum(N-1));     
}