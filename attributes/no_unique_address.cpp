/************************************************************
 *              ATTRIBUTES - NO_UNIQUE_ADDRESS              *
 ************************************************************/

/*!
 *
 * @brief : Demonstrate how [[no_unique_address]] attribute can be used.
 *
 * It allows data members of a class to be overlapped with other 
 * non-static data members of its class. (i.e. share the same address)
 *
 * Allows the compiler to perform space optimizations on 
 * - empty objects
 * - objects that have non-static data member(s) that may be of a type
 * that is empty.
 */

// compiled with `g++ -std=c++20 -Wall -Werror -O0 no_unique_address.cpp -o no_unique_address`

#include <iostream>


class Empty {};

struct UniqueAddress {
    int   _not_empty{};
    Empty _empty{};
};

struct NoUniqueAddress {
    int                         _not_empty{};
    [[no_unique_address]] Empty _empty{};
};

int main()
{
    std::cout << "SizeOf(UniqueAddress) = " << sizeof(UniqueAddress) << '\n';
    std::cout << "SizeOf(NoUniqueAddress) = " << sizeof(NoUniqueAddress) << '\n';

    UniqueAddress   a;
    NoUniqueAddress b;
    std::cout << "&a._not_empty = " << &a._not_empty << "\t&a._empty = " << &a._empty << '\n';
    std::cout << "&b._not_empty = " << &b._not_empty << "\t&b._empty = " << &b._empty << '\n';

    return EXIT_SUCCESS;
}

/*
SizeOf(UniqueAddress) = 8
SizeOf(NoUniqueAddress) = 4
&a._not_empty = 0x7ffc76c402b8  &a._empty = 0x7ffc76c402bc
&b._not_empty = 0x7ffc76c402b4  &b._empty = 0x7ffc76c402b4
*/