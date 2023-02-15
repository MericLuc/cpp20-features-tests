/************************************************************
 *                    CORE - ORDERING                       *
 ************************************************************/

/*!
 *
 * @brief : Shows how the compiler-generated three-way 
 * comparison operator works.
 * 
 * It operates a lexicographical comparison, meaning that :
 * - All base classes are compared left to right
 * - All non-static members in their declaration order
 * 
 * @notes : For more informations, see
 * <https://en.cppreference.com/w/cpp/language/operator_comparison>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// compiler-generated.cpp -o compiler-generated`

#include <iostream>
#include <concepts>
#include <compare>

struct Basics {
    int i;
    char c;

    auto operator<=>(const Basics&) const = default;
};

struct Arrays {
    int ai[1];
    char ac[2];

    auto operator<=>(const Arrays&) const = default;
};

struct Bases : Basics, Arrays {
    auto operator<=>(const Bases&) const = default;
};

int main()
{
    constexpr Bases b1{ {42, 'a'}, { {42}, {'a','b'} } };
    constexpr Bases b2{ {42, 'a'}, { {44}, {'a','b'} } };

    std::cout << std::boolalpha;
    std::cout << "Lexicographical comparison\n";
    std::cout << "b1 < b2 ? " << (b1 < b2) << '\n';
    std::cout << "b1 > b2 ? " << (b1 > b2) << '\n';

    return EXIT_SUCCESS;
}

// Lexicographical comparison
// b1 < b2 ? true
// b1 > b2 ? false