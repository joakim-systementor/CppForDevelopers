#include <iostream>
#include <mutex>
#include <thread>

struct Account {
    int balance{100};
    std::mutex mutex;
};

void transfer(Account& from, Account& to) {
    // Call only with distinct accounts.
    std::scoped_lock lock{from.mutex, to.mutex};

    --from.balance;
    ++to.balance;
}

int main() {
    Account first;
    Account second;

    std::thread forward{[&first, &second] {
        for (int index{}; index < 100; ++index) {
            transfer(first, second);
        }
    }};

    try {
        std::thread backward{[&first, &second] {
            for (int index{}; index < 100; ++index) {
                transfer(second, first);
            }
        }};
        backward.join();
    } catch (...) {
        forward.join();
        throw;
    }

    forward.join();

    std::cout << first.balance << ' ' << second.balance << '\n';
}
