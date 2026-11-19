#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
    std::mutex mutex;
    std::condition_variable changed;
    bool ready{};
    int result{};

    std::thread consumer{[&] {
        std::unique_lock<std::mutex> lock{mutex};

        changed.wait(lock, [&ready] {
            return ready;
        });

        result = 42;
    }};

    {
        std::lock_guard<std::mutex> lock{mutex};
        ready = true;
    }

    changed.notify_one();
    consumer.join();

    std::cout << result << '\n';
}
