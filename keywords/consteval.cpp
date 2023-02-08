/************************************************************
 *                   KEYWORDS - CONSTEVAL                   *
 ************************************************************/

/*!
 *
 * @brief : Demonstrate how the 'consteval' keyword can be used.
 *
 * consteval declares 'immediate functions'. That is, functions that 
 * must be evaluated at compile time. Each invocation of a 'immediate 
 * function' creates a compile-time constant (i.e. compile-time execution).
 * 
 * 'immediate functions' need to satisfay 'constexpr' requirements,
 * which basically means that all dependances must be resolved at 
 * compile-time :
 * - calls to constexpr functions
 * - use fondamental data types (initialized with a constant expression)
 * - jumps
 * 
 * @notes : Some differences with 'constexpr functions', which
 * - may be evaluated at compile-time or at run-time.
 * - does not require to produce a constant expression.
 */

// compiled with `g++ -std=c++20 -Wall -O0 consteval.cpp -o consteval`

#include <iostream>

constexpr auto decrement(int i){ return i - 1; }
consteval auto fn(int i){ return i * decrement(i); }

int main()
{
    // OK - constVal is a constant expression
    const int constVal{ 3 };
    std::cout << "fn(constVal) = " << fn(constVal) << '\n'; 

    // KO - val is not
    // int val{ 3 };
    // std::cout << "fn(val) = " << fn(val) << '\n'; 

    return EXIT_SUCCESS;
}

//fn(constVal) = 6