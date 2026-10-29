#include <iostream>
#include <memory>
#include <utility>

int main() {
    auto owner = std::make_unique<int>(42);
    int* observer = owner.get();

    auto next_owner = std::move(owner);

    std::cout << std::boolalpha << "Old owner empty: " << (owner == nullptr) << '\n';
    std::cout << "New owner: " << *next_owner << '\n';
    std::cout << "Observer: " << *observer << '\n';

    return 0;
}
