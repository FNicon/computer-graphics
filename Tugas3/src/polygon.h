/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#pragma once

#include <bits/stdc++.h>
#include "point.h"

using namespace std;


// Polygon.

class Polygon {
public:
    /**
     * Set object from input stream.
     *
     * @param _is  input stream to be read.
     * @param _obj  object to be set.
     */
    friend istream& operator>> (istream& _is, Polygon& _obj);

    /**
     * Print object to output stream.
     *
     * @param _os  output stream to be written.
     * @param _obj  object to be read.
     */
    friend ostream& operator<< (ostream& _os, const Polygon& _obj);

protected:
    vector<Point> points;
};
