#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define PI 3.1416

//void createTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void createTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    delay(300);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
}
void translate(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{
    delay(300);
    x1 += tx;
    x2 += tx;
    x3 += tx;
    y1 += ty;
    y2 += ty;
    y3 += ty;
    createTriangle(x1, y1, x2, y2, x3, y3);
}
void reflect(int x1, int y1, int x2, int y2, int x3, int y3, int midy)
{
    delay(300);
    // Reflect about x-axis
    // Translate back by mid and reflect and re-translate back to mid
    x1 = x1;
    y1 = -(y1 - midy) + midy;
    x2 = x2;
    y2 = -(y2 - midy) + midy;
    x3 = x3;
    y3 = -(y3 - midy) + midy;
    createTriangle(x1, y1, x2, y2, x3, y3);
}
void rotate(int x1, int y1, int x2, int y2, int x3, int y3, float cosVal, float sinVal, int midx, int midy)
{
    delay(300);
    x1 -= midx;
    x2 -= midx;
    x3 -= midx;
    y1 -= midy;
    y2 -= midy;
    y3 -= midy;
    //ClockWise Rotation
    x1 = floor(x1 * cosVal + x1 * sinVal);
    x2 = floor(x2 * cosVal + x2 * sinVal);
    x3 = floor(x3 * cosVal + x3 * sinVal);

    y1 = floor(-y1 * sinVal + y1 * cosVal);
    y2 = floor(-y2 * sinVal + y2 * cosVal);
    y3 = floor(-y3 * sinVal + y3 * cosVal);

    x1 += midx;
    x2 += midx;
    x3 += midx;
    y1 += midy;
    y2 += midy;
    y3 += midy;
    printf("%d, %d", x1, y1);
    printf("%d, %d", x2, y2);
    printf("%d, %d", x3, y3);
    createTriangle(x1, y1, x2, y2, x3, y3);
}
int main()
{
    int x1 = 10, y1 = 10, x2 = 30, y2 = 40, x3 = 50, y3 = 20;
    int gd = DETECT, gm;
    int maxx, maxy, midx, midy;
    float cosVal, sinVal;
    float angle = (PI / 180) * 45;
    initgraph(&gd, &gm, "C:\\TC\\bgi");
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy /2;
    // Draw Line
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);

    x1 += midx;
    x2 += midx;
    x3 += midx;
    y1 += midy;
    y2 += midy;
    y3 += midy;
    cosVal = (cos(angle));
    sinVal = (sin(angle));

    createTriangle(x1, y1, x2, y2, x3, y3);
    translate(x1, y1, x2, y2, x3, y3, 100, 80);
    reflect(x1, y1, x2, y2, x3, y3, midy);
    rotate(x1, y1, x2, y2, x3, y3, cosVal, sinVal, midx, midy);





    getch();
    closegraph();
    return 0;

}
