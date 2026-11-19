#include <iostream>

#include "Money.hpp"

int main() {
    std::cout << Money{1250} << ' ' << Money{5} << ' ' << Money{-5} << ' ' << Money{1000} << std::endl;

    return 0;
}
