#include <iostream>
#include <span>

int sum(std::span<const int> values) {
    int result{};

    for (int value : values) {
        result += value;
    }

    return result;
}

int main() {
    const int values[]{10, 20, 30};
    std::cout << sum(values) << '\n';

    return 0;
}
