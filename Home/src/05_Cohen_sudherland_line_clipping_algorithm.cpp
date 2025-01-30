#include <iostream>
#include <graphics.h>
using namespace std;

// Define region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the clipping window
const int X_MIN = 100, Y_MIN = 100, X_MAX = 400, Y_MAX = 400;

// Function to compute the region code of a point
int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < X_MIN) code |= LEFT;
    else if (x > X_MAX) code |= RIGHT;
    if (y < Y_MIN) code |= BOTTOM;
    else if (y > Y_MAX) code |= TOP;
    return code;
}

// Cohen-Sutherland Line Clipping Algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) { // Both endpoints inside
            accept = true;
            break;
        } else if (code1 & code2) { // Both endpoints share an outside region
            break;
        } else {
            int codeOut;
            int x, y;
            if (code1 != 0) codeOut = code1; // Choose the outside point
            else codeOut = code2;

            // Find intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    // Draw clipping rectangle
    setcolor(WHITE);
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
    
    // Original line
    int x1 = 50, y1 = 50, x2 = 450, y2 = 450;
    setcolor(RED);
    line(x1, y1, x2, y2);
    
    // Apply clipping
    cohenSutherlandClip(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}
