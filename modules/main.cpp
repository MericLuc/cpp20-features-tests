#import mathm;

#include <iostream>
#include <vector>

int main() {

    std::cout << "mathm::elemsProduct(): "
              << mathm::elemsProduct(std::vector{1,2,3})
              << '\n';

    return EXIT_SUCCESS;
}
