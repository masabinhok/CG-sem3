#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int r){
    //initial points.
   int x = 0; 
   int y = r;

    // initial decision parameter.
    int d;
    d = 1- r;

    while(x < y){
        putpixel(x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(y + xc, x + yc, WHITE);
        putpixel(y + xc, -x + yc, WHITE);
        putpixel(-y + xc, -x + yc, WHITE);
        putpixel(-y + xc, x + yc, WHITE);
    if(d < 0){
        x += 1;
        d += 2 * x + 3;
    }
    else {
        x += 1;
        y -= 1;
        d += 2 * x - 2 * y + 5;
    }}
}


int main (){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); 
    int xc, yc, r;

    cout << "Enter centers of circle (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius of the circle r: ";
    cin >> r;

    drawCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}


