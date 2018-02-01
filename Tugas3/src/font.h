/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#pragma once

#include <bits/stdc++.h>

#include "glyph.h"

using namespace std;


// Font.

class Font {
public:
    /**
     * Set object from input stream.
     *
     * @param _is  input stream to be read.
     * @param _obj  object to be set.
     */
    friend istream& operator>> (istream& _is, Font& _obj);

    /**
     * Print object to output stream.
     *
     * @param _os  output stream to be written.
     * @param _obj  object to be read.
     */
    friend ostream& operator<< (ostream& _os, const Font& _obj);

protected:
    map<char, Glyph> glyphs;
};
