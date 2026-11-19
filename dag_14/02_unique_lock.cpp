#include <iostream>
#include <mutex>

int main() {
    std::mutex mutex;
    std::unique_lock<std::mutex> lock{mutex, std::defer_lock};

    std::cout << std::boolalpha << lock.owns_lock() << '\n';

    lock.lock();

    std::cout << lock.owns_lock() << '\n';

    lock.unlock();

    std::cout << lock.owns_lock() << '\n';
}
