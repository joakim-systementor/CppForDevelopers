#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> values{79, 80, 100, 0, 101};

    const auto new_end = std::remove_if(values.begin(), values.end(), [](int value) {
        return value < 0 || value > 100;
    });

    values.erase(new_end, values.end());

    std::sort(values.begin(), values.end());

    std::cout << "Values:";

    for (int value : values) {
        std::cout << ' ' << value;
    }

    const auto alarms = std::count_if(values.begin(), values.end(), [](int value) {
        return value >= 80;
    });

    std::cout << "\nAlarms: " << alarms << '\n';

    if (values.empty()) {
        std::cout << "No measurements\n";
    } else {
        const double total = std::accumulate(values.begin(), values.end(), 0.0);
        std::cout << "Mean: " << total / values.size() << '\n';
    }

    return 0;
}
