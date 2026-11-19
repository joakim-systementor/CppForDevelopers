#include <iostream>

#include "WorkQueue.hpp"

int main() {
    int failures{};
    WorkQueue queue;
    int value{};

    queue.push(10);
    queue.push(20);
    queue.close();

    if (!queue.pop(value) || value != 10) {
        ++failures;
    }

    if (!queue.pop(value) || value != 20) {
        ++failures;
    }

    if (queue.pop(value)) {
        ++failures;
    }

    bool rejected{};

    try {
        queue.push(30);
    } catch (const std::logic_error&) {
        rejected = true;
    }

    if (!rejected) {
        ++failures;
    }

    WorkQueue empty;
    empty.close();
    empty.close();

    if (empty.pop(value)) {
        ++failures;
    }

    if (failures != 0) {
        std::cerr << "FAIL: queue contract\n";
    }

    return failures == 0 ? 0 : 1;
}
