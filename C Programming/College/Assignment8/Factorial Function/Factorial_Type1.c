#include <stdio.h>

/*Factorial function with no return type and with no argument.*/

void find_factorial();

int main()
{
    find_factorial();
}
void find_factorial()
{
    int num, factorial=1;
    printf("Enter any number: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++)
    {
        factorial= factorial* i;
    }
    printf("The factorial of %d is %d", num, factorial);
}