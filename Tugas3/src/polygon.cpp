/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#include "parsetool.h"
#include "lib/line.h"

#include "polygon.h"


void Polygon::Draw (Framebuffer& _buf, int _x, int _y) const {
    auto it = points.begin();

    if (it != points.end()) {
        auto prev = *it;

        for (++it; it != points.end(); ++it) {
            const auto& self = *it;

            Line line(_x + prev.x, _y + prev.y, _x + self.x, _y + self.y);
            line.Draw(_buf, 0xffffff, 1, _buf.BUF_MAIN);

            // Put previous.
            prev = self;
        }
    }
}

istream& operator>> (istream& _is, Polygon& _obj) {
    Point p;

    // Read first mandatory point.

    if (!(_is >> p)) {
        cerr << "Polygon: 1st Point is expected" << endl;
        return _is;
    }

    _obj.points.push_back(p);

    // Read additional points.

    while (!(_is >> blank >> expect('\n'))) {

        if (!(_is >> reset >> p)) {
            cerr << "Polygon: Point is expected" << endl;
            return _is;
        }

        _obj.points.push_back(p);
    }

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
