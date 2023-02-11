/************************************************************
 *                 CORE - MISCELLANEOUS                     *
 ************************************************************/

/*!
 *
 * @brief : Shows the evolution of the `volatile` type qualifier
 * 
 * @notes : volatile is now partly deprecated.
 * The parts that were incertain or already broken does not
 * pass the compilation step anymore :
 * - compond assignement, pre/post increment/decrement
 * - function parameters or return types
 * - structured bindings declarations
 */

// compiled with `g++ -std=c++20 -Wall -Werr -O3
// volatile.cpp -o volatile`

// What is the purpose of `volatile` type qualifier ?
/*
  Basically, it just stops the compiler from optimizing
  the load/store operations (remove or reorder for example).

  It is usefull especially when an object can be modified
  outside of the execution flow.
*/

#include <iostream>

int main()
{
    volatile int i{ 42 };

    while ( 42 != i ) {
      std::cout << "We should never be able to get there...\n"
                << "as far as the compiler knows !\n";
    }

    return EXIT_SUCCESS;
}

// Compiled without 'volatile'
/*
main: # @main
  xorl %eax, %eax
  retq
*/

// Compiled with 'volatile'
/*
main: # @main
  pushq %r15
  pushq %r14
  pushq %rbx
  subq $16, %rsp
  movl $42, 12(%rsp)
  movl 12(%rsp), %eax
  cmpl $42, %eax
  je .LBB0_3
  movq _ZSt4cout@GOTPCREL(%rip), %rbx
  leaq .L.str(%rip), %r14
  leaq .L.str.1(%rip), %r15
.LBB0_2: # =>This Inner Loop Header: Depth=1
  movl $40, %edx
  movq %rbx, %rdi
  movq %r14, %rsi
  callq _ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
  movl $31, %edx
  movq %rbx, %rdi
  movq %r15, %rsi
  callq _ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
  movl 12(%rsp), %eax
  cmpl $42, %eax
  jne .LBB0_2
.LBB0_3:
  xorl %eax, %eax
  addq $16, %rsp
  popq %rbx
  popq %r14
  popq %r15
  retq
.L.str:
  .asciz "We should never be able to get there...\n"

.L.str.1:
  .asciz "as far as the compiler knows !\n"
*/