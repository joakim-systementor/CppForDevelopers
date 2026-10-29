#include <iostream>
#include <memory>
#include <stdexcept>

class Resource {
public:
    Resource() {
        std::cout << "Acquired\n";
    }

    ~Resource() {
        std::cout << "Released\n";
    }
};

int main() {
    try {
        auto owner = std::make_unique<Resource>();
        throw std::runtime_error{"Demo error"};
    } catch (const std::runtime_error&) {
        std::cout << "Caught\n";
    }

    return 0;
}
