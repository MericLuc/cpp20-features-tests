/************************************************************
 *                    CORE - ORDERING                       *
 ************************************************************/

/*!
 *
 * @brief : Shows how much boilerplate code was needed
 * to define user-defined class ordering.
 * 
 * To define ordering between types T et U, 6 operator
 * needed to be defined : <, <=, ==, !=, >= and >
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// ordering-before.cpp -o ordering-before`

#include <iostream>
#include <concepts>

template< std::integral T >
struct IntegralWrapper { 
    explicit constexpr IntegralWrapper(T val) noexcept: 
        _val{ val } {}

    constexpr bool operator==(const IntegralWrapper<T>& rhs) const {
        return _val == rhs._val; 
    }

    constexpr bool operator!=(const IntegralWrapper<T>& rhs) const {
        return !(*this == rhs); 
    }

    constexpr bool operator< (const IntegralWrapper<T>& rhs) const {
        return _val < rhs._val; 
    }

    constexpr bool operator<=(const IntegralWrapper<T>& rhs) const {
        return !(*this > rhs); 
    }

    constexpr bool operator> (const IntegralWrapper<T>& rhs) const {
        return rhs > *this; 
    }

    constexpr bool operator>=(const IntegralWrapper<T>& rhs) const {
        return !(*this < rhs); 
    }

    T _val;
};

int main()
{
    IntegralWrapper WrInt24(24), WrInt42(42);

    std::cout << std::boolalpha;
    std::cout << "Defining ordering before c++20 is cumbersome\n";
    std::cout << "WrInt24 == WrInt42 ? " << 
                 (WrInt24 == WrInt42) << '\n';
    std::cout << "WrInt24 >= WrInt42 ? " << 
                 (WrInt24 >= WrInt42) << '\n';
    std::cout << "WrInt24 < WrInt42 ? " << 
                 (WrInt24 < WrInt42) << '\n';

    return EXIT_SUCCESS;
}

// Defining ordering before c++20 is cumbersome
// WrInt24 == WrInt42 ? false
// WrInt24 >= WrInt42 ? false
// WrInt24 < WrInt42 ? true
