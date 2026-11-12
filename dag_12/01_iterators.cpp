#include <iostream>
#include <iterator>
#include <vector>

int main() {
    const std::vector<int> values{3, 1, 2};

    for (auto position = values.begin(); position != values.end(); ++position) {
        std::cout << *position << ' ';
    }

    std::cout << "\nDistance: " << std::distance(values.begin(), values.end()) << '\n';

    return 0;
}
