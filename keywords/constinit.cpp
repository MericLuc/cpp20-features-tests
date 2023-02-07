/************************************************************
 *                   KEYWORDS - CONSTINIT                   *
 ************************************************************/

/*!
 *
 * @brief : Demonstrate how the 'constinit' keyword can be used.
 *
 * Ensures that variables with static or thread storage duration are 
 * initialized during the compilation. 
 * 
 * Basically
 * - 'static storage duration' -> Alloc at program start, dealloc at program end
 * - 'thread storage duration' -> Bound to thread lifetime
 * 
 * @usage : A typical usage of 'constinit' is to solve the 'static 
 * initialization order fiasco'.
 * It happended because initialization order of variables with static storage
 * duration were not garanteed through different translation units.
 * Variables were initialized when control flow passed through its declaration.
 *
 * @note : constinit does not imply constness (unlike const or constexpr)
 */

// compiled with `g++ -std=c++20 -Wall -O0 constinit.cpp -o constinit`

#include <iostream>

constinit auto constInitVal{ 42 };
constexpr auto constExprVal{ 42 };

auto computation(int in) noexcept { return in * in; }

int main()
{
    const auto vOut{ computation(42) };

    std::cout << "constinit : " << constInitVal << '\n'
              << "constexpr : " << constExprVal << '\n'
              << "const : "     << vOut         << '\n';

    constexpr auto localConstExpr{ 42 }; // This is OK
    // constinit auto localConstInit{ 42 }; // Ill-formed (wrong storage duration)

    return EXIT_SUCCESS;
}