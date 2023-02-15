/************************************************************
 *                    CORE - ORDERING                       *
 ************************************************************/

/*!
 *
 * @brief : Shows how the three-way comparison operator
 * can help write simpler and efficient ordering.
 * 
 * It can be compiler-generated or user-generated and
 * automatically defines the six comparison operators
 * <, <=, ==, !=, >=, >
 * 
 * Note that you can also directly use <=> instead of
 * 'classical' comparison operators.
 * 
 * @notes : For more informations, see
 * <https://en.cppreference.com/w/cpp/language/operator_comparison>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// ordering-since.cpp -o ordering-since`

#include <iostream>
#include <concepts>
#include <compare>

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
    IntegralWrapper WrInt24(24), WrInt42(42);

    std::cout << std::boolalpha;
    std::cout << "Defining ordering since c++20 is clear!\n";
    std::cout << "WrInt24 == WrInt42 ? " << 
                 (WrInt24 == WrInt42) << '\n';
    std::cout << "WrInt24 >= WrInt42 ? " << 
                 (WrInt24 >= WrInt42) << '\n';
    std::cout << "WrInt24 < WrInt42 ? " << 
                 (WrInt24 < WrInt42) << '\n';


    // (a <=> b) < 0 if a < b
    // (a <=> b) > 0 if a > b
    // (a <=> b) == 0 if a and b are equal/equivalent.
    auto r{ WrInt24 <=> WrInt24 };
    std::cout << "WrInt24 <=> WrInt24 : " << 
    ((r < 0) ? "<" : ((r > 0) ? ">" : "==")) << '\n';

    return EXIT_SUCCESS;
}

// Defining ordering since c++20 is clear!
// WrInt24 == WrInt42 ? false
// WrInt24 >= WrInt42 ? false
// WrInt24 < WrInt42 ? true
// WrInt24 <=> WrInt24 : ==