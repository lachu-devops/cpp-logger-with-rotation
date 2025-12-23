#include "include/logger.hpp"

#include <iostream>
#include <fstream>
int main() {
            std::cout<<"entered";

    logger_space::Logger& logobj =  logger_space::Logger::getInstance();

  for(int cyclecount = 0;cyclecount<100; cyclecount++)
    {
logobj.execute(logger_space::Level::INFO);
    }


    return 0;
}
