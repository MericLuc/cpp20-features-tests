/************************************************************
 *                    CORE - ORDERING                       *
 ************************************************************/

/*!
 *
 * @brief : Show how flagship operator can be used
 * to provide comparisons at compile-time
 * 
 * Indeed, `<=>` is implicitly constexpr, which means
 * it can (or not) be applied at compile-time.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// compile-time.cpp -o compile-time`

#include <iostream>
#include <concepts>

template< std::integral T >
struct IntegralWrapper { 
    explicit constexpr IntegralWrapper(T val) noexcept: 
        _val{ val } {}

    // Compiler-generated
    auto operator<=>(const IntegralWrapper<T>& rhs) const = default;

    // User-generated
    // auto operator<=>(const IntegralWrapper<T>& rhs) const {
    //     return _val <=> rhs._val;
    // }

    T _val;
};

int main()
{
    constexpr IntegralWrapper a{42}, b{24};
    constexpr bool r1{ a < b }, r2{ a > b };
    
    std::cout << std::boolalpha;
    std::cout << "Comparisons at compile-time!\n";
    std::cout << "a < b : " << r1 << '\n';
    std::cout << "a > b : " << r2 << '\n';

    return EXIT_SUCCESS;
}

// Comparisons at compile-time!
// a < b : false
// a > b : true

