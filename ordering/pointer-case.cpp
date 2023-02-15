/************************************************************
 *                    CORE - ORDERING                       *
 ************************************************************/

/*!
 *
 * @brief : A warning about automatic comparison
 * of pointers using the compiler-generated
 * three-way comparison operator. 
 * 
 * It does compare pointers, not referenced objects.
 * That means, memory addresses only are compared.
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// pointer-case.cpp -o pointer-case`

#include <iostream>
#include <concepts>
#include <vector>

template< typename T >
concept PointerT = requires(T param)
{
    requires std::is_pointer_v<T>;
};

template< PointerT T >
struct PointerWrapper { 
    explicit constexpr PointerWrapper(T val) noexcept: 
        _val{ val } {}

    auto operator<=>(const PointerWrapper<T>& o) const = default;

    T _val;
};

int main()
{
    auto v1{ new std::vector<int>{1,2,3} };
    auto v2{ new std::vector<int>{1,2,3} };

    PointerWrapper W1v1(v1), W2v1(v1);
    PointerWrapper W1v2(v2), W2v2(v2);

    std::cout << std::boolalpha;
    std::cout << "Default compiled three-way operator and pointers\n";
    std::cout << "W1v1 == W1v1 ? " << 
                 (W1v1 == W1v1) << '\n';
    std::cout << "W1v1 == W1v2 ? " << 
                 (W1v1 == W1v2) << '\n';
    std::cout << "W1v2 == W2v2 ? " << 
                 (W1v2 == W2v2) << '\n';

    delete v1;
    delete v2;

    return EXIT_SUCCESS;
}

// Default compiled three-way operator and pointers
// W1v1 == W1v1 ? true
// W1v1 == W1v2 ? false
// W1v2 == W2v2 ? true
