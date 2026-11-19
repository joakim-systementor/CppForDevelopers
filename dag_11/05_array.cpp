#include <array>
#include <iostream>

int main() {
    std::array<int, 3> values{10, 20, 30};
    values.at(1) = 25;

    std::cout << "Size: " << values.size() << '\n';

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}
