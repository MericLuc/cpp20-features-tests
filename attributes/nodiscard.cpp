/************************************************************
 *                  ATTRIBUTES - NODISCARD                  *
 ************************************************************/

/*!
 *
 * @brief : Demonstrate how [[nodiscard]] attribute can be used.
 * Use it to add expressivity to your code and explain design choices
 *
 * @note : [[nodiscard]] already existed in C++17. C++20 only added the possibility
 * to add a "reason" to it. 
 */

// compiled with `g++ -std=c++20 -Wall -Werror -O0 nodiscard.cpp -o nodiscard`

#include <utility>
#include <iostream>

template < typename T, typename ... Args >
[[nodiscard("Memory leak !")]]
T* createWithHeapAlloc(Args&& ...arguments)
{
    return new T(std::forward<Args>(arguments)...);
}

enum class 
[[nodiscard("You should not ignore retcodes")]] 
RetCode {
    OK,
    WARNING,
    ERROR,
    CRITICAL
};

RetCode functionWithRetCode(void) noexcept {
    //...
    return RetCode::CRITICAL;
}

int main()
{
    createWithHeapAlloc<int>(42);

    functionWithRetCode();

    return EXIT_SUCCESS;
}

// Compiler warnings

/*
error: ignoring return value of ‘T* createWithHeapAlloc(Args&& ...) [with T = int; Args = {int}]’, declared with attribute ‘nodiscard’: ‘Memory leak !’ [-Werror=unused-result]
42 |     createWithHeapAlloc<int>(42);
*/

/*
error: ignoring returned value of type ‘RetCode’, declared with attribute ‘nodiscard’: ‘You should not ignore retcodes’ [-Werror=unused-result]
44 |     functionWithRetCode();
*/