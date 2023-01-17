#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (x*x + 2*x - 3)
#define g(x) (3 / (x + 2))
#define E 0.0001

int main()
{
	float x0, x1, error;
	here: 
	printf("Enter initial guess: ");
	scanf("%f", &x0);

	next: 
		x1 = g(x0);
		error = (x1 - x0) / x1;
		x0 = x1;
		if(error > E)
		{
			goto next;
		}
		else{
			printf("Approximate root is: %f", x1);
		}
}	