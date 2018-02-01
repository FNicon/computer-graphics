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

void Line::Draw(Framebuffer& buf, int color, int thickness, bool main)
{
	// Use Bresenham's algorithm to determine which pixels represents this line

	if(abs(y2 - y1) < abs(x2 - x1)) DrawX(buf,color,thickness,main); // Draw by coloring pixels for every X if pixels on X axis greater or equal than pixels on Y axis
    else DrawY(buf,color,thickness,main); // Draw by coloring pixels for every Y if pixels on X axis less than pixels on Y axis
}

void Line::DrawX(Framebuffer& buf, int color, int thickness, bool main)
{
	for(int t=0; t<thickness;t++)
	{
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);

		int p = 2 * dy - dx;

		int const1 = 2 * dy;
		int const2 = 2 * (dy - dx);

		int x, x_end, y, y_end;
		int sign;

		if(x1 > x2)
		{
			x = x2;
			y = y2 + t;
			x_end = x1;
			y_end = y1 + t;
		}
		else
		{
			x = x1;
			y = y1 + t;
			x_end = x2;
			y_end = y2 + t;
		}

		if (y_end < y) sign = -1;
		else if (y_end > y) sign = 1;
		else sign = 0;

		buf.Write(y, x, color, main);

		while(x < x_end)
		{
			x++;

			if(p < 0) p += const1;
			else
			{
				y = y + sign;
				p += const2;
			}

			buf.Write(y, x, color, main);
		}
	}
}

void Line::DrawY(Framebuffer& buf, int color, int thickness, bool main)
{
	for(int t=0; t<thickness;t++)
	{
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);

		int p = 2 * dx - dy;

		int const1 = 2 * dx;
		int const2 = 2 * (dx - dy);

		int x, x_end, y, y_end;
		int sign;

		if (y1 > y2)
		{
			x = x2 + t;
			y = y2;
			x_end = x1 + t;
			y_end = y1;
		}
		else
		{
			x = x1 + t;
			y = y1;
			x_end = x2 + t;
			y_end = y2;
		}

		if (x_end < x) sign = -1;
		else if (x_end > x) sign = 1;
		else sign = 0;

		buf.Write(y, x, color, main);

		while(y < y_end)
		{
			y++;

			if(p < 0) p += const1;
			else
			{
				x = x + sign;
				p += const2;
			}
			
			buf.Write(y, x, color, main);
		}
	}
}