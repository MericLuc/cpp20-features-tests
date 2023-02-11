/************************************************************
 *            CORE - DESIGNATED INITIALIZATION              *
 ************************************************************/

/*!
 *
 * @brief : Aggregate initialization is the initialization
 * of an aggregate from an initializer list.
 * 
 * An aggregate is either an array type or a class type
 * (struct or union) that respects aggregate initialization
 * conditions.
 * 
 * C++20 provides conditions for a class type
 * to support aggregate initialization :
 * - no user-declared or inherited constructors
 * - no private or protected non-static data members
 * - no virtual base classes
 * - no private or protected direct base classes
 * - no virtual member functions
 * 
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// aggregate_initialization.cpp -o aggregate_initialization`

#include <iostream>
#include <array>

struct A {

    int a;

    class B {
    public:
        int  _b;
        char _c;
    } b;
};

struct Base1 {
    int b1, b2 = 42;
};

struct Base2 {
    int b3;

    constexpr Base2() noexcept : b3{42} {}
};

struct Derived : Base1, Base2 {
    int d;
};

int main()
{
    // A object is initialized with
    // a = 42 and b = B( _b = 0, _c = 'b' )
    {
        A elm{ 42, {0, 'b'} };
        std::cout << elm.a << " , " 
                  << elm.b._b << " , " 
                  << elm.b._c << '\n';
    }

    // Derived element initializes b1, b2 with 1,2
    // b3 with default Base2 constructor (which is 42)
    // and d with 3
    {
        Derived elm{ {1,2}, {}, 3 };
        std::cout << elm.d << " , " 
                  << elm.b1 << " , "
                  << elm.b2 << " , "
                  << elm.b3 << '\n';
    }

    // An array of char types can be initialized 
    // from ordinary string literals or UTF-8 string literals
    {
        char arr[] = "Hello cpp20 world!";
        std::cout << arr << '\n';
    }

    // Same applies for std::array
    {
        std::array<char, 12> arr2{ {'H', 'e', 'l', 'l', 
                        'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'} };
        for ( const auto& c : arr2 ) std::cout << c;
        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}

// 42 , 0 , b
// 3 , 1 , 2 , 42
// Hello cpp20 world!
// Hello World!
