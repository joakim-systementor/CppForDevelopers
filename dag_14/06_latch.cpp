#include <iostream>
#include <latch>
#include <thread>

int main() {
    std::latch ready{2};
    int first_value{};
    int second_value{};

    std::jthread first{[&] {
        first_value = 10;
        ready.count_down();
    }};

    std::jthread second{[&] {
        second_value = 20;
        ready.count_down();
    }};

    ready.wait();

    std::cout << first_value + second_value << '\n';
}
