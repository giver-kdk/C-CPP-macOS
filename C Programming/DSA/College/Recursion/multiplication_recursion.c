#include <stdio.h>
long int product(int x, int y);

int main()
{
    int x, y;
	long int p;
    printf("Enter positive integer x and y: ");
    scanf("%d%d", &x, &y);
    p = product(x, y);
    printf("The product of two numbers is %ld\n", p);
}
long int product(int x, int y)
{
	//Acts as condition to terminate recursion
    if(y == 0) return 0;
    else return (x + product(x, y-1));     
}