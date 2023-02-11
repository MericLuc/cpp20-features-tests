/************************************************************
 *                 CORE - MISCELLANEOUS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the new possibility to declare
 * constexpr virtual functions.
 * 
 * It basically gives the ability to execute
 * polymorphism at compile-time.
 * 
 * @notes : 
 * - A constexpr function can override a non-constexpr function
 * - A non-constexpr function can override a constexpr function
 * - A constexpr function can override a constexpr function
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// virtual-constexpr.cpp -o virtual-constexpr`

#include <iostream>
#include <memory>
#include <string_view>

struct Base {
  constexpr virtual std::string_view f(void) noexcept { 
    return "constexpr Base\n";
  }

  virtual std::string_view g(void) noexcept {
    return "non-constexpr Base\n";
  }
};

struct Derived : Base {
  constexpr std::string_view f(void) noexcept override {
    return "constexpr Derived\n";
  }

  std::string_view g(void) noexcept override {
    return "non-constexpr Derived\n";
  }
};

int main()
{
    auto b{ std::make_unique<Base>() };
    auto d{ std::make_unique<Derived>() };

    std::cout << b->f();
    std::cout << b->g();

    std::cout << d->f();
    std::cout << d->g();

    return EXIT_SUCCESS;
}