#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

// function to draw line with DDA
void drawLineWithDDA(int x1, int y1, int x2, int y2){

    // calculating the difference
    int dx = x2 - x1;
    int dy = y2 - y1;

    // calculating the step
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculating the increments
    float xi = dx / float(steps);
    float yi = dy /float(steps);

    // initializing the starting points
    float x = x1;
    float y = y1; 

    // iterating through steps and incrementing x, y
    for ( int i = 0 ; i <= steps; i++){
        putpixel(round(x), round(y), WHITE);
        x += xi;
        y += yi;
    }
}

int main () {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    outtextxy(10, 10, "Sabin Shrestha");

    int x1, y1, x2, y2;

    cout << "Enter the first endpoints x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter the second endpoitns x2, y2: ";
    cin >> x2 >> y2;

    drawLineWithDDA(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}