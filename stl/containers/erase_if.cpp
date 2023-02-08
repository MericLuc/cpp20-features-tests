/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : Shows how the new std::erase_if works.
 * 
 * @note : That feature performs correct erasure of elements 
 * without requiring to implement that good old erase-remove
 * idiom.
 */

// compiled with `g++ -std=c++20 -Wall -O0 erase_if.cpp -o erase_if`

#include <iostream>
#include <numeric>
#include <vector>
#include <span>

template < typename T >
void print(std::span<T> s, std::string_view mesg) noexcept {
    std::cout << mesg << "\n\t";
    for ( const auto& elm : s )
        std::cout << elm << " ";
    std::cout << '\n';
}

int main()
{
    std::vector<int> v1(20), v2(20);
    std::iota( std::rbegin(v1), std::rend(v1), 0 );
    v2 = v1;

    // 'Old way'
    v1.erase( std::remove_if( std::begin(v1), 
                              std::end(v1), 
                              [](int i) { return 0 == i % 2; }), 
        std::end(v1) );

    print<int>(v1, "v1 After erase-remove_if idiom");

    // 'New way'
    std::erase_if( v2, [](int i){ return 1 == i % 2; } );

    print<int>(v2, "v2 After std::erase_if");

    return EXIT_SUCCESS;
}

// v1 After erase-remove_if idiom
//     19 17 15 13 11 9 7 5 3 1 
// v2 After std::erase_if
//     18 16 14 12 10 8 6 4 2 0 
