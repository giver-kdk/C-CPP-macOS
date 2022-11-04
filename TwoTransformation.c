#include <stdio.h>
#include <graphics.h>
#include <math.h>

void translate(int x[], int y[], int tx, int ty)
{

}
void create_triangle(int x[], int y[])
{

}


int main()
{
    int x1 = 10, y1 = 10, x2 = 30, y2 = 40, x3 = 50, y3 = 20;
    int gd = DETECT, gm;
    int maxx, maxy, midx, midy;
    initgraph(&gd, &gm, "C:\\TurboC3\\bgi");
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy /2;
    // Draw Line
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);





}
