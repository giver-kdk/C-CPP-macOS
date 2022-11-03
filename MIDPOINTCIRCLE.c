#include <graphics.h>
#include <stdio.h>

int main()
{
    int x, y, r, xk, yk, pk;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\bgi");

    printf("Enter x and y coordinates: ");
    scanf("%d %d", &x, &y);
    printf("Enter radius of circle: ");
    scanf("%d", &r);

    xk = 0;
    yk = r;
    pk = 1 - r;
    while(xk < yk)
    {
         if(pk < 0)
        {

            xk = xk + 1;
            pk = pk + (2 * xk) + 1;
        }
        else if(pk >= 0)
        {
            xk = xk + 1;
            yk = yk - 1;
            pk = pk + (2 * xk) - (2 * yk) + 1;
        }
        putpixel(x + xk, y + yk, 4);
        putpixel(x + yk, y + xk, 4);
        putpixel(x - yk, y + xk, 4);
        putpixel(x - xk, y + yk, 4);
        putpixel(x - xk, y - yk, 4);
        putpixel(x - yk, y - xk, 4);
        putpixel(x + yk, y - xk, 4);
        putpixel(x + xk, y - yk, 4);
    }
   getch();
   closegraph();
   return 0;

}
