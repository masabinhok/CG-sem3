#include <graphics.h>
#include <iostream>
#include <cstdlib> // For random
#include <ctime>   // For seeding random numbers

void drawSmiley(int x, int y, int radius) {
    // Draw face
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, radius, radius);

    // Draw eyes
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x - radius / 3, y - radius / 3, radius / 8, radius / 8); // Left eye
    fillellipse(x + radius / 3, y - radius / 3, radius / 8, radius / 8); // Right eye

    // Draw mouth (arc for a smile)
    setcolor(RED);
    arc(x, y, 200, 340, radius / 2); // Smiley mouth
}

int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    int radius = 50;
    int x = screenWidth / 2, y = screenHeight / 2;
    int dx = 10, dy = 10; // Speed of movement

    srand(time(0)); // Seed random numbers

    while (true) {
        cleardevice();

        // Draw the bouncing smiley
        drawSmiley(x, y, radius);

        // Move the smiley
        x += dx;
        y += dy;

        // Bounce off walls and change color randomly
        if (x + radius > screenWidth || x - radius < 0) {
            dx = -dx;
            setcolor(rand() % 15 + 1); // Randomize color
        }
        if (y + radius > screenHeight || y - radius < 0) {
            dy = -dy;
            setcolor(rand() % 15 + 1); // Randomize color
        }

        // Delay for smooth animation
        delay(50);

        // Exit condition (Press 'q' to quit)
        if (kbhit()) {
            char ch = getch();
            if (ch == 'q' || ch == 'Q') {
                break;
            }
        }
    }

    // Close graphics window
    closegraph();
    return 0;
}
