#include <iostream>

int main() {
    int threshold{80};

    auto copied = [threshold](int value) {
        return value >= threshold;
    };

    auto referenced = [&threshold](int value) {
        return value >= threshold;
    };

    threshold = 90;

    std::cout << std::boolalpha << copied(85) << ' ' << referenced(85) << '\n';

    return 0;
}
