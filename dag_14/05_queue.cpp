#include <exception>
#include <iostream>
#include <thread>

#include "WorkQueue.hpp"

void run_queue() {
    WorkQueue queue;
    long long sum{};
    std::exception_ptr error;

    {
        std::thread consumer{[&] {
            try {
                int value{};

                while (queue.pop(value)) {
                    sum += value;
                }
            } catch (...) {
                error = std::current_exception();
                queue.close();
            }
        }};

        CloseQueueAndJoin finish_consumer{queue, consumer};

        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.close();
    }

    if (error) {
        std::rethrow_exception(error);
    }

    std::cout << sum << '\n';
}

int main() {
    try {
        run_queue();
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }

    return 0;
}
