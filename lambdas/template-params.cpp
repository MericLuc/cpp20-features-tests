/************************************************************
 *                      STL - LAMBDAS                       *
 ************************************************************/

/*!
 *
 * @brief : We finally got to use template parameters in
 * lambdas !
 * 
 * @note : Since lambdas now support templated parameters,
 * it means we can use `concepts` with it.
 * The principle interest over c++14 generic lambdas is to
 * enforce conditions on the parameters (same type is the
 * most obvious case) and make your code more expressive.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// template-params.cpp -o template-params`

#include <algorithm>
#include <iostream>
#include <vector>
#include <string_view>
#include <ranges>
#include <numeric>
#include <concepts>

int main()
{
    std::vector<char> vec(26);
    std::iota(std::begin(vec), std::end(vec), 'a');

    // The principle interest over c++14 generic lambdas is to
    // enforce conditions on the parameters (same type is the
    // most obvious case) and make your code more expressive.
    auto enforceSameType{ []<std::integral T>(
         const T& r1, const T& r2, std::string_view mesg) {
        std::cout << mesg << " : " << r1 << " + " << r2 << " = " << r1 + r2 << '\n';
    } };

    enforceSameType(-58, 100, "Forcing same integral type");


    // Don't mind this, just messing with concepts
    auto dumbAND{ [](const std::predicate auto&& c1, 
                     const std::predicate auto&& c2){ return c1() && c2(); } };

    std::cout << dumbAND([](){return true;}, [](){return false;}) << '\n';
    

    return EXIT_SUCCESS;
}