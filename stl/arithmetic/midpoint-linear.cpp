/************************************************************
 *                     STL - ARITHMETIC                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the new arithmetic functions to perform
 * midpoint and linear interpolation.
 * 
 * @notes :
 * - std::midpoint(T a, T b) computes the midpoint of
 * integers, floating-points or pointers a and b
 * <https://en.cppreference.com/w/cpp/numeric/midpoint>
 * - std::lerp(float a, float b, float t) computes
 * the linear interpolation between a and b, if t is 
 * inside [0, 1] (the linear extrapolation otherwise).
 * i.e. a + t(b - a)
 * <https://en.cppreference.com/w/cpp/numeric/lerp>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// midpoint-linear.cpp -o midpoint-linear`

#include <iostream>
#include <cstdint>
#include <numeric>
#include <limits>
#include <cmath>

int main()
{
    // Note that std::midpoint can avoid overflow issues
    {
      auto a{ std::numeric_limits<std::uint32_t>::max() },
           b{ std::numeric_limits<std::uint32_t>::max() };

      std::cout << "a = b = " << a << '\n';
      std::cout << "Overflow (a + b)/2 : " 
                << (a + b)/2 << '\n';
      std::cout << "Correct std::midpoint(a,b) = " 
                << std::midpoint(a,b) << '\n';
    }

    // Note that the std::midpoint(T* a, T* b) overload
    // is intended for pointer arithmetic purposes
    // It's behaviour is only defined if a and b are elements
    // of the same array object.
    // (i.e. a = x[i] and b = x[j] 
    // => std::midpoint(a,b) = x[i + (j -i) / 2])
    {
      std::string str{ "Hello c++20 world!" };
      const char* a{ &str[0] }, *b{ &str[0] + 17 };
      std::cout << "pointers arithmetic (on string elements)\n";
      std::cout << "str : " << str << '\n';
      std::cout << "std::midpoint(" << *a 
                << ", " << *b << ") = " << *std::midpoint(a, b) << '\n';
    }


    // Note that std::lerp has a set of overloads
    // for all combinations of arguments of arithmetic type
    // which cast arguments of integral type to double.
    // If any other arguments is long double then the
    // return type is long double, otherwise double.
    {
      std::cout << std::boolalpha;
   
      const float a = 1e8f, b = 1.0f;
      const float midpoint = std::lerp(a, b, 0.5f);
   
      std::cout << "a = " << a << ", " << "b = " << b << '\n'
                << "midpoint = " << midpoint << '\n';
    }

    return EXIT_SUCCESS;
}

// a = b = 4294967295
// Overflow (a + b)/2 : 2147483647
// Correct std::midpoint(a,b) = 4294967295
// pointers arithmetic (on string elements)
// str : Hello c++20 world!
// std::midpoint(H, !) = +
// a = 1e+08, b = 1
// midpoint = 5e+07
