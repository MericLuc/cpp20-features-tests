/************************************************************
 *                     STL - ARITHMETIC                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the new mathematical constants 
 * introduced by c++20
 * 
 * @notes : The exaustive list of mathematical constants
 * introduced in c++20 can be found here
 * <https://en.cppreference.com/w/cpp/numeric/constants>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// math-constants.cpp -o math-constants`

#include <iostream>
#include <cmath>
#include <numbers> // Header containing the constants
#include <iomanip>
#include <functional>
#include <string_view>

using std::placeholders::_2;
template < class T >
constexpr auto operator^(T num, decltype(_2)) { return num * num; };

template<>
inline constexpr std::string_view
std::numbers::pi_v<std::string_view> = "3.14";

int main()
{
    using namespace std::numbers;

    std::cout << std::setprecision(10);

    auto angle{ pi / 6 };
    std::cout << "cos(π/6)² + sin(π/6)² = " 
              << ((std::sin(angle)^_2) + (std::cos(angle)^_2)) <<'\n';

    // Okay, that one was fun
    // From https://en.cppreference.com/w/cpp/numeric/constants
    std::cout << "The answer is " <<
        (((std::sin(e)^_2) + (std::cos(e)^_2)) + 
        std::pow(e, ln2) + std::sqrt(pi) * inv_sqrtpi +
        ((std::cosh(pi)^_2) - (std::sinh(pi)^_2)) +
        sqrt3 * inv_sqrt3 * log2e * ln2 * log10e * ln10 *
        pi * inv_pi + (phi * phi - phi)) *
        ((sqrt2 * sqrt3)^_2) << '\n';

    // The STL specializes mathematical constant variable templates
    // (std::numbers::${name}_v<T>) for all floating point types
    std::cout << "egamma = " 
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << egamma_v<long double>
              << " (I really needed that Euler-Mascheroni constant !\n";

    std::cout << "π (long double) : " 
              << std::setprecision(std::numeric_limits<long double>::digits10 + 1)
              << pi_v<long double> << '\n';

    std::cout << "π (string) : " 
              << pi_v<std::string_view>
              << " (We can provide our own specializations of"
                 " constant variable templates)\n";

    return EXIT_SUCCESS;
}

// cos(π/6)² + sin(π/6)² = 1
// The answer is 42
// egamma = 0.5772156649015328606 (I really needed that Euler-Mascheroni constant !
// π (long double) : 3.141592653589793239
// π (string) : 3.14(We can provide our own specializations of constant variable templates)
