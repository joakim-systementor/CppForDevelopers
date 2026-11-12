#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{20, 80, 50};

    std::cout << "Values begin()-end():\n";
    for (int value : values) {
        std::cout << value << ' ';
    }

    auto logical_end = std::remove_if(values.begin(), values.end(), [](int value) {
        return value >= 80;
    });

    std::cout << "\nValues begin()-end() after remove_if:\n";
    for (auto it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << "\nValues begin()-logical_end:\n";
    for (auto it = values.begin(); it != logical_end; ++it) {
        std::cout << *it << ' ';
    }

    std::cout << "\nsize() before erase: " << values.size() << '\n';
    values.erase(logical_end, values.end());
    std::cout << "size() after erase: " << values.size() << '\n';

    std::cout << "Values begin()-end() after erase:\n";
    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
