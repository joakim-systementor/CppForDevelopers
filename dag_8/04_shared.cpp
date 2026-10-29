#include <iostream>
#include <memory>

int main() {
    auto first = std::make_shared<int>(42);

    {
        auto second = first;
        std::cout << "Owners: " << first.use_count() << '\n';
        std::cout << "Value: " << *second << '\n';
    }

    std::cout << "Owners after scope: " << first.use_count() << '\n';

    return 0;
}
