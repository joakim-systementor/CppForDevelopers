#include <array>
#include <iostream>
#include <semaphore>
#include <thread>

int main() {
    std::counting_semaphore<2> slots{2};
    std::array<int, 3> results{};

    {
        std::array<std::jthread, 3> workers;

        for (unsigned index{}; index < workers.size(); ++index) {
            workers[index] = std::jthread{[&, index] {
                slots.acquire();

                // At most two workers may be in this section.
                results[index] = static_cast<int>((index + 1) * 10);

                slots.release();
            }};
        }
    }

    for (int result : results) {
        std::cout << result << ' ';
    }

    std::cout << '\n';
}
