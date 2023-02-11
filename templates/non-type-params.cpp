/************************************************************
 *                     CORE - TEMPLATES                     *
 ************************************************************/

/*!
 *
 * @brief : Shows new non-type template parameters made
 * available by c++20.
 * 
 * non-type template parameters are available for a 
 * (very) long time :
 * - non-type with an optional name 
 * - pointers or reference (to objects, functions, 
 * class attributes...)
 * - enumeration type
 * - integral type (Hello std::array<T, 42>)
 * - std::nullptr_t (since c++11)
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// non-type-params.cpp -o non-type-params`

#include <iostream>
#include <cassert>

/*
  c++20 added the folowing non-type template parameters
  to the list :
  - floating-point type
  - literal class type that respect the following conditions
    * All base classes and non-static data members are 
      public and immutable
    * All base classes and non-static members have structural
      types or array thereof.
  Note that :
  - A literal type must have a constexpr constructor
  - A template parameter object shall have constant destruction
*/

// https://en.cppreference.com/w/cpp/language/template_parameters
struct A
{
    friend bool operator==(const A&, const A&) = default;
};
 
template<A a>
void f()
{
    const A& ra = a, &rb = a; // Both bound to the same template parameter object
    assert(&ra == &rb);       // passes

    std::cout << "f<a>\n";
}

template < int Sz >
class B {
public:
  constexpr B( char const (&in)[Sz] ) noexcept {
    std::copy(in, in + Sz, _v);
  }

  char _v[Sz];
};

// Class B is a literal type and can therefore be used
// as template parameter of class C
template < B b  >
class C {
  friend std::ostream& operator<<(std::ostream& os,
          const C& c) noexcept {
    return os << b._v << '\n';
  }
};

template < B b >
void templateFn() { std::cout << b._v << '\n'; }

int main()
{
    A a;
    f<a>();

    C<"Hello c++20 world!"> c;
    std::cout << c;

    templateFn<"Hello c++20 world!">();

    return EXIT_SUCCESS;
}

// f<a>
// Hello c++20 world!
// Hello c++20 world!
