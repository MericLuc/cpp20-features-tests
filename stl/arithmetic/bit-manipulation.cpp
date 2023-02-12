/************************************************************
 *                     STL - ARITHMETIC                     *
 ************************************************************/

/*!
 *
 * @brief : Show the new bit (and bit sequences)
 * manipulation introduced by c++20
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// bit-manipulation.cpp -o bit-manipulation`

#include <iostream>
#include <bit> // c++20 bit manipulation header
#include <bitset>

int main()
{
    /*
    std::endian allows to get the endianness of scalar
    types :
    - integral types
    - pointer
    - enum
    - member pointer
    - std::nullptr_t
    */
    {
        if constexpr ( std::endian::native == 
                       std::endian::big ) {
            std::cout << "Let's perform compilation for Big endian" 
            " architecture\n";
        } else if constexpr ( std::endian::native == 
                              std::endian::little ) {
            std::cout << "Let's perform compilation for Little endian" 
            " architecture\n";
        }
    }

    /*
    c++20 - via its <bit> header - also provides
    a dozen of bit manipulation functions.
    
    The list can be found here
    <https://en.cppreference.com/w/cpp/header/bit>
    */
    {
        uint8_t i{ 0b00101010 };
        std::cout << "The answer is " << std::bitset<8>(i) << '\n';
        std::cout << std::boolalpha;
        std::cout << "Has single bit : " << std::has_single_bit(i) << '\n';
        std::cout << "bit_ceil : " << 
            std::bitset<8>(std::bit_ceil(i)) << '\n';
        std::cout << "bit_floor : " << 
            std::bitset<8>(std::bit_floor(i)) << '\n';
        std::cout << "bit_width : " << 
            static_cast<int>(std::bit_width(i)) << '\n';
        std::cout << "countl_zero : " <<
            static_cast<int>(std::countl_zero(i)) << '\n';
        std::cout << "countl_one : " <<
            static_cast<int>(std::countl_one(i)) << '\n';
        std::cout << "popcount : " <<
            static_cast<int>(std::popcount(i)) << '\n';
    }

    return EXIT_SUCCESS;
}

// Let's perform compilation for Little endian architecture
// The answer is 00101010
// Has single bit : false
// bit_ceil : 01000000
// bit_floor : 00100000
// bit_width : 6
// countl_zero : 2
// countl_one : 0
// popcount : 3
