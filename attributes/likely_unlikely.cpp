/************************************************************
 *              ATTRIBUTES - LIKELY/UNLIKELY                *
 ************************************************************/

/*!
 *
 * @brief : Demonstrate of likely/unlikely attributes can be used to give hints to the optimizer.
 * Use it to mark paths of executions that are more/less likely.
 */

// compiled with `g++ -std=c++20 -Wall -Werror -O0 likkely_unlikely.cpp -o likkely_unlikely`

#include <ranges>
#include <iostream>

int main()
{
    auto cmpt{ 0 };
    for ( const auto& elm : std::views::iota(-10) | std::views::take(11) ) {
        if ( elm < 0 ) [[likely]] ++cmpt;
        else [[unlikely]] --cmpt;
    }

    std::cout << cmpt << '\n';

    return EXIT_SUCCESS;
}