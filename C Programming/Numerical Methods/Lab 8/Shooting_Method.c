#include <stdio.h>

float f1(float x, float y, float z)
{
	return z;
}

float f2(float x, float y, float z)
{
	return (2 * y) + (72 * x) - (8 * x * x);
}
int main()
{
	int i;
	float m, xp, yp, zp, z, x1, x2, y1, y2, h, sy1, sy2, sz1, sz2, temp1, temp2, c[2], d[2];
	printf("Enter x1,y1,x2,y2: ");
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	printf("Enter h: ");
	scanf("%f",&h);
	temp1 = x1;
	temp2 = y1;

	for (i = 0; i < 2; i++)
	{
		printf("\nEnter z: ");
		scanf("%f",&z);
		d[i] = z;
		do
		{
			printf("\n%f\t%f\t%f", x1, y1, z);
			x1 = x1 + h;
			xp = x1 - h;					// Set Previous Value

			y1 = y1 + f1(xp, y1, z) * h;
			yp = y1 - f1(x1, y1, z) * h;	// Set Previous Value

			z = z + f2(xp, yp, z) * h;
			zp = z - f2(x1, y1, z) * h;	// Set Previous Value
		} while (x1 < x2);
		c[i] = y1;
		x1 = temp1;
		y1 = temp2;
	}
	// Linear Interpolation Formula
	z = d[1] - (((c[1] - y2) * (d[1] - d[0])) / (c[1] - c[0]));
	printf("\n");
	do
	{
		printf("\n%f\t%f\t%f", x1, y1, z);
		x1 = x1 + h;
		xp = x1 - h;

		y1 = y1 + f1(xp, y1, z) * h;
		yp = y1 - f1(x1, y1, z) * h;

		z = z + f2(xp, yp, z) * h;
		zp = z - f2(x1, y1, z) * h;
	} while (x1 < x2);
	return 0;
}
