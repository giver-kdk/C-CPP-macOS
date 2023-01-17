#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (x*x + 2*x - 3)
#define E 0.0001

int main()
{
	float x0, x1, x, error;
	here: 
	printf("Enter guesses x0 and x1: ");
	scanf("%f%f", &x0, &x1);
	if(f(x0) * f(x1) > 0)
	{
		printf("Invalid Guess");
		goto here;
	}
	next: 
	x = (x0 - (f(x0) * (x1 - x0)) / (f(x1) - f(x0)));
	error = fabs(f(x));
	if(error > E)
	{
		goto next;
	}
	else
	{
		printf("Approximate root is: %f", x);
	}

	return 0;
}