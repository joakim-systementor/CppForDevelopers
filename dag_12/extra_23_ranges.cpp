#include <iostream>
#include <ranges>
#include <vector>

int main() {
    const std::vector<int> values{20, 80, 50};
    auto view = values
        | std::views::filter([](int value) {
            return value >= 50;
        })
        | std::views::transform([](int value) {
            return value * 2;
        });

    std::cout << "View:\n";
    for (int value : view) {
        std::cout << value << ' ';
    }

    auto result = view | std::ranges::to<std::vector<int>>();

    std::cout << "\nSaved view:\n";
    for (int value : result) {
        std::cout << value << ' ';
    }

    std::cout << "\nValues:\n";

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
