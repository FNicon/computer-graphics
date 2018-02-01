/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#include "parsetool.h"

#include "font.h"


istream& operator>> (istream& _is, Font& _obj) {
    std::string key;

    while (_is >> key) {
        if (key == "char") {
            char ch;

            // Read '#' character.
            if (!(_is >> ws >> expect('#'))) {
                cerr << "Font: '#' is expected" << endl;
                return _is;
            }

            if (!(_is >> ch)) {
                cerr << "Font: Character is expected" << endl;
                return _is;
            }

            Glyph& glyph = _obj.glyphs[ch];

            if (!(_is >> ws >> glyph)) {
                cerr << "Font: Glyph is expected" << endl;
                return _is;
            }
        } else {
            _is.setstate(std::ios_base::failbit);

            cerr << "Font: Illegal string keyword" << endl;
            return _is;
        }
    }

    return _is;
}

ostream& operator<< (ostream& _os, const Font& _obj) {
    auto& glyph = _obj.glyphs;
    auto it = glyph.begin();

    _os << "Font:" << endl;

    if (it == glyph.end()) {
         _os << "(empty)" << endl;
    } else {
        for (; it != glyph.end(); ++it)
            _os << it->first << ": " << it->second;
    }

    return _os;
}
