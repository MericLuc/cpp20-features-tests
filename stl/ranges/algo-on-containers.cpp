/************************************************************
 *                       STL - RANGES                       *
 ************************************************************/

/*!
 *
 * @brief : Conveniently use std::ranges algorithms on 
 * STL containers.
 * 
 * @notes : std::ranges declares its own version of
 * STL algorithms defined in the 'algorithm' header
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// algo-on-containers.cpp -o algo-on-containers`

#include <algorithm>
#include <iostream>
#include <vector>
#include <string_view>
#include <ranges>
#include <numeric>
#include <random>

void printFn(std::ranges::input_range auto&& rr, std::string_view mesg) noexcept
{
    std::cout << mesg << "\n\t";
    std::ranges::for_each(rr, [](const auto& elm) {       
        std::cout << elm << ' ';
    });
    std::cout << '\n';
}

int main()
{
    // Creating a range of 1000 ints
    std::vector<int> vec(1000);
    std::iota(vec.begin(), vec.end(), -500);

    // shuffle it all !
    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::ranges::shuffle(vec, gen);

    printFn(vec | 
            std::views::reverse | 
            std::views::take(10), "last 10 elements of shuffled vector");

    // Sort it using std::ranges::sort
    std::ranges::sort(vec);

    auto filtered{ vec | std::views::reverse 
                       | std::views::take(10) };
    
    printFn(filtered, "last 10 elements of sorted vector");

    return EXIT_SUCCESS;
}

// last 10 elements of shuffled vector
//     -27 330 318 -228 323 -325 -46 -252 80 -354 
// last 10 elements of sorted vector
//     499 498 497 496 495 494 493 492 491 490 

