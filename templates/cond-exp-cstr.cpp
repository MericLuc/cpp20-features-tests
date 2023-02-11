/************************************************************
 *                     CORE - TEMPLATES                     *
 ************************************************************/

/*!
 *
 * @brief : Show how to write generic constructors
 * with explicit expressions
 * 
 * explicit(bool) allow to simplify the implementation
 * of generic types
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// cond-exp-cstr.cpp -o cond-exp-cstr`

#include <iostream>

/*
    In order to provide classes that allow construction
    with implicit conversions when it is possible, and
    explicit when it is not possible, we had to do SFINAE. 

    That means 2 overloads + a compile-time cost, breaking
    the c++ promise: "you pay for what you need"
*/
// From https://devblogs.microsoft.com/cppblog/c20s-conditionally-explicit-constructors
#if ___cplusplus >= 201103L
template<class T>
struct oldWrapper {
  template<class U, std::enable_if_t<std::is_convertible_v<U, T>>* = nullptr>
  oldWrapper(U const& u) : t_(u) {}
  
  template<class U, std::enable_if_t<!std::is_convertible_v<U, T>>* = nullptr>
  explicit oldWrapper(U const& u) : t_(u) {}

  T t_;
};
#endif // 201103L

// Here is the solution using the 'explicit(bool)' c++20 feature
#if ___cplusplus >= 202003L
template<class T> 
struct newWrapper { 
  template<class U> 
  explicit(!std::is_convertible_v<U, T>) 
  newWrapper(U const& u) : t_(u) {
    std::cout << "newWrapper<" << typeid(T).name() 
              << "> : " << u << " (" << typeid(U).name() << ")\n";
  } 

  T t_; 
};
#endif // 202003L

int main()
{
    // OK - int is convertible to bool
    newWrapper<bool> A{ 1 };
    // OK - char is convertible to int
    newWrapper<int> B{ 'A' };
    // KO - int is not convertible to string
    // newWrapper<std::string> B{ 1 };

    return EXIT_SUCCESS;
}

// newWrapper<b> : 1 (i)
// newWrapper<i> : A (c)