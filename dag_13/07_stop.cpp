#include <iostream>
#include <stop_token>
#include <thread>

int main() {
    bool stopped{};

    std::jthread worker{[&stopped](std::stop_token stop) {
        while (!stop.stop_requested()) {
            std::this_thread::yield();
        }

        stopped = true;
    }};

    worker.request_stop();
    worker.join();

    std::cout << std::boolalpha << "Stopped: " << stopped << '\n';
}
