/************************************************************
 *                 CORE - MISCELLANEOUS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the new possibility to use enum
 * in local scopes
 * 
 * It allows to introduce the enumerators of the named
 * enum into the local scope
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// enum-local.cpp -o enum-local`

#include <iostream>

enum class 
[[nodiscard("You should check the retCode!")]]
RetCode {
  DEBUG,
  INFO,
  NOTICE,
  WARNING,
  ERROR,
  CRITICAL
};

auto operation(const RetCode& rc) noexcept {
  switch ( rc ) {

    using enum RetCode;

    case DEBUG: return "DEBUG"; break;
    case INFO: return "INFO"; break;
    case NOTICE: return "NOTICE"; break;
    case WARNING: return "WARNING"; break;
    case ERROR: return "ERROR"; break;
    case CRITICAL: return "CRITICAL"; break;
  }
  return "ERROR";
}

int main()
{
    std::cout << operation(RetCode::NOTICE) << '\n';

    return EXIT_SUCCESS;
}

// NOTICE