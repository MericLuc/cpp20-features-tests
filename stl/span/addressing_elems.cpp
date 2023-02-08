/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : Shows how a std::span can address its view.
 * 
 * @notes : That fact therefore constitutes the main difference
 * between std::span<std::string> and std::string_view
 * 
 * @notes : Note that you can prevent a std::span from modifying
 * its view by creating it as a constant range of constant elements.
 * i.e. std::span<const T> mySPan{ myContinuousRange<T> };
 */

// compiled with `g++ -std=c++20 -Wall -O0 span.cpp -o span`

#include <iostream>
#include <span>
#include <ranges>
#include <vector>

template <typename T>
void printSpan(std::span<T> s, std::string_view msg) noexcept {
    std::cout << msg << '\n';
    std::cout << "\tstd::size : " << std::size(s) << "\n\t";

    for ( const auto& elm : s )
        std::cout << elm << " ";
    std::cout << '\n';
}

int main()
{
    std::vector<int> v;
    v.reserve(100);
    for ( const auto& elm : std::views::iota(0) | std::views::take(100) )
        v.push_back(elm);

    std::span<int> s{ v };

    std::cout << "front         : " << s.front() << '\n';
    std::cout << "back          : " << s.back() << '\n';
    std::cout << "size          : " << s.size() << '\n';
    std::cout << "size in bytes : " << s.size_bytes() << '\n';
    std::cout << "operator[50]  : " << s[50] << '\n';
    std::cout << "empty         : " << std::boolalpha << std::empty(s) << '\n';

    printSpan<int>( s.first(10), "first(10) elements");
    printSpan<int>( s.last(10), "last(10) elements");
    printSpan<int>( s.subspan(45, 10), "subspan(45, 10) elements");

    return EXIT_SUCCESS;
}

// front         : 0
// back          : 99
// size          : 100
// size in bytes : 400
// operator[50]  : 50
// empty         : false
// first(10) elements
//     std::size : 10
//     0 1 2 3 4 5 6 7 8 9 
// last(10) elements
//     std::size : 10
//     90 91 92 93 94 95 96 97 98 99 
// subspan(45, 10) elements
//     std::size : 10
//     45 46 47 48 49 50 51 52 53 54 
