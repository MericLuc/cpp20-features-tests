# C++20 Features tests ![Language](https://img.shields.io/badge/language-C++20-orange.svg) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)

This repository contains a list of **small tests** regarding enhancements brought by the **_c++20 standard_**.

<details>
<summary>

## Core language

</summary>

<details>
<summary>

### Attributes

</summary>

- [\[\[likely\]\]](attributes/likely_unlikely.cpp)
- [\[\[unlikely\]\]](attributes/likely_unlikely.cpp)
- [\[\[nodiscard\]\]](attributes/odiscard.cpp)
- [\[\[no_unique_address\]\]](attributes/no_unique_address.cpp)

</details>

<details>
<summary>

### Keywords

</summary>

- [consteval](keywords/consteval.cpp)
- [constinit](keywords/constinit.cpp)

</details>

</details>

<details>
<summary>

## Standard library

</summary>

<details>
<summary>

### std::span

</summary>

- [generalities](stl/span/generalities.cpp)
- [automatic size deduction](stl/span/automatic-size-deduction.cpp)
- [reallocations management](stl/span/reallocations_management.cpp)
- [initialization from pointer and size](stl/span/init_from_pointer.cpp)
- [modifying underlying elements](stl/span/modifying_elems.cpp)
- [addressing underlying elements](stl/span/addressing_elems.cpp)

</details>

<details>
<summary>

### Containers improvments

</summary>

- [std::erase_if](stl/containers/erase_if.cpp)
- [std::string(_view) prefix/suffix](stl/containers/string_prefix_suffix.cpp)
- [std::contains - associative containers](stl/containers/contains_associative_containers.cpp)
- [constexpr improvments](stl/containers/constexpr-improvments.cpp)
- [std::array creation](stl/containers/array-creation.cpp)
</details>

<details>
<summary>

### std::ranges library

</summary>

- [range and view concepts](stl/ranges/concepts.cpp)
- [range adaptors](stl/ranges/adaptors.cpp)
- [range algorithms on STL containers](stl/ranges/algo-on-containers.cpp)
- [projections](stl/ranges/projections.cpp)

</details>

</details>