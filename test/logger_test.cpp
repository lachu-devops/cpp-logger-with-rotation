#include "include/logger.hpp"

#include <iostream>
#include <fstream>
int main() {
            std::cout<<"entered";

    logger_space::Logger& logobj =  logger_space::Logger::getInstance();

  for(int cyclecount = 0;cyclecount<300000; cyclecount++)
  {
    if(cyclecount <20){
logobj.execute(logger_space::Level::INFO);
    }
    if(cyclecount >20&&cyclecount <50){
logobj.execute(logger_space::Level::ERROR);
    }
        if(cyclecount >50){
logobj.execute(logger_space::Level::WARN);
    }
  }
    return 0;
}
