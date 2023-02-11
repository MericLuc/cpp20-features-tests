/************************************************************
 *            CORE - DESIGNATED INITIALIZATION              *
 ************************************************************/

/*!
 *
 * @brief : Named (designated) initialization allows to
 * initialize class members of a class type 
 * by using their names.
 * 
 * @notes : 
 * - For an union type, only one member should
 * be provided.
 * - Each designator must name a direct non-static
 * data member of the class type.
 * - All designators used in the named initialization must
 * appear in the same order they are declared in the 
 * class type.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// named_initialization.cpp -o named_initialization`

#include <iostream>
#include <string>

struct A {

    int         a{ 42 };
    std::string str;
    char        c{ 'c' };
};

union U {
    int         a;
    const char* b;
};

int main()
{
    A elm1{ .str = "Hello cpp20 world!" };
    std::cout << elm1.a << " , " << elm1.str 
              << " , " << elm1.c << '\n';


    U elm2{ .b = "Hello world!" };
    // U elm2{ .a = 42, .b = "Does not work" };
    std::cout << elm2.b << '\n';

    // initializes str with default constructor {}
    // and c with 'a'
    A elm3{ .c = 'a' }; 
    std::cout << elm3.a << " , " << elm3.str 
              << " , " << elm3.c << '\n';

    return EXIT_SUCCESS;
}

// 42 , Hello cpp20 world! , c