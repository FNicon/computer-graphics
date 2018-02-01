/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#include "parsetool.h"

#include "point.h"


istream& operator>> (istream& _is, Point& _obj) {
    // Read '(' character.
    if (!(_is >> expect('('))) {
        cerr << "Point: '(' is expected" << endl;
        goto quit;
    }

    // Read X-axis.
    if (!(_is >> ws >> _obj.x)) {
        cerr << "Point: X-axis is expected" << endl;
        goto quit;
    }

    // Read ',' separator.
    if (!(_is >> ws >> expect(','))) {
        cerr << "Point: ',' is expected" << endl;
        goto quit;
    }

    // Read Y-axis.
    if (!(_is >> ws >> _obj.y)) {
        cerr << "Point: Y-axis is expected" << endl;
        goto quit;
    }

    // Read ')' character.
    if (!(_is >> ws >> expect(')'))) {
        cerr << "Point: ')' is expected" << endl;
        goto quit;
    }

quit:
    return _is;
}

ostream& operator<< (ostream& _os, const Point& _obj) {
    return _os << '(' << _obj.x << ',' << _obj.y << ')';
}
