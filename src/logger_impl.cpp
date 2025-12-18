#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <logger.hpp>
#include <iostream>

namespace logger_space {

Logger::Logger()
    : size_limit(1024*1024), current_logger_info(0), current_size(0), file_name("log.txt"),cycle(0)
{
    fileout.open(file_name);
    if (!fileout.is_open()) {
        std::cerr << "Logger: failed to open " << file_name << "\n";
    }
}

Logger::~Logger()
{
    if (fileout.is_open()) fileout.close();
}

void logger_space::Logger::execute(int cycle)
{
    for(int cyclecount = 0;cyclecount<cycle; cyclecount++)
    {
    WritelogMessage();

    RotateIfNeeded(size_limit, current_size);
    }
}

void logger_space::Logger::WritelogMessage()
{
    
}

void logger_space::Logger::RotateIfNeeded(int size_, int current_size_temp)
{
    if(size_<current_size_temp)
    {

    }

}
} // namespace logger_space
#endif // LOGGER_CPP
