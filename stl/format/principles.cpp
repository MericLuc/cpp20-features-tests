/************************************************************
 *                    STL - std::format                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the main usages of the new std::format
 * library.
 * 
 * Basically, it offers a 'pythonic' (yet printf inspired)
 * way of formatting strings, which offers many features :
 * - fill letters
 * - text alignement
 * - width, precision, sign, type of numbers
 * 
 * @notes : For more informations, see 
 * <https://en.cppreference.com/w/cpp/utility/format>
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O0
// principles.cpp -o principles`

#include <iostream>
#include <format>

int main()
{
    // Write to buffers (output iterators) using 
    // std::format_to and std::format_to_n
    std::string buff;

    std::format_to(std::back_inserter(buff), 
                   "Hello c++{} world!", 
                   20);
    std::cout << buff << '\n';

    // We can have unsed arguments
    buff.clear();
    std::format_to(std::back_inserter(buff),
                   "Hello std::{1}{0} {2}",
                   "_to()",
                   "format",
                   "with unused and arranged elements");
    std::cout << buff << '\n';
    buff.clear();

    // std::format_to_n allows to write te formatting result
    // to an output iterator with at most n characters
    // written.
    std::format_to_n(std::back_inserter(buff),
                     40,
                     "std::{0} {1}",
                     "format_to_n",
                     "will write at most n chars to the "
                     "output iterator");
    std::cout << buff << '\n';

    std::cout << std::format(
      "You can use {} directly with {}{}",
      "std::format()", "streams", '\n');

    // Specify fill character and alignement
    std::cout << "Specify fill character and alignement\n";
    std::cout << std::format("{:-^20}", "Center") << '\n';
    std::cout << std::format("{:*>20}", "Center") << '\n';
    std::cout << std::format("{:*<20}", "Left")   << '\n'; 

    double d{ 12.3456789 };
    std::cout << "\nSpecify width and precision\n";
    std::cout << std::format("{:10.50}", d) << '\n';

    auto i{ 2020 };
    std::cout << "\nSpecify type\n";  
    std::cout << "Default: "     << std::format("{:}" , i) << '\n'; 
    std::cout << "Decimal: "     << std::format("{:d}", i) << '\n'; 
    std::cout << "Binary: "      << std::format("{:b}", i) << '\n'; 
    std::cout << "Octal: "       << std::format("{:o}", i) << '\n'; 
    std::cout << "Hexadecimal: " << std::format("{:x}", i) << '\n'; 


    return EXIT_SUCCESS;
}

// Hello c++20 world!
// Hello std::format_to() with unused and arranged elements
// std::format_to_n will write at most n ch
// You can use std::format() directly with streams
// Specify fill character and alignement
// -------Center-------
// **************Center
// Left****************

// Specify width and precision
// 12.345678899999999345027390518225729465484619140625

// Specify type
// Default: 2020
// Decimal: 2020
// Binary: 11111100100
// Octal: 3744
// Hexadecimal: 7e4