#include <iostream>
#include <stdexcept>

#include "Money.hpp"

int main() {
    Money total{100};
    total += Money{25};
    std::cout << total << '\n';

    Money near_limit{Money::limit};

    try {
        near_limit += Money{1};
    } catch (const std::out_of_range&) {
        std::cout << "Rejected; unchanged=" << near_limit.cents() << '\n';
    }

    return 0;
}
