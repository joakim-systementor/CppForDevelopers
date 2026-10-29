#include <fstream>
#include <iostream>
#include <string>

int main() {
    {
        std::ifstream file{"CMakeLists.txt"};

        if (!file) {
            std::cerr << "Cannot open CMakeLists.txt\n";
            return 1;
        }

        std::string line;
        std::getline(file, line);
        std::cout << line << '\n';
    }

    std::cout << "File scope ended\n";

    return 0;
}
