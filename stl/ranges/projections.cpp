/************************************************************
 *                       STL - RANGES                       *
 ************************************************************/

/*!
 *
 * @brief : What are range projections and how to use them
 * 
 * @notes : projections are mappings of a set into a subset.
 * They are used by the rangified versions of many STL algorithms
 * 
 * Here is a very interesting article about it
 * https://www.modernescpp.com/index.php/projections-with-ranges
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// projections.cpp -o projections`

#include <algorithm>
#include <iostream>
#include <vector>
#include <string_view>
#include <ranges>
#include <numeric>

void printFn(std::ranges::input_range auto& rr, std::string_view mesg) noexcept
{
    std::cout << mesg << "\n\t";
    std::ranges::for_each(rr, [](const auto& elm) {       
        std::cout << elm << ' ';
    });
    std::cout << '\n';
}

struct CapitalCity {
    std::string country;
    std::string city;

    friend std::ostream& operator<<(std::ostream& os, const CapitalCity& c) noexcept {
        return os << "{ " << c.country << " , " << c.city << " } "; 
    }
};

int main()
{
    std::vector<int> vec(10);
    std::iota(std::begin(vec), std::end(vec), -10);

    // std::ranges::sort can be used with
    // - a Sortable range Range
    // - a predicate Pred (comparison) which defaults to std::less
    // - a projection Proj which defaults to identity

    std::ranges::sort(vec, {}, [](auto& val){ return abs(val); });

    printFn(vec, "Sorted by absolute values");

    std::vector<CapitalCity> capitalCities{
        {"France", "Paris"}, {"Spain", "Madrid"}, {"Portugal", "Lisbone"},
        {"Italy", "Rome"}, {"Germany", "Berlin"}, {"Belgium", "Bruxelles"},
        {"Azeroth", "Orgrimar"}
    };

    std::ranges::sort( capitalCities, 
                       std::ranges::greater{},
                       &CapitalCity::country );

    printFn(capitalCities, "Sorted by greater countries");

    return EXIT_SUCCESS;
}

// Sorted by absolute values
//     -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 
// Sorted by greater countries
//     { Spain , Madrid }  { Portugal , Lisbone }  { Italy , Rome }  { Germany , Berlin }  { France , Paris }  { Belgium , Bruxelles }  { Azeroth , Orgrimar }  
