/************************************************************
 *                       STL - RANGES                       *
 ************************************************************/

/*!
 *
 * @brief : Explain the concepts and concepts behind 
 * the std::ranges library
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// concepts.cpp -o concepts`

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

int main()
{
    // WHAT IS A RANGE ?
    /*
    The concept of `range` basically only means an iterable object
    that provides the begin() and end() methods were :
    - begin() is an iterator 
    - end() is a sentinel delimiting the end of the interval

    template< class T >
    concept range = requires( T& t ) {
      ranges::begin(t); // equality-preserving for forward iterators
      ranges::end  (t);
    };

    That means that stl containers and string are ranges 
    (among others).
     */

    // WHAT IS A VIEW ?
    /*
    A `view` is a range that does not own any data but rather
    uses ones of another range. It is applied on ranges to
    perform operations on it.

    To be a view, the class T requires :
    - To be a movable range 
    - A move construction in constant time complexity
    - A copy_construction in constant time complexity (or false)
    - A copy_asignement has no more time complexity than destruction 
    followed by copy construction

    template<class T>
    concept view = ranges::range<T> && std::movable<T> && ranges::enable_view<T>;

    template<class T>
    inline constexpr bool enable_view =
        std::derived_from<T, view_base> || <T>;
    
    struct view_base { };
    */

    // Creating a range of 1000 ints
    std::vector<int> vec(1000);
    std::iota(vec.begin(), vec.end(), -500);

    // Applying views on it in a functional style
    auto filtered{ vec | std::views::filter([](int i){ return i > 0 && 0  == i % 2; })
                       | std::views::reverse 
                       | std::views::take(10) };
    
    printFn(filtered, "last 10 even elements");

    return EXIT_SUCCESS;
}

// last 10 even elements
//     498 496 494 492 490 488 486 484 482 480 
