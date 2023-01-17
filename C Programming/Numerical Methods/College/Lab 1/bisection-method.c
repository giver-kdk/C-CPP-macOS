#include <stdio.h>
#include <math.h>

#define f(x) (x*x - 4*x -9)
#define e 0.00001

int main()
{
    float x, x0, x1, error;
    here:
        printf("enter the two initial guesses: ");
        scanf("%f%f", &x0, &x1);
		// One value should be +ve and another -ve
        if(f(x0) * f(x1) > 0)
		{
			printf("invalid guess");
			goto here;
		}
    next:
        x = (x0 + x1) / 2;
        error = fabs((x1 - x0));
		// Assign "x" to "x0" is different sign
        if(f(x1) * f(x) < 0)
        {
            x0 = x;
        }
		// Assign "x" to "x1" is same sign
        else
        {
            x1 = x;
		}
		// "error" keeps decreasing.
        if(error > e)
        {
            goto next;
        }
		// Stop if less than "e"
        else
        {
            printf("required root is %f\n", x);
        }

}


