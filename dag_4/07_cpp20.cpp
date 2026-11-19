#include <compare>
#include <iostream>

struct Reading {
    char sensorId[10];
    int value;

    auto operator<=>(const Reading&) const = default;
};

int main() {
    // C++20: namngivna initialiserare för en aggregate-typ.
    Reading first{.sensorId = "stol", .value = 80};
    Reading same{.sensorId = "stol", .value = 80};
    Reading later{.sensorId = "t", .value = 10};

    std::cout << std::boolalpha;
    std::cout << (first == same) << '\n';
    std::cout << (first < later) << '\n';

    return 0;
}
