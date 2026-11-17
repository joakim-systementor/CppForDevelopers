#include <iostream>
#include <thread>

int main() {
    int value{10};
    int copied_result{};

    std::thread copied{[value, &copied_result] {
        copied_result = value + 1;
    }};

    value = 20;
    copied.join();

    std::thread referenced{[&value] {
        ++value;
    }};

    referenced.join();

    std::cout << copied_result << ' ' << value << '\n';
}
