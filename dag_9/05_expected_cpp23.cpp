#include <expected>
#include <iostream>

#include "Measurement.hpp"

std::expected<Measurement, std::string> try_parse(const std::string& line) {
    try {
        return parse_measurement(line);
    } catch (const std::exception& error) {
        return std::unexpected{std::string{error.what()}};
    }
}

int main() {
    auto valid = try_parse("1 80");
    auto invalid = try_parse("bad");

    if (valid) {
        std::cout << "Value: " << valid->value << '\n';
    }

    if (!invalid) {
        std::cout << "Error: " << invalid.error() << '\n';
    }

    return 0;
}
