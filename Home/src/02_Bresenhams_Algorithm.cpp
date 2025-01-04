#include <iostream>
#include <graphics.h> 


using namespace std;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;

    bool swapFlag = false;
    if (dy > dx) {
        int temp = dx;
        dx = dy;
        dy = temp;
        swapFlag = true;
    }

    int p = 2 * dy - dx;
    int x = x1, y = y1;

    for (int i = 0; i <= dx; i++) {
        putpixel(x, y, WHITE);

        if (p >= 0) {
            if (swapFlag)
                x += sx;
            else
                y += sy;
            p -= 2 * dx;
        }

        if (swapFlag)
            y += sy;
        else
            x += sx;

        p += 2 * dy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); 

    int x1, y1, x2, y2;
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    drawLineBresenham(x1, y1, x2, y2);

    // Draw text "Sabin Shrestha"
    setcolor(WHITE);
    outtextxy(200, 420, "Sabin Shrestha");

    getch(); 
    closegraph();

    return 0;
}
