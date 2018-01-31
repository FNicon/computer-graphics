#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "framebuffer.h"
#include "line.h"

using namespace std;

int main()
{
    Framebuffer buf;

    int x1 = 2;
    int y1 = 2;
    int x2 = 100;
    int y2 = 100;

    Line line(x1, y1, x2, y2);
    int cnt = 400;

    while(cnt--)
    {
        line.draw(buf, 0x5342f4, buf.BUF_BACK);
        
        line.x1++; line.y1++;
        line.x2++; line.y2++;

        buf.flush();
        usleep(10000);
    }

    return 0;
}