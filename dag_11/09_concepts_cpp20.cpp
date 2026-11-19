#include <concepts>
#include <iostream>

template <typename T>
T add(T first, T second) {
    return first + second;
}

template <std::integral T>
T add_integers(T first, T second) {
    return first + second;
}

int main() {
    std::cout << add(3.0, 4.0) << '\n';
    std::cout << add_integers(3, 4) << '\n';

    // add_integers(3.0, 4.0); // Dubbelvärden uppfyller inte integral.
    return 0;
}
