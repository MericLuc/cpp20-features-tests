/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : Shows how a std::span can modify its view.
 * 
 * @notes : That fact therefore constitutes the main difference
 * between std::span<std::string> and std::string_view
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

int main()
{
    std::array<int, 10> arr{ 0 };

    // Modify the entire std::span
    std::span<int> s1{ arr };
    for ( size_t i{0}; i < std::size(s1); ++i )
        s1[i] += i;

    // Modify only a subsection of std::span
    std::span<int> s2{ s1.subspan( 0 , 5) };
    std::for_each( std::begin(s2), 
                   std::end(s2), [](auto& val) {
                    val = 1;
                   } );

    infos<int>(arr, "Infos about underlying container");

    return EXIT_SUCCESS;
}

// Infos about underlying container
// sizeof(container) = 16
// std::size(container) = 10
// 1 1 1 1 1 5 6 7 8 9 
