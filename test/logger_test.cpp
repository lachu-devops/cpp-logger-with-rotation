#include "include/logger.hpp"
#include <iostream>
#include <fstream>
int main() {
    // verify header compiles and enum values are accessible
    std::cout << "ERROR value: " << static_cast<int>(logger_space::ERROR) << "\n";
    return 0;
}
