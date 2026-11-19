#include <array>
#include <exception>
#include <iostream>
#include <thread>

#include "WorkQueue.hpp"

void run_pipeline() {
    WorkQueue queue;
    std::array<long long, 2> sums{};
    std::array<int, 2> counts{};
    std::array<std::exception_ptr, 2> errors{};

    auto consume = [&](std::size_t index) {
        try {
            int value{};

            while (queue.pop(value)) {
                sums[index] += value;
                ++counts[index];
            }
        } catch (...) {
            errors[index] = std::current_exception();
            queue.close();
        }
    };

    {
        std::thread first{consume, 0};
        // Also close the queue if construction of the next thread fails.
        CloseQueueAndJoin finish_first{queue, first};
        std::thread second{consume, 1};
        CloseQueueAndJoin finish_second{queue, second};

        for (int value{1}; value <= 6; ++value) {
            queue.push(value);
        }

        queue.close();
    }

    for (const auto& error : errors) {
        if (error) {
            std::rethrow_exception(error);
        }
    }

    std::cout << "Items: " << counts[0] + counts[1] << '\n';
    std::cout << "Total: " << sums[0] + sums[1] << '\n';
}

int main() {
    try {
        run_pipeline();
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }

    return 0;
}
