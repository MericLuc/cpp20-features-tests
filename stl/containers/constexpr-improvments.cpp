/************************************************************
 *                     STL - CONTAINERS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows constexpr improvments on containers and
 * stl algorithms.
 * 
 * @notes : 
 * - std::vector and std::string methods are now constexpr.
 * i.e. Can be evaluated at compile time.
 * - most algorithms of the stl are now constexpr.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// constexpr-improvments.cpp -o constexpr-improvments`

#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>


consteval int maxElem(void) noexcept
{
    std::vector v{1,3,5,7,9};
    std::sort(std::begin(v), std::end(v));

    return v.back();
}

consteval int vecSize(void) noexcept 
{
    std::vector v{0,2,4,6,8};
    return std::size(v);
}


int main()
{
    constexpr int max_elem = maxElem();
    std::cout << "maxElem = " << max_elem << '\n';

    constexpr int vec_size = vecSize();
    std::cout << "vecSize = " << vec_size << '\n';

    return EXIT_SUCCESS;
}

//maxElem = 9
//vecSIze = 5