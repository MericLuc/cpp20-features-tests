/************************************************************
 *                      STL - LAMBDAS                       *
 ************************************************************/

/*!
 *
 * @brief : Shows how c++20 stateless lambdas can be used in
 * unevaluated contexts.
 * 
 * @notes : Let's define some important terms
 * - stateless lamdas : A lambda that does not capture
 * - unevaluated contexts : https://stackoverflow.com/questions/35088599/what-are-unevaluated-contexts-in-c 
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// unevaluated-contexts.cpp -o unevaluated-contexts`

#include <iostream>
#include <memory>

// Here we use a stateless lambda in an unevaluated context
// to define a unique_ptr class with a custom deleter function.
template<typename T, auto DelFn>
using custUptrDel =
    std::unique_ptr<T, decltype([](T* obj) { DelFn(obj); })>;


int main()
{
    auto p = custUptrDel<FILE, fclose>{stdout};

    fprintf(p.get(), "%s\n", "Hello Cpp20 world!");

    return EXIT_SUCCESS;
}

// Hello Cpp20 world!