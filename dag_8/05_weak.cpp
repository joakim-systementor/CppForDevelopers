#include <iostream>
#include <memory>

int main() {
    std::weak_ptr<int> observer;

    {
        auto owner = std::make_shared<int>(42);
        observer = owner;

        if (auto locked = observer.lock()) {
            std::cout << "Locked: " << *locked << '\n';
        }
    }

    std::cout << std::boolalpha << "Expired: " << observer.expired() << '\n';

    return 0;
}
