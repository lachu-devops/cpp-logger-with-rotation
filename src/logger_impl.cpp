#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <logger.hpp>
#include <iostream>

namespace logger_space {

Logger::Logger()
    : size_limit(1024*1024), current_logger_info(logger_space::Level::INFO), current_size(0), file_name("log.txt"),cycle(0),message("log file")
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

void logger_space::Logger::execute( Level info)
{
  
    WritelogMessage(current_logger_info);
    RotateIfNeeded(size_limit, current_size);
    
}

void logger_space::Logger::WritelogMessage(Level current_logger_info)
{

     if (fileout.is_open()) {
if(current_logger_info == logger_space::Level::INFO)
{
                           
            fileout << "[INFO] This is info message" << std::endl;

}
if(current_logger_info == logger_space::Level::ERROR)
{
        fileout << "[ERROR] This is error message" << std::endl;
}
if(current_logger_info == logger_space::Level::WARN)
{
      fileout << "[WARN] This is warn message" << std::endl;
}
            fileout.flush();  // Ensure it's written immediately
     }


        //                 if (fileout.is_open()) {
        //     logFile << "[" << getLevelstring(current_logger_info) << "] "
        //             << message << std::endl;
        //     logFile.flush();  // Ensure it's written immediately
        // }



}

void logger_space::Logger::RotateIfNeeded(int size_, int current_size_temp)
{
    if(size_<current_size_temp)
    {

    }

}

std::string logger_space::Logger::getLevelstring(Level current_logger_info)
{
if(current_logger_info == logger_space::Level::INFO)
{
    return "info";
}
if(current_logger_info == logger_space::Level::ERROR)
{
    return "ERROR";
}
if(current_logger_info == logger_space::Level::WARN)
{
    return "WARN";
}

return "nothing";
}

} // namespace logger_space
#endif // LOGGER_CPP
