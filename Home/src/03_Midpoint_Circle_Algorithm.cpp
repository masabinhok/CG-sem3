#include <stdio.h>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int xc, yc, r, p, x, y;

    initgraph(&gd, &gm, NULL);


    printf("Enter the center of circle (xc yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius of circle: ");
    scanf("%d", &r);

    p = 1 - r;
    x = 0;
    y = r;


    while (x <= y)
    {

        putpixel(x + xc, y + yc, WHITE);
        putpixel(x + xc, -y + yc, WHITE);
        putpixel(-x + xc, -y + yc, WHITE);
        putpixel(-x + xc, y + yc, WHITE);
        putpixel(y + xc, x + yc, WHITE);
        putpixel(y + xc, -x + yc, WHITE);
        putpixel(-y + xc, -x + yc, WHITE);
        putpixel(-y + xc, x + yc, WHITE);

        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * x + 3;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * (x - y) + 5;
        }
    }

    setcolor(WHITE);
    outtextxy(10, 10, "Sabin Shrestha");
    getch();
    

    closegraph();

    return 0;
}
