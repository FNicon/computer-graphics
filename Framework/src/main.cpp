#include <iostream>
#include <stdio.h>

#include "framebuffer.h"

using namespace std;

int main()
{
    Framebuffer buf;

    // Test red
    for(int r=0; r<10; r++)
    {
        for(int c=0; c<10; c++)
        {
            buf.write(r, c, 0xff0000, buf.BUF_MAIN);
        }
    }

    // Test green
    for(int r=10; r<20; r++)
    {
        for(int c=10; c<20; c++)
        {
            buf.write(r, c, 0x00ff00, buf.BUF_MAIN);
        }
    }

    // Test blue
    for(int r=20; r<30; r++)
    {
        for(int c=20; c<30; c++)
        {
            buf.write(r, c, 0x0000ff, buf.BUF_MAIN);
        }
    }

    // Test white
    for(int r=30; r<40; r++)
    {
        for(int c=30; c<40;c++)
        {
            buf.write(r, c, 0xffffff, buf.BUF_MAIN);
        }
    }

    // Test gray
    for(int r=40; r<50; r++)
    {
        for(int c=40; c<50; c++)
        {
            buf.write(r, c, 0x3c3c3c, buf.BUF_MAIN);
        }
    }

    return 0;
}