/************************************************************
 *                    STL - std::format                     *
 ************************************************************/

/*!
 *
 * @brief : Shows how to create user-defined types
 * supporting the std::format library
 * 
 * Basically, to make a type 'format-ready', a specialization
 * of the struct `formatter<class T, clas CharT = char>` must
 * be provided for that class type.
 * 
 * Enabled specializations meet the `Formatter` requirements,
 * meaning they define callables :
 * - parse : Handles the parameters after the ':' in the
 *  format context. If the type class does not handle any,
 * you may simply return the std::end() iterator
 * - format
 *  
 * @notes : For more informations, see 
 * <https://en.cppreference.com/w/cpp/utility/format/formatter>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// extensibility.cpp -o extensibility`

#include <iostream>
#include <format>
#include <concepts>
#include <vector>
#include <numeric>

/*
parse :
- Accepts the parse context
- Parses the parse context 
- Returns an iterator to the end of the format specification
- Throws a std::format_error in case of error

format :
- Gets the value t that should be formatted
- Gets the format context fc t should be formatted to
- Formats t according to the fc
- Writes the output to fc.out()
- Returns an iterator to the end of the output
*/

template< std::integral T >
struct Point{ T x, y; };

template <typename T>
struct std::formatter< Point<T> > {
    // Note that here, parse could be inherited
    // from base class 
    constexpr auto parse(std::format_parse_context& ctx) {
        return std::end(ctx);
    }

    template <class FormatContext>
    auto format(const Point<T>& pt, FormatContext& ctx) {
        return std::format_to(ctx.out(), "({},{})", pt.x, pt.y);
    }
};

template <typename T>
struct std::formatter< std::vector<T> > {
    std::string fmt;

    constexpr auto parse(std::format_parse_context& ctx) {
        fmt = "{:" + std::string{ std::begin(ctx), std::end(ctx) };
        return std::end(ctx) - 1;
    }

    template <class FormatContext>
    auto format(const std::vector<T>& v, FormatContext& ctx) {
        format_to(ctx.out(), "[");
        if ( !std::empty(v) ) 
            std::format_to( ctx.out(), fmt, v.at(0) );
        for ( auto i{1}; i < std::size(v); ++i )
            std::format_to( ctx.out(), " , " + fmt, v.at(i) );
        return std::format_to(ctx.out(), "]");
    }
};

int main()
{
    Point<int> pt{ .x = 42, .y = 24 };
    std::cout << std::format("Format Point<double> : {:}\n", pt);
    

    std::vector<int> v(10);
    std::iota(std::begin(v), std::end(v), 0);
    std::cout << std::format("Format vector<int> : {:}\n", v);

    return EXIT_SUCCESS;
}

// Format Point<double> : (42,24)
// Format vector<int> : [0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9]