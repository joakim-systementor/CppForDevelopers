#include <iostream>
#include <thread>

int main() {
    int result{};

    std::thread worker{[&result] {
        result = 42;
    }};

    worker.join();

    std::cout << result << '\n';
}
