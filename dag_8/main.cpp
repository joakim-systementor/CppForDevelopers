#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

class Source {
public:
    virtual ~Source() = default;
    virtual int read() const = 0;
};

class ConstantSource final : public Source {
public:
    explicit ConstantSource(int value) : value_{value} {
        if (value < 0 || value > 100) {
            throw std::out_of_range{"Value must be 0..100"};
        }
    }

    int read() const override {
        return value_;
    }

private:
    int value_;
};

int main() {
    std::unique_ptr<Source> owner = std::make_unique<ConstantSource>(80);
    const Source* observer = owner.get();

    std::cout << "Observed: " << observer->read() << '\n';

    auto next_owner = std::move(owner);
    std::cout << std::boolalpha << "Old owner empty: " << (owner == nullptr) << '\n';
    std::cout << "New owner: " << next_owner->read() << '\n';

    try {
        auto invalid = std::make_unique<ConstantSource>(101);
        std::cout << invalid->read() << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "Rejected\n";
    }

    return 0;
}
