#include <iostream>
#include <stdio.h>

#include "framebuffer.h"
#include "line.h"

using namespace std;

int main()
{
    Framebuffer buf;
    Line line(2, 2, 100, 300);

    line.draw(buf, 0x5342f4, buf.BUF_MAIN);

    return 0;
}