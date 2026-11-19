#include <iostream>
#include <mutex>
#include <thread>

int main() {
    int counter{};
    std::mutex mutex;

    auto increment = [&counter, &mutex] {
        for (int index{}; index < 10000000; ++index) {
            std::lock_guard<std::mutex> lock{mutex};
            ++counter;
        }
    };

    std::thread first{increment};
    try {
        std::thread second{increment};
        second.join();
    } catch (...) {
        first.join();
        throw;
    }

    first.join();

    std::cout << counter << '\n';
}
