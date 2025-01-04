#include <graphics.h>
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2, int COLOR){
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = fabs(dx) >= fabs(dy) ? fabs(dx) : fabs(dy);
    
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1; 
    float y = y1;

    for(int i = 0 ; i <= steps; i++){
        putpixel(round(x), round(y), COLOR);
        x += xIncrement;
        y += yIncrement;
    }
}

int main () {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for(int i = 40; i <= 400; i += 40){
        if(i == 40 || i == 160 || i == 280 || i == 400){
            drawLine(40, i, 400, i, WHITE);
        }
        else 
        {
            drawLine(40, i, 400, i, RED);
        }
        
    }
    for(int i = 40; i <= 400; i += 40){
        if(i == 40 || i == 160 || i == 280 || i == 400){
            drawLine(i, 40, i, 400, WHITE);
        }
        else {
            drawLine(i, 40, i, 400, RED);
        }
    }

    drawLine(40, 40, 400, 400, WHITE);
    drawLine(40, 400, 400, 40, WHITE);
    drawLine(40, 160, 280, 400, WHITE);
    drawLine(40, 280, 160, 400, WHITE);
    drawLine(160, 400, 400, 160, WHITE); 
    drawLine(280, 400, 400, 280, WHITE);

    // Draw text "Sabin Shrestha"
    setcolor(WHITE);
    outtextxy(200, 420, "Sabin Shrestha");

    delay(50);
    getch();
    closegraph();
    return 0;
}
