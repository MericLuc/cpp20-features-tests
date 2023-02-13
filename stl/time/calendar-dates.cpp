/************************************************************
 *                 STL - TIME AND CALENDAR                  *
 ************************************************************/

/*!
 *
 * @brief : Shows the new calendar utilities. 
 * 
 * @notes : For more informations, see 
 * <https://en.cppreference.com/w/cpp/chrono>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// calendar-dates.cpp -o calendar-dates`

#include <iostream>
#include <chrono>

int main()
{
    using namespace std::chrono;

    // A `calendar date` is a date of the gregorian
    // calendar that consists in a year, month and day.

    // Create calendar dates using the 
    // std::chrono::year_month_day class
    // https://en.cppreference.com/w/cpp/chrono/year_month_day
    {
      std::cout << "\nCreate calendar dates\n";

      constexpr year_month_day 
        d1{ year{1991}, May, day{22} };
      std::cout << "Using explicit type : " << d1 << '\n';

      // The operator / overloading allows to 
      // use the so called 'cute syntax'
      constexpr year_month_day 
        d2{ year{2019}/month{9}/day{10} };
      std::cout << "Using 'cute' syntax : " << d2 << '\n';

      constexpr year_month_day_last 
        d3{ year{689}, month_day_last(month{12}) };
      std::cout << "Using month_day_last : " << d3 << '\n';

      constexpr year_month d4{ year{2023}/month{1} };
      std::cout << "Using year_month : " << d4 << '\n';

      constexpr month_day d5{ month{1}/day{10} };
      std::cout << "Using month_day : " << d5 << '\n';
    }

    // Display calendar dates
    {
      // The year_month_day::sys_days operator
      // allows to convert *this to a time_point
      // representing the same date.
      std::cout << "\nDisplay calendar dates\n";

      constexpr auto d1{ 2023y/January/10 };
      std::cout << "Display using sys_days: " 
                << sys_days(d1) << '\n';

      constexpr auto d2{ 2019y/April/last };
      std::cout << "Display using sys_days: " 
                << sys_days(d2) << '\n';
    }

    // Check calendar dates validity
    {
      // This is performed by the 'ok()' method
      std::cout << std::boolalpha;
      std::cout << "\nCheck calendar dates validity\n";

      day d31{ 31 };
      day d32{ d31 + days{1} };
      std::cout << d31 << " : " << d31.ok() << '\n';
      std::cout << d31 << " : " << d32.ok() << '\n';

      constexpr auto ly2016{ year(2016)/2/29 };
      constexpr auto ly2024{ year(2024)/2/29 };
      constexpr auto ly2042{ day(29)/2/2042  };

      std::cout << ly2016 << " : " << ly2016.ok() << '\n';
      std::cout << ly2024 << " : " << ly2024.ok() << '\n';  
      std::cout << ly2042 << " : " << ly2042.ok() << '\n';  
    }

    // Query calendar dates
    {
      // It is really straight-forward to query
      // calendar dates from a std::chrono::duration
      std::cout << "\nQuery calendar dates\n";

      auto now{ system_clock::now() };
      std::cout << "Current time : " << now << '\n';
      std::cout << "Current time : " << floor<days>(now) << '\n';

      auto curDate{ year_month_day(floor<days>(now)) };
      std::cout << "Current year : " << curDate.year() << '\n';

      auto sLastY{ floor<seconds>(now) - sys_days(January/1/curDate.year()) };
      std::cout << "Seconds since new year : " << sLastY << '\n';
    }


    return EXIT_SUCCESS;
}

// Create calendar dates
// Using explicit type : 1991-05-22
// Using 'cute' syntax : 2019-09-10
// Using month_day_last : 0689/Dec/last
// Using year_month : 2023/Jan
// Using month_day : Jan/10

// Display calendar dates
// Display using sys_days: 2023-01-10
// Display using sys_days: 2019-04-30

// Check calendar dates validity
// 31 : true
// 31 : false
// 2016-02-29 : true
// 2024-02-29 : true
// 2042-02-29 is not a valid date : false

// Query calendar dates
// Current time : 2023-02-13 10:50:29.865925210
// Current time : 2023-02-13
// Current year : 2023
// Seconds since new year : 3754229s