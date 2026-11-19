#include <iostream>
#include <list>

int main() {
    std::list<int> values{20, 30};
    values.push_front(10);
    values.push_back(40);

    auto position = values.begin();
    ++position;

    values.insert(position, 15);

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    values.sort();

    std::cout << "Size: " << values.size() << '\n';
}
