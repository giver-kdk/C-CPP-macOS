#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f1(x, y, z) ((6 - 2*y - z) / 2)
#define f2(x, y, z) ((x + z))
#define f3(x, y, z) ((4 - 4*x - 2*y) / 3)
#define E 0.001


int main()
{
	int count = 0;
	float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3;

	printf("Iteration\tx\ty\tz\n");
	do
	{
		x1 = f1(x0, y0, z0);
		y1 = f2(x1, y0, z0);
		z1 = f3(x1, y1, z0);
		printf("%d\t%f\t%f\t%f", count, x1, y1, z1);

		e1 = fabs(x1 - x0);
		e2 = fabs(y1 - y0);
		e3 = fabs(z1 - z0);

		count++;

		x0 = x1;
		y0 = y1;
		z0 = z1;
	}while(e1 > E && e2 > E && e3 > E);

	printf("Solution is x: %f, y: %f and z: %f", x1, y1, z1);
}