/************************************************************
 *                    CORE - ORDERING                       *
 ************************************************************/

/*!
 *
 * @brief : Shows how priorities are managed between
 * user-defined comparison operators and auto-generated ones
 * (by `<=>` operator)
 * 
 * Basically, user-defined comparison operators have a higher
 * priority than auto-generated ones.
 * 
 * @notes : For more informations, see
 * <https://en.cppreference.com/w/cpp/language/operator_comparison>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// priorities.cpp -o priorities`

#include <iostream>
#include <concepts>
#include <compare>

template< std::integral T >
struct IntegralWrapper { 
    explicit constexpr IntegralWrapper(T val) noexcept: 
        _val{ val } {}

    // Compiler-generated
    // Defines the 6 comparison operators
    auto operator<=>(const IntegralWrapper<T>& rhs) const = default;

    // User-defined comparison operator
    // Cannot be constexpr because of std::cout
    // (exec time operation)
    bool operator<(const IntegralWrapper<T>& rhs) const {
        std::cout << "Using user-defined operator<()\n";
        return _val < rhs._val;
    }

    T _val;
};

int main()
{
    IntegralWrapper WrInt24(24), WrInt42(42);

    std::cout << std::boolalpha;
    std::cout << "Priorities between comparison operators\n";
    std::cout << "WrInt24 == WrInt42 ? " << 
                 (WrInt24 == WrInt42) << '\n';
    std::cout << "WrInt24 >= WrInt42 ? " << 
                 (WrInt24 >= WrInt42) << '\n';
    std::cout << "WrInt24 < WrInt42 ? " << 
                 (WrInt24 < WrInt42) << '\n';

    return EXIT_SUCCESS;
}

// Priorities between comparison operators
// WrInt24 == WrInt42 ? false
// WrInt24 >= WrInt42 ? false
// WrInt24 < WrInt42 ? Using user-defined operator<()
// true
