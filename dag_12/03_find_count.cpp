#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> values{20, 80, 50};
    auto found = std::find_if(values.begin(), values.end(), [](int value) {
        return value >= 80;
    });

    if (found != values.end()) {
        std::cout << "Found: " << *found << '\n';
    }

    std::cout << "Count: " << std::count_if(values.begin(), values.end(), [](int value) {
        return value >= 80;
    }) << '\n';

    return 0;
}
