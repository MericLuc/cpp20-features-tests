/************************************************************
 *                     STL - ARITHMETIC                     *
 ************************************************************/

/*!
 *
 * @brief : Show how safe integral types comparison
 * solved a subtle but common bug cause.
 * 
 * @notes : Comparison between signed and unsigned
 * integers are indeed a common cause of bugs.
 */

// compiled with `g++ -std=c++20 -Wall -O0
// safe-comparison.cpp -o safe-comparison`

#include <iostream>
#include <concepts>
#include <typeinfo>
#include <utility> // c++20 integers comparison functions

void unsafe_comparison(const std::integral auto&& a, 
                       const std::integral auto&& b) noexcept {
  std::cout << std::boolalpha;
  std::cout << "UNSAFE INTEGRAL TYPES COMPARISON\n";
  std::cout << "Compared types: " << typeid(a).name() << " and " << typeid(b).name() << '\n';
  std::cout << "Compared values: " << a << " and " << b << '\n';
  std::cout << "a <  b " << (a <  b) << '\n';
  std::cout << "a <= b " << (a <= b) << '\n';
  std::cout << "a >  b " << (a >  b) << '\n';
  std::cout << "a >= b " << (a >= b) << '\n';
}

void safe_comparison(const std::integral auto&& a, 
                     const std::integral auto&& b) noexcept {
  std::cout << std::boolalpha;
  std::cout << "SAFE INTEGRAL TYPES COMPARISON\n";
  std::cout << "Compared types: " << typeid(a).name() << " and " << typeid(b).name() << '\n';
  std::cout << "Compared values: " << a << " and " << b << '\n';
  std::cout << "a <  b " << std::cmp_less(a,b) << '\n';
  std::cout << "a <= b " << std::cmp_less_equal(a,b) << '\n';
  std::cout << "a >  b " << std::cmp_greater(a,b) << '\n';
  std::cout << "a >= b " << std::cmp_greater_equal(a,b) << '\n';
}

int main()
{
    // Note : This will not compile with the 
    // '-Werr' compilation flag because of the
    // warning : "comparison of integer expressions of 
    // different signedness: ‘const int’ and 
    // ‘const unsigned int’ [-Werror=sign-compare]"
    unsafe_comparison((int)(-2), (unsigned)(42));

    safe_comparison((int)(-2), (unsigned)(42));

    return EXIT_SUCCESS;
}

// UNSAFE INTEGRAL TYPES COMPARISON
// Compared types: i and j
// Compared values: -2 and 3
// a <  b false
// a <= b false
// a >  b true
// a >= b true

// SAFE INTEGRAL TYPES COMPARISON
// Compared types: i and j
// Compared values: -2 and 42
// a <  b true
// a <= b true
// a >  b false
// a >= b false
