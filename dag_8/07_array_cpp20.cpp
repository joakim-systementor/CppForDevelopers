#include <iostream>
#include <memory>

int main() {
    auto owner = std::make_shared<int[]>(3);
    auto second = owner;

    owner[0] = 10;
    std::cout << second[0] << ' ' << owner[1] << ' ' << owner.use_count() << '\n';

    return 0;
}
