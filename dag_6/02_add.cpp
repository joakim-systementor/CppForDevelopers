#include <iostream>

#include "Money.hpp"

int main() {
    Money first{1250};
    Money second{375};
    Money total = first + second;

    std::cout << "total.cents(): " << total.cents() << '\n';
    std::cout << "first.cents(): " << first.cents() << '\n';

    return 0;
}
