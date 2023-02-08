/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : Generalities about std::span
 *
 * A std::span is just an object that represents a continuous
 * sequence of objects. 
 * 
 * It can be created from basically any continuous sequence of 
 * objects such as a C array, a std::string, a std::vector, 
 * another std::span or even a pair of {pointer, size}.
 * 
 * std::span - just like std::string_view - is never the owner of 
 * the continuous elements it gives a view to.
 * 
 * It is typed by the type of the datas it points and have a size 
 * (extend) which can be static or dynamic.
 * 
 */

// compiled with `g++ -std=c++20 -Wall -O0 span.cpp -o span`

#include <iostream>
#include <span>
#include <ranges>
#include <vector>

int main()
{
    const int        vSize{ 100 }; 
    std::vector<int> v1, v2; 

    v1.reserve(vSize);
    for ( int elm : std::views::iota(0, vSize) ) 
        v1.push_back(elm);
    v2 = { std::crbegin(v1), std::crend(v1) };

    std::span<int>        s1{ v1 };
    std::span<int, vSize> s2{ v2 };
    /*
    span size (extend) cannot be modified.

    s2 has a static extend : That means its size
    is known at compile-time and stocked as part
    of its type definition.
    Therefore s1 only contains a pointer to the
    start of its data.

    s1 has a dynamic extend and therefore is bigger 
    in memory.
    */

    std::cout << std::size(s1) << '\n';

    std::cout << "sizeof(s1) = " << sizeof(s1) << '\n';
    std::cout << "sizeof(s2) = " << sizeof(s2) << '\n';

    return EXIT_SUCCESS;
}

// 100
// sizeof(s1) = 16
// sizeof(s2) = 8
