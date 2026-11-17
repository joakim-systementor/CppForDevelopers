#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main() {
    const std::vector<int> values{10, 20, 30, 40, 50};
    long long left{};
    long long right{};

    std::thread first{[&values, &left] {
        left = std::accumulate(values.begin(), values.begin() + 3, 0LL);
    }};

    std::thread second{[&values, &right] {
        right = std::accumulate(values.begin() + 3, values.end(), 0LL);
    }};

    first.join();
    second.join();

    std::cout << left << ' ' << right << ' ' << left + right << '\n';
}
