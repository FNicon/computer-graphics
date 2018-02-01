#pragma once

#include "framebuffer.h"

class Line
{
    private:
        // Methods

        void DrawX (Framebuffer& buf, int color, int thickness, bool main); // Draw by coloring pixels for every X
        void DrawY (Framebuffer& buf, int color, int thickness, bool main); // Draw by coloring pixels for every Y

    public:
        // Properties

        int x1, y1; // First point coordinate
        int x2, y2; // Second point coordinate

        // Methods

        Line(int _x1, int _y1, int _x2, int _y2); // Line constructor

        // Draw line to main buffer or back buffer with RGB color and thickness, use hex for color
        void Draw(Framebuffer& buf, int color, int thickness, bool main);
};