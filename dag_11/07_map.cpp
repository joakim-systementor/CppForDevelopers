#include <iostream>
#include <map>

int main() {
    std::map<int, int> counts;
    ++counts[2];
    counts[1] += 2;

    for (const auto& [sensor_id, count] : counts) {
        std::cout << sensor_id << ": " << count << '\n';
    }

    return 0;
}
