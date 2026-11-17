#include <atomic>
#include <iostream>
#include <thread>

int main() {
    std::atomic<int> counter{};
    //int counter{};

    auto increment = [&counter] {
        for (int index{}; index < 10000000; ++index) {
            ++counter;
        }
    };

    std::thread first{increment};
    std::thread second{increment};

    first.join();
    second.join();

    std::cout << counter << '\n';
}
