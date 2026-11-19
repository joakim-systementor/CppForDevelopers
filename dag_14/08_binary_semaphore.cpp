#include <iostream>
#include <semaphore>
#include <thread>

int main() {
    std::binary_semaphore ready{0};
    int result{};

    std::jthread worker{[&] {
        result = 42;
        ready.release();
    }};

    ready.acquire();
    std::cout << result << '\n';
}
