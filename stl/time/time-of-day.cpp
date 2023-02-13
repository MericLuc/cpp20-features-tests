/************************************************************
 *                 STL - TIME AND CALENDAR                  *
 ************************************************************/

/*!
 *
 * @brief : Shows the usage of std::chrono::hh_mm_ss
 * 
 * @notes : For more informations, see 
 * <https://en.cppreference.com/w/cpp/chrono/hh_mm_ss>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// time-of-day.cpp -o time-of-day`

#include <iostream>
#include <chrono>

int main()
{
    // This class represents a duration since midnight
    // split into hours, min, seconds and fraction seconds.
    /*
    template < class Duration >
    class hh_mm_ss;

    Duration must be a specialization of std::chrono::duration
    */

    using namespace std::chrono_literals;

    std::cout << std::boolalpha;

    // Construct an object representing duration zero
    // std::chrono::duration::zero()
    constexpr std::chrono::hh_mm_ss tDayZero{ std::chrono::seconds::zero() };
    

    constexpr std::chrono::hh_mm_ss tDay{ 12h + 98min + 76s };

    std::cout << "duration::zero() time : " 
              << tDayZero.hours() 
              << tDayZero.minutes() 
              << tDayZero.seconds()
              << '\n';
    std::cout << "initialized with a std::chrono::duration : "
              << tDay.hours() 
              << tDay.minutes()
              << tDay.seconds()
              << '\n';

    // It is directly usable with streams
    // and therefore can be a good formatting tool
    std::cout << "Direct output to stream : " << tDay << '\n';

    return EXIT_SUCCESS;
}

// duration::zero() time : 0h0min0s
// initialized with a std::chrono::duration : 13h39min16s
// Direct output to stream : 13:39:16