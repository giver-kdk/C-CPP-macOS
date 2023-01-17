#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x, y) (x + y)

int main()
{
	float x, y, m, p, h, m1, m2, m3, m4;

	printf("Enter initial guesses x0 and y0: ");
	scanf("%f%f", &x, &y);

	printf("Enter point of evaluation: ");
	scanf("%f", &p);

	printf("Enter step size: ");
	scanf("%f", &h);

	do
	{
		m1 = f(x, y);
		m2 = f(x + (h/2), y + m1*(h/2));
		m3 = f(x + (h/2), y + m2*(h/2));
		m4 = f(x + h, y + m3*h);
		m = (m1 + 2*m2 + 2*m3 + m4) / 6;
		x = x + h;
		y = y + m*h;
	}while(p > x);
	printf("The solution is %f", y);
}