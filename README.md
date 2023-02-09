# C++20 Features tests ![Language](https://img.shields.io/badge/language-C++20-orange.svg) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)

This repository contains a list of **small tests** regarding enhancements brought by the **_c++20 standard_**.

## Core language

### Attributes

- [\[\[likely\]\]](attributes/likely_unlikely.cpp)
- [\[\[unlikely\]\]](attributes/likely_unlikely.cpp)
- [\[\[nodiscard\]\]](attributes/odiscard.cpp)
- [\[\[no_unique_address\]\]](attributes/no_unique_address.cpp)

### Keywords

- [consteval](keywords/consteval.cpp)
- [constinit](keywords/constinit.cpp)

## Standard library

### std::span

- [generalities](stl/span/generalities.cpp)
- [automatic size deduction](stl/span/automatic-size-deduction.cpp)
- [reallocations management](stl/span/reallocations_management.cpp)
- [initialization from pointer and size](stl/span/init_from_pointer.cpp)
- [modifying underlying elements](stl/span/modifying_elems.cpp)
- [addressing underlying elements](stl/span/addressing_elems.cpp)

### Containers improvments

- [std::erase_if](stl/containers/erase_if.cpp)
- [std::string(_view) prefix/suffix](stl/containers/string_prefix_suffix.cpp)
- [std::contains - associative containers](stl/containers/contains_associative_containers.cpp)