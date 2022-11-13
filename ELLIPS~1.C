#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int x, y, rx, ry, xk, yk, pk;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\bgi");

	printf("Enter x and y coordinates: ");
	scanf("%d %d", &x, &y);
	printf("Enter x-radius and y-radius of circle: ");
	scanf("%d %d", &rx, &ry);

	xk = 0;
	yk = ry;
	pk = ry * ry + -(rx * rx) * ry + (rx * rx) / 4;
	while ((2 * xk * ry * ry) < (2 * yk * rx * rx))
	{
		if (pk < 0)
		{

			xk = xk + 1;
			pk = pk + (2 * ry * ry * xk) + (ry * ry);
		}
		else if (pk >= 0)
		{
			xk = xk + 1;
			yk = yk - 1;
			pk = pk + (2 * ry * ry * xk) - (2 * rx * rx * yk) + (ry * ry);
		}
		putpixel(x + xk, y + yk, 4);
		putpixel(x + yk, y + xk, 4);
		putpixel(x - yk, y + xk, 4);
		// putpixel(x - xk, y + yk, 4);
		putpixel(x - xk, y - yk, 4);
		// putpixel(x - yk, y - xk, 4);
		// putpixel(x + yk, y - xk, 4);
		// putpixel(x + xk, y - yk, 4);
	}
	pk = (ry * ry) * pow((xk + 0.5), 2) + (rx * rx) * pow((yk - 1), 2) - (pow(rx, 2) * pow(ry, 2));
	while ((2 * ry * 2 * xk) > (2 * rx * 2 * yk))
	{
		if (pk < 0)
		{
			xk = xk + 1;
			yk = yk - 1;
			pk = pk + 2 * (ry * ry) * xk - 2 * (rx * rx) * yk + (rx * rx);
		}
		else if (pk >= 0)
		{
			yik = yk - 1;
			pk = pk - 2 * (rx * rx) * yk + (rx * rx);
		}
		putpixel(x + xk, y + yk, WHITE);
	}
	getch();
	closegraph();
	return 0;
}
