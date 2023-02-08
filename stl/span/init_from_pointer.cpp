/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : Shows how a std::span can be initialized
 * from a pointer and a size.
 * 
 */

// compiled with `g++ -std=c++20 -Wall -O0 span.cpp -o span`

#include <iostream>
#include <span>
#include <array>

template <typename T>
void infos(std::span<T> s, std::string_view msg) noexcept {
    std::cout << msg << '\n';
    std::cout << "sizeof(container) = " << sizeof(s) << '\n';
    std::cout << "std::size(container) = " << std::size(s) << '\n';

    for ( const auto& elm : s )
        std::cout << elm << " ";
    std::cout << '\n';
}

struct myType {
    int _val;

    constexpr myType(int val) noexcept : _val{val} {}
    friend std::ostream& operator<<(std::ostream& os, 
                                    const myType& t) noexcept {
        return os << "myType(" << t._val << ")";
    }
};

int main()
{
    std::array<myType, 5> arr{ 1, 2, 3, 4, 5 };
    infos<myType>( {arr.data(), std::size(arr)}, 
                "Init from pointer and size");

    return EXIT_SUCCESS;
}

// Init from pointer and size
// sizeof(container) = 16
// std::size(container) = 5
// myType(1) myType(2) myType(3) myType(4) myType(5) 
