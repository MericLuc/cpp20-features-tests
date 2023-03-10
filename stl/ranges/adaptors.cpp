/************************************************************
 *                       STL - RANGES                       *
 ************************************************************/

/*!
 *
 * @brief : What are range adaptors and how to use them
 * 
 * @notes : 
 * - range adaptors allow to create views by
 * transforming a range (which can be a view) in a view.
 * - views can also be created by data generated by 
 * range factories
 * 
 * Here is a very interesting article about it
 * https://brevzin.github.io/c++/2021/02/28/ranges-reference
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// adaptors.cpp -o adaptors`

#include <algorithm>
#include <iostream>
#include <vector>
#include <string_view>
#include <ranges>
#include <numeric>
#include <unordered_map>

void printFn(std::ranges::input_range auto& rr, std::string_view mesg) noexcept
{
    std::cout << mesg << "\n\t";
    std::ranges::for_each(rr, [](const auto& elm) {       
        std::cout << elm << ' ';
    });
    std::cout << '\n';
}

int main()
{
    // There are a lot of range adaptors
    // counted
    // filter
    // transform
    // take - take_while
    // drop - drop_while
    // join - split
    // common
    // reverse
    // elements, keys, values

    // Here are also some range factories
    // iota
    // single
    // istream_view
    // empty_view

    auto cubesUnder1000{ std::views::iota(0) |
                         std::views::transform([](int i){ return i * i * i; }) |
                         std::views::take_while([](int i){ return i < 1000; }) };
    
    printFn(cubesUnder1000, "cubes under 1000");

    std::unordered_map<std::string, std::string> capitalCities{
        {"France", "Paris"}, {"Spain", "Madrid"}, {"Portugal", "Lisbone"},
        {"Italy", "Rome"}, {"Germany", "Berlin"}, {"Belgium", "Bruxelles"},
        {"Azeroth", "Orgrimar"}
    };

    auto capitalsWithMoreThan5Letters{
        capitalCities | std::views::values | 
        std::views::filter([](const auto& name){ return std::size(name) > 5; })
    };

    printFn(capitalsWithMoreThan5Letters, "Capital cities whose name has more than 5 letters");

    return EXIT_SUCCESS;
}

// cubes under 1000
//     0 1 8 27 64 125 216 343 512 729 
// Capital cities whose name has more than 5 letters
//     Orgrimar Lisbone Berlin Madrid Bruxelles 

