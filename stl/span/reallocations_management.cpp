/************************************************************
 *                        STL - SPAN                        *
 ************************************************************/

/*!
 *
 * @brief : std::span behaviour on underlying 
 * data reallocations
 *
 * This example shows some dangers of using std::span.
 * As we can see, we should ensure the underlying container
 * does not reallocate which can invalidate std::span 
 * elements (in this case, the reallocation originates from
 * a simple call to std::vector::push_back)
 */

// compiled with `g++ -std=c++20 -Wall -O0 span.cpp -o span`

#include <iostream>
#include <span>
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
    std::vector<int>  vec( 5, 42);
    std::span<int>    sp{ vec };

    infos<int>(sp, "Before reallocation");

    vec.push_back(42);
    infos<int>(sp, "After reallocation");

    return EXIT_SUCCESS;
}

// Before reallocation
// sizeof(container) = 16
// std::size(container) = 5
// 42 42 42 42 42 
// After reallocation
// sizeof(container) = 16
// std::size(container) = 5
// 0 0 -1647591408 21869 42 