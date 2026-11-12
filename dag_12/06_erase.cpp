#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{20, 80, 50};
    auto logical_end = std::remove_if(values.begin(), values.end(), [](int value) {
        return value >= 80;
    });

    std::cout << "Before erase: " << values.size() << '\n';
    values.erase(logical_end, values.end());
    std::cout << "After erase: " << values.size() << '\n';

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
