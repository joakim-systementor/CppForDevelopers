#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main() {
    const std::vector<int> values{1, 2, 3, 4, 5, 6, 7};
    const auto middle = values.begin() + values.size() / 2;
    long long first_sum{};
    long long second_sum{};

    std::thread first{[&values, middle, &first_sum] {
        first_sum = std::accumulate(values.begin(), middle, 0LL);
    }};

    std::thread second{[&values, middle, &second_sum] {
        second_sum = std::accumulate(middle, values.end(), 0LL);
    }};

    first.join();
    second.join();

    std::cout << "Items: " << values.size() << '\n';
    std::cout << "Parts: " << first_sum << ' ' << second_sum << '\n';
    std::cout << "Total: " << first_sum + second_sum << '\n';
}
