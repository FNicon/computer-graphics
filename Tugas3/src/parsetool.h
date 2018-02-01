/**
 * Assignment 3 - IF3260 Grafika Komputer
 */

#pragma once

#include <istream>


// blank.

/**
 * Extended manipulator for skipping blanks.
 */
template<typename CharType, typename Traits>
std::basic_istream<CharType, Traits>& blank (
    std::basic_istream<CharType, Traits>& _is) {

    using StreamType = std::basic_istream<CharType, Traits>;
    using StreamBufType = std::basic_streambuf<CharType, Traits>;
    using CTypeType = std::ctype<CharType>;
    using IntType = typename StreamType::int_type;

    const CTypeType& ct = std::use_facet<CTypeType>(_is.getloc());
    const IntType eof = Traits::eof();
    StreamBufType* sb = _is.rdbuf();

    IntType c = sb->sgetc();

    while (!Traits::eq_int_type(c, eof)
        && ct.is(std::ctype_base::blank, Traits::to_char_type(c)))
        c = sb->snextc();

    if (Traits::eq_int_type(c, eof))
        _is.setstate(std::ios_base::eofbit);

    return _is;
}


// expect.

template<typename CharType>
struct _Expect { CharType ch; };

/**
 * Expect a character in a stream.
 * @param _ch  Character to be expected.
 */
template<typename CharType>
inline _Expect<CharType> expect(CharType _ch) {
    return { _ch };
}

template<typename CharType, typename Traits>
std::basic_istream<CharType, Traits>& operator>> (
    std::basic_istream<CharType, Traits>& _is, _Expect<CharType> _t) {

    using StreamType = std::basic_istream<CharType, Traits>;
    using StreamBufType = std::basic_streambuf<CharType, Traits>;
    using IntType = typename StreamType::int_type;

    const IntType eof = Traits::eof();
    StreamBufType* sb = _is.rdbuf();

    IntType c = sb->sgetc();

    if (Traits::eq_int_type(c, eof)) {
        _is.setstate(std::ios_base::eofbit);
    } else {
        // Not EOF.
        if (Traits::to_char_type(c) == _t.ch) {
            sb->snextc();
        } else {
            _is.setstate(std::ios_base::failbit);
        }
    }

    return _is;
}


// reset.

/**
 * Extended manipulator for resetting stream error flags.
 */
template<typename CharType, typename Traits>
std::basic_istream<CharType, Traits>& reset (
    std::basic_istream<CharType, Traits>& _is) {

    if (_is.fail() && !_is.bad())
        _is.clear();

    return _is;
}
