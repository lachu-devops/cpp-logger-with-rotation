#include "include/logger.hpp"
#include <iostream>

int main() {
    // verify header compiles and enum values are accessible
    std::cout << "ERROR value: " << static_cast<int>(logger::ERROR) << "\n";
    return 0;
}
