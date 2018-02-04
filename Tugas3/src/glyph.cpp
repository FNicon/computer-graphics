/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#include "parsetool.h"

#include "glyph.h"


void Glyph::Draw (Framebuffer& _buf, int _x, int _y) const {
    for (const Polygon& polygon : polygons) {
        polygon.Draw(_buf, _x, _y);
    }
    // Rastering
//     bool colorize;
//     for (j=0; j< _y; j++){
//         colorize = false;
//         for (i=0; i<_x; i++) {
//             Point point;
//             // If the pixel is line color
//             if (std::find(points.begin(), points.end(), point) != points.end()) {
//                 //Change color
//                 if (!colorize) {
//                     colorize = true;
//                 } else {
//                     colorize = false;
//                 }
//             }

//             buf.Write(_y + j, _x + i, 0xFFFFFF, colorize);
//         }
//     }
}

istream& operator>> (istream& _is, Glyph& _obj) {
    // Read '{' character.
    if (!(_is >> expect('{'))) {
        cerr << "Glyph: '{' is expected" << endl;
        return _is;
    }

    while (!(_is >> ws >> expect('}'))) {
        std::string key;

        if (!(_is >> reset >> key)) {
            cerr << "Glyph: String keyword is expected" << endl;
            return _is;
        }

        if (key == "p") {
            Polygon polygon;

            if (!(_is >> blank >> polygon)) {
                cerr << "Glyph: Polygon is expected" << endl;
                return _is;
            }

            _obj.polygons.push_back(polygon);
        } else {
            _is.setstate(std::ios_base::failbit);

            cerr << "Glyph: Illegal string keyword" << endl;
            return _is;
        }
    }

    return _is;
}

ostream& operator<< (ostream& _os, const Glyph& _obj) {
    auto& polygons = _obj.polygons;
    auto it = polygons.begin();

    _os << "Glyph ";

    if (it == polygons.end()) {
         _os << "(empty)" << endl;
    } else {
        _os << "{" << endl;

        for (; it != polygons.end(); ++it) {
            _os << '\t' << *it << endl;
        }

        _os << "}" << endl;
    }

    return _os;
}
