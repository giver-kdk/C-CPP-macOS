#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x, y) (x + y)

int main()
{
	float x, y, m, p, h, m1, m2, ye;

	printf("Enter initial guesses x0 and y0: ");
	scanf("%f%f", &x, &y);

	printf("Enter point of evaluation: ");
	scanf("%f", &p);

	printf("Enter step size: ");
	scanf("%f", &h);

	do
	{
		m1 =  f(x, y);
		ye = y + m1*h;
		x = x + h;
		m2 = f(x, ye);
		m = (m1 + m2) / 2;
		y = y + m*h;
	}while(p > x);
	printf("The solution is %f", y);
}