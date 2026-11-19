#include <compare>
#include <iostream>

struct Reading {
    int sensor_id;
    int value;

    auto operator<=>(const Reading&) const = default;
};

int main() {
    Reading first{1, 80};
    Reading same{1, 80};
    Reading later{2, 10};
    Reading first_less_value{1, 40};

    std::cout << std::boolalpha << (first == same) << ' ' << (first < later) << ' '
              << (first < first_less_value) << ' ' << (first == first_less_value) << '\n';

    return 0;
}
