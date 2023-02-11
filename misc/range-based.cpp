/************************************************************
 *                 CORE - MISCELLANEOUS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the new possibility to perform
 * range-based for loop with initializers.
 * 
 * @notes : Not a revolution, but still pretty nice
 * for consiceness
 * 
 * It follows the exact same evolution of the c++17
 * in if else instructions.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O3
// range-based.cpp -o range-based`

#include <iostream>
#include <vector>

int main()
{
  for ( const auto v{ std::vector{42, 0, 42} }; const auto& elm : v )
    std::cout << elm << ' ';
  std::cout << '\n';

    return EXIT_SUCCESS;
}

// 42 0 42