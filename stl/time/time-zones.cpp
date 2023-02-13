/************************************************************
 *                 STL - TIME AND CALENDAR                  *
 ************************************************************/

/*!
 *
 * @brief : Shows how to use the time_zone class
 * 
 * @notes : For more informations, see 
 * <https://en.cppreference.com/w/cpp/chrono/time_zone>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// time-zones.cpp -o time-zones`

#include <iostream>
#include <chrono>

int main()
{
    using namespace std::chrono;

    /*
      The class tim_zone represents all time zone
      transitions for a specific geographic area.

      This is not possible to construct nor copy a 
      time_zone object, they are parsed from the
      IANA timezone database.

      There are only const access to time_zone objects.
    */

    // This pointer cannot be nullptr
    // Otherwise an exception is thrown
    // terminate called after throwing an instance of 
    // 'std::runtime_error'
    // what():  tzdb: cannot determine current zone
    const time_zone* tz{ current_zone() };

    // In this case, time_point is in the scope of
    // system_clock, and have it as their template
    // argument.
    // Therefore the epoch is 00:00:00 Jan 1, 1970
    // independant from the time zone.
    time_point p1{ krn::system_clock::now() };

    // Now, the template argument for p2
    // is std::chrono::local_t
    // p2 represents the nb of seconds from
    // epoch in the desired time zone.
    time_point p2{ tz->to_local(p1) };

    return EXIT_SUCCESS;
}
