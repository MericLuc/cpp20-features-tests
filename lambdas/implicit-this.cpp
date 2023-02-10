/************************************************************
 *                      STL - LAMBDAS                       *
 ************************************************************/

/*!
 *
 * @brief : Shows how c++20 lambdas are able to detect
 * implicit 'this' copy, and what kind of undefined
 * behaviours are now avoided.
 * 
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0 
// implicit-this.cpp -o implicit-this`

#include <iostream>

class BrokenLambdasFactory {
public:
    constexpr BrokenLambdasFactory() noexcept { 
        std::cout << "Alive\n"; 
    }
    ~BrokenLambdasFactory() noexcept { 
        std::cout << "Im dead. Do not try to access me\n"; 
    }

    auto makeBrokenLambda() noexcept { 
        return [=](){ std::cout << "val is " << _val << '\n'; };
    }

private:
    const int _val{ 42 };

};

auto makeBrokenLambda(void) noexcept {
    BrokenLambdasFactory instance;
    return instance.makeBrokenLambda();
}

auto makeCorrectLambda(void) noexcept {
    BrokenLambdasFactory instance;
    return instance.makeCorrectLambda();
}

int main()
{
    // Used to be undefined behaviour 
    // c++20 issues a warning
    // implicit-this.cpp:31:16: error: implicit capture of ‘this’ 
    // via ‘[=]’ is deprecated in C++20 [-Werror=deprecated]
    // {
    //     auto myLambda{ makeBrokenLambda() };
    //     myLambda();
    // }

    return EXIT_SUCCESS;
}