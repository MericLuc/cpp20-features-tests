# C++20 Module test ![Language](https://img.shields.io/badge/language-C++20-orange.svg)

This repository is just about toying with c++20 modules.

Basically, what I take from C++20 modules are the following 
- **Big improvement over headers and macros**.
  - Import once and for free
  - Import order does not matter
  - Avoid names collisions
- **Linkage facilities**
  - Easily define what is to be exported by your module (external linkage) and what should remain inside (module linkage)
  - Same applies to included or imported libraries/modules 
- **Smooth transition for existing projects**
  - Modules can provide header units, which may be imported using `import`, which works quite like `include`
- **Interface/Implementation separation remains the same**
  - Modules have an `interface unit` and an `implementation unit`
- **Full support of generic programming**
  - Modules seem to use a particular representation for templates (a sort of Abstract Syntax Tree) which makes the template-definition available at instantiation-time.

Some drawbacks, though :
- The C++20 STL does not provide with a modularized version.
- CMake support is either poorly referenced or far from complete.
- Compilers do not use the same extensions for module files ?!