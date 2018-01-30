#pragma once

#include "framebuffer.h"

class Line
{
    public:
        // Properties

        int x1, y1; // First point coordinate
        int x2, y2; // Second point coordinate

        // Methods

        Line(int _x1, int _y1, int _x2, int _y2); // Line constructor

        // Draw line to main buffer or back buffer with RGB color, use hex for color
        void draw(Framebuffer& buf, int color, bool main);
};