/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#include "parsetool.h"

#include "polygon.h"


istream& operator>> (istream& _is, Polygon& _obj) {
    Point p;

    // Read first mandatory point.

    if (!(_is >> p)) {
        cerr << "Polygon: 1st Point is expected" << endl;
        goto quit;
    }

    _obj.points.push_back(p);

    // Read additional points.

    while (!(_is >> blank >> expect('\n'))) {

        if (!(_is >> reset >> p)) {
            cerr << "Polygon: Point is expected" << endl;
            goto quit;
        }

        _obj.points.push_back(p);
    }

quit:
    return _is;
}

ostream& operator<< (ostream& _os, const Polygon& _obj) {
    auto& points = _obj.points;
    auto it = points.begin();

    _os << "Polygon ";

    if (it == points.end()) {
        _os << "(empty)";
    } else {
        _os << *(it++);

        for (; it != points.end(); ++it) {
            _os << ' ' << *it;
        }
    }

    return _os;
}
