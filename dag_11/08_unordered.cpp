#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> counts{{2, 1}, {1, 2}};

    // Iterationsordningen är inte ett sorteringslöfte.
    std::cout << "Lookups: " << counts.at(1) << ' ' << counts.at(2) << '\n';

    return 0;
}
