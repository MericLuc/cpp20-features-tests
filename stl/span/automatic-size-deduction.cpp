/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : Taking advantage of utomatic size deduction 
 * of continuous objects sequence using std::span.
 *
 * This example shows how easy/powerful std::span is,
 * especially to use in functions that operate on 
 * continuous objects sequence.
 * 
 * Remember, a std::span is a lightweight reference-types 
 * to contiguous storage.
 * 
 */

// compiled with `g++ -std=c++20 -Wall -O0 span.cpp -o span`

#include <iostream>
#include <span>
#include <ranges>
#include <array>
#include <vector>

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
    std::vector        vec( 5, 42);
    std::array<int, 5> arr{ 1, 2, 3, 4, 5}; 
    int                cPtr[]{ 5, 4, 3, 2, 1};

    infos<int>(vec, "Passing a std::vector");
    infos<int>(arr, "Passing a std::array");
    infos<int>(cPtr, "Passing a c array");

    return EXIT_SUCCESS;
}

// Passing a std::vector
// sizeof(container) = 16
// std::size(container) = 5
// 42 42 42 42 42 
// Passing a std::array
// sizeof(container) = 16
// std::size(container) = 5
// 1 2 3 4 5 
// Passing a c array
// sizeof(container) = 16
// std::size(container) = 5
// 5 4 3 2 1 
