#include <iostream>

#include "Money.hpp"

int main() {
    Money first{1250};
    Money same{1250};
    Money larger{2000};

    std::cout << std::boolalpha;
    std::cout << "first == same? " << (first == same) << '\n';
    std::cout << "first < larger? " << (first < larger) << '\n';

    return 0;
}
