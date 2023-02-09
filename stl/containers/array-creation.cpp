/************************************************************
 *                     STL - CONTAINERS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows new ways to create std::array
 * 
 * @notes : std::array can now be created from C-strings,
 * std::initializer_list or array of std::pair
 * 
 * Note that elements of the std::array are copy-initialized.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// array-creation.cpp -o array-creation`

#include <iostream>
#include <array>
#include <string>
#include <string_view>
#include <span>

template < typename T >
void print(std::span<T> cont, std::string_view mesg) noexcept
{
    std::cout << mesg << "\n\t";
    for ( const auto& elm : cont )
        std::cout << elm << ' ';
    std::cout << '\n';
}

struct myStruct {
    constexpr myStruct(double val = 0 ) noexcept : _val{ val } {}

    friend std::ostream& operator<<( std::ostream& os, 
                                     const myStruct& s ) {
        return os << s._val;
    }

    double _val;
};

int main()
{
    auto arr1{ std::to_array({1,2,3,4,5}) };
    print<int>(arr1, "Created from std::initializer_list");

    auto arr2 = std::to_array("Hello cpp20 world!");
    print<char>(arr2, "Created from C string");

    auto arr3{ std::to_array<myStruct>({1, 2, 3, 4, 5}) };
    print<myStruct>(arr3, "Created using myStruct array");

    return EXIT_SUCCESS;
}

//Created from st::initializer_list
//  1 2 3 4 5
//Created from C string
//  H e l l o  c p p 2 0  w o r l d ! 
//Created using myStruct array
//  1 2 3 4 5