#include <iostream>
#include <thread>

int main() {
    int result{};

    {
        std::jthread worker{[&result] {
            result = 7;
        }};
    }

    std::cout << result << '\n';
}
