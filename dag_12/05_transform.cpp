#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    const std::vector<int> values{20, 80, 50};
    std::vector<double> normalized(values.size());

    std::transform(values.begin(), values.end(), normalized.begin(), [](int value) {
        return value / 100.0;
    });

    for (double value : normalized) {
        std::cout << value << ' ';
    }

    const double total = std::accumulate(values.begin(), values.end(), 0.0);
    std::cout << "\nMean: " << total / values.size() << '\n';

    return 0;
}
