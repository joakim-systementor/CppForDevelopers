#include <exception>
#include <iostream>
#include <stdexcept>
#include <thread>

int main() {
    std::exception_ptr error;

    std::thread worker{[&error] {
        try {
            throw std::runtime_error{"Worker error"};
        } catch (...) {
            error = std::current_exception();
        }
    }};

    worker.join();

    try {
        if (error) {
            std::rethrow_exception(error);
        }
    } catch (const std::exception& exception) {
        std::cout << exception.what() << '\n';
    }
}
