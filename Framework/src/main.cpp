#include <iostream>

#include "framebuffer.h"

using namespace std;

int main()
{
    Framebuffer frame_buf;
    
    frame_buf.init();

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            frame_buf.set(i,j,0xFF,0,0,0);
        }
    }

    for(int i=10;i<20;i++)
    {
        for(int j=10;j<20;j++)
        {
            frame_buf.set(i,j,0,0xFF,0,0);
        }
    }

    for(int i=20;i<30;i++)
    {
        for(int j=20;j<30;j++)
        {
            frame_buf.set(i,j,0,0,0xFF,0);
        }
    }

    for(int i=30;i<40;i++)
    {
        for(int j=30;j<40;j++)
        {
            frame_buf.set(i,j,0xFF,0xFF,0xFF,90);
        }
    }
    
    frame_buf.cleanup();

    return 0;
}