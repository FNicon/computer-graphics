#include "line.h"

#include <cstdlib>

using namespace std;

Line::Line(int _x1, int _y1, int _x2, int _y2)
{
    // Assign first point coordinates
    x1 = _x1;
    y1 = _y1;

    // Assign second point coordinates
    x2 = _x2;
    y2 = _y2;
}

void Line::draw(Framebuffer& buf, int color, bool main)
{
    // Use Bresenham's algorithm to determine which pixels represents this line

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    int p = 2 * dy - dx;

    int const1 = 2 * dy;
    int const2 = 2 * (dy - dx);

    int x, x_end, y;

    x = (x1 > x2)? x2 : x1;
    y = (x1 > x2)? y2 : y1;
    x_end = (x1 > x2)? x1 : x2;

    buf.write(y, x, color, main);

    while(x < x_end)
    {
        x++;

        if(p < 0) p += const1;
        else 
        {
            y++;
            p += const2;
        }

        buf.write(y, x, color, main);
    }
}