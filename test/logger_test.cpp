#include "include/logger.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    // verify header compiles and enum values are accessible
    std::cout << "ERROR value: " << static_cast<int>(logger_space::ERROR) << "\n";

  ofstream fileout("file_name");

  if (fileout.is_open()) {
    cout<<"file created"<<endl;
  fileout<<"hello";
  }

    return 0;
}
