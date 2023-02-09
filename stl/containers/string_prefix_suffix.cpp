/************************************************************
 *                     STL - CONTAINERS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows how the new methods on strings prefix/suffix
 * checking work.
 * 
 * THose functions can be invoked on a std::string, a std::string_view
 * or a char.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 string_prefix_suffix.cpp -o string_prefix_suffix`

#include <iostream>
#include <string>
#include <string_view>


int main()
{
    std::string      s{"Hello Cpp20 World!"};
    std::string_view sv_prefix{"Hello"};
    char             c_suffix{'!'};

    std::cout << std::boolalpha;
    std::cout << '"' << s << '"' << " : starts_with '" 
              << sv_prefix << "'? " << s.starts_with(sv_prefix) 
              << '\n';
    std::cout << '"' << s << '"' << " : ends_with '" 
              << c_suffix << "'? " << s.ends_with(c_suffix) 
              << '\n';

    return EXIT_SUCCESS;
}

// "Hello Cpp20 World!" : starts_with 'Hello'? true
// "Hello Cpp20 World!" : ends_with '!'? true
