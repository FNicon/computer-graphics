/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#pragma once

#include <bits/stdc++.h>

#include "lib/framebuffer.h"
#include "polygon.h"
#include "raster.h"

using namespace std;


// Glyph.

class Glyph {
public:
    /**
     * Draw glyph to screen.
     *
     * @param _buf  framebuffer.
     * @param _x  x-axis.
     * @param _y  y-axis.
     */
    void Draw (Framebuffer& _buf, int _x, int _y, int _borderColor, int _inColor, bool _main) const;

    /**
     * Set object from input stream.
     *
     * @param _is  input stream to be read.
     * @param _obj  object to be set.
     */
    friend istream& operator>> (istream& _is, Glyph& _obj);

    /**
     * Print object to output stream.
     *
     * @param _os  output stream to be written.
     * @param _obj  object to be read.
     */
    friend ostream& operator<< (ostream& _os, const Glyph& _obj);

    bool IsNotExceptionalAllPolygon(int x, int y) const;

protected:
    vector<Polygon> polygons;
};
