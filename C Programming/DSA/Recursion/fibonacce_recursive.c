#include <stdio.h>
int fibonacce(int num);

int main()
{
    int i, N;
    printf("Enter number of terms N for fibonacce series: ");
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
    {
        printf("%d\t", fibonacce(i));     //Repeatedly prints output according to 'i'.
    }
	printf("\n");
}
int fibonacce(int num)
{
    if(num == 1)
    	return 0;
    if(num == 2)
    	return 1;
    else
        return(fibonacce(num - 1) + fibonacce(num - 2)); //Recursion causing to return 'n'th term.                                                               
}