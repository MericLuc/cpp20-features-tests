/************************************************************
 *                     STL - CONTAINERS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows how the new std::contains works
 * on associative containers.
 * 
 * @note : It was possible (for quite a long time) to test the
 * presence of an element in an associative container using :
 * - std::count
 * - std::find
 * 
 * But those methods had substantial drawbacks :
 * - std::find is really verbose and frankly quite cumbersome to use
 * - std::count has a performance issue since it, well, counts
 * every occurences instead of stopping when one is found.
 */

// compiled with `g++ -std=c++20 -Wall -O0 
// contains_associative_containers.cpp -o contains_associative_containers`

#include <iostream>
#include <map>
#include <ranges>

template < typename T, typename U >
void print(const std::map<T, U>& cont, std::string_view mesg) noexcept {
    std::cout << mesg << "\n";
    for ( const auto& [key, val] : cont )
        std::cout << '\t' << key << " - " << val << '\n';
    std::cout << '\n';
}

int main()
{
    std::map<char, int> m;
    char                cToFind{ 'z' };

    for ( const auto& elm : std::views::iota('a') | 
                            std::views::take(26) )
        m[elm] = elm;

    print<char, int>(m, "Printing map elements");

    // Test presence of 'z' using std::find
    {
        if ( auto it{ m.find('k') }; std::end(m) != it ) {
            std::cout << "map contains '" << cToFind << "\n";
        }
    }

    // Test presence of 'z' using std::count
    {
        if ( auto occ{ m.count('z') }; 0 != occ ) {
            std::cout << "map contains '" << cToFind << "' (" << occ << " occurence(s))\n";
        }
    }

    // Test presence of 'z' using new std::contains
    {
        std::cout << "map " << ( m.contains(cToFind) ? "contains"
            : "does not contain") << " '" << cToFind << "'\n";
    }


    return EXIT_SUCCESS;
}

// Printing map elements
//     a - 97
//     b - 98
//     c - 99
//     d - 100
//     e - 101
//     f - 102
//     g - 103
//     h - 104
//     i - 105
//     j - 106
//     k - 107
//     l - 108
//     m - 109
//     n - 110
//     o - 111
//     p - 112
//     q - 113
//     r - 114
//     s - 115
//     t - 116
//     u - 117
//     v - 118
//     w - 119
//     x - 120
//     y - 121
//     z - 122

// map contains 'z
// map contains 'z' (1 occurence(s))
// map contains 'z'
