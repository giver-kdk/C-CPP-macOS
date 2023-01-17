#include <stdio.h>
#include <math.h>

/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
/* Defining function which is basically re-araanged "x, y and z" */
// #define f1(x, y, z) (17 - y + 2 * z) / 20					// "x"
// #define f2(x, y, z) (-18 - 3 * x + z) / 20					// "y"
// #define f3(x, y, z) (25 - 2 * x + 3 * y) / 20				// "z"
#define f1(x, y, z) (16 - 4*y - 5*z) / 6
#define f2(x, y, z) (12 - 5*x - 3*z) / 2
#define f3(x, y, z) (4 - x - 2*y) / 3
// #define f1(x, y, z) (12 - 2*y - 3*z) / 5
// #define f2(x, y, z) (16 - 6*x -5*z) / 4
// #define f3(x, y, z) (4 - x - 2*y) / 3


/* Main function */
int main()
{
	float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
	int count = 1;
	printf("Enter tolerable error:\n");
	scanf("%f", &e);							// Use: 0.001

	printf("\nCount\tx\ty\tz\n");
	do
	{
		/* Calculation, use possible lastest values for input*/
		x1 = f1(x0, y0, z0);
		y1 = f2(x1, y0, z0);
		z1 = f3(x1, y1, z0);
		printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

		/* Error, which is just difference of previous and current result */
		e1 = fabs(x0 - x1);
		e2 = fabs(y0 - y1);
		e3 = fabs(z0 - z1);

		count++;

		/* Set value for next iteration */
		x0 = x1;
		y0 = y1;
		z0 = z1;

	} while (e1 > e && e2 > e && e3 > e);

	printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n", x1, y1, z1);
	return 0;
}