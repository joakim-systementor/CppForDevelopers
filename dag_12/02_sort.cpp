#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{20, 80, 50};
    std::sort(values.begin(), values.end());

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
    std::sort(values.begin(), values.end(), [](int first, int second) {
        return first > second;
    });

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
