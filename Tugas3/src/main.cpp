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
    Line line2(100, 0, 100, 100);
    Line line3(100, 100, 200, 0);
    Line line4(100, 100, 200, 100);
    Line line5(100, 100, 200, 200);
    Line line6(100, 100, 100, 200);
    Line line7(100, 100, 0, 200);
    Line line8(100, 100, 0, 100);
    int cnt = 400;

    /*while(cnt--)
    {*/
        //line.draw(buf, 0x5342f4, buf.BUF_MAIN);
        //line2.draw(buf, 0x5342f4, buf.BUF_MAIN);
        //line3.draw(buf, 0x5342f4, buf.BUF_MAIN);
        //line4.draw(buf, 0x5342f4, buf.BUF_MAIN);
        //line5.draw(buf, 0x5342f4, buf.BUF_MAIN);
        //line6.draw(buf, 0x5342f4, buf.BUF_MAIN);
        //line7.draw(buf, 0x5342f4, buf.BUF_MAIN);
        line8.draw(buf, 0x5342f4, buf.BUF_MAIN);

        //line.x1++; line.y1++;
        //line.x2++; line.y2++;

        //buf.flush();
        /*usleep(10000);
    }*/

    return 0;
}