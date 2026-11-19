#include <iostream>
#include <span>
#include <array>
#include <vector>

// span beskriver en följd utan att kopiera eller äga elementen.
int sum(std::span<const int> values) {
    int result{};

    for (int value : values) {
        result += value;
    }

    return result;
}

int main() {
    const int values[]{10, 20, 30};
    const std::vector<int> vector_values{11, 20, 30};
    const std::array<int, 3> array_values{12, 20, 30};

    std::cout << sum(values) << '\n';
    std::cout << sum(vector_values) << '\n';
    std::cout << sum(array_values) << '\n';

    return 0;
}
