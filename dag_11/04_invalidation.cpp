#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{10, 20};
    values.reserve(4);
    int& first = values.at(0);

    values.push_back(30); // Kapaciteten räcker, ingen omallokering behövs.
    first = 11;
    std::cout << values.at(0) << '\n';

    try {
        std::cout << values.at(9) << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "Rejected index\n";
    }

    // Efter omallokering/erase kan referenser bli ogiltiga; läs dem inte då.
    return 0;
}
