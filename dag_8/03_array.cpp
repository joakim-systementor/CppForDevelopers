#include <iostream>
#include <memory>

int main() {
    auto values = std::make_unique<int[]>(3);

    for (int index{}; index < 3; ++index) {
        values[index] = (index + 1) * 10;
    }

    std::cout << values[0] << ' ' << values[1] << ' ' << values[2] << '\n';

    return 0;
}
