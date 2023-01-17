#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x, y) (x + y)

int main()
{
	float x, y, m, p, h;

	printf("Enter initial guesses x0 and y0: ");
	scanf("%f%f", &x, &y);

	printf("Enter point of evaluation: ");
	scanf("%f", &p);

	printf("Enter step size: ");
	scanf("%f", &h);

	do
	{
		m = f(x, y);
		x = x + h;
		y = y + m*h;
	}while(p > x);
	printf("The solution is %f", y);
}