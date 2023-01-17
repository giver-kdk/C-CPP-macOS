#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f1(x, y, z) (z)
#define f2(x, y, z) (2 * y + 72 * x - 8 * x * x)

int main()
{
	float x1, y1, x2, y2, h, temp1, temp2, z, xp, yp, zp;

	printf("Enter x1, y1, x2, y2: ");
	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

	printf("Enter value of h: ");
	scanf("%f", &h);
	temp1 = x1;
	temp2 = y1;

	for (i = 0; i < 2; i++)
	{
		printf("Enter z: ");
		scanf("%f", &z);
		d[i] = z;
		do
		{
			printf("%f\t%f\t%f\n", x1, y1, z);
			x1 = x1 + h;
			xp = x1 - h;

			y1 = y1 + f1(xp, y1, z);
			yp = y1 - f1(xp, y1, z);

			z = z + f2(xp, yp, z);
		} while (x1 < x2);
		c[i] = y1;
		x1 = temp1;
		y1 = temp;
	}
	z = d[1] - ((c[1] - y2) * (d[1] - d[0])) / (c[1] - c[0]);
	do
	{
		printf("%f\t%f\t%f\n", x1, y1, z);
		x1 = x1 + h;
		xp = x1 - h;

		y1 = y1 + f1(xp, y1, z);
		yp = y1 - f1(xp, y1, z);

		z = z + f2(xp, yp, z);
	} while (x1 < x2);
	return 0;
}