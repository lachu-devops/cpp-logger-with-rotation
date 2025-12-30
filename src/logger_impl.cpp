#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <logger.hpp>
#include <iostream>
#include <filesystem>

namespace logger_space {

Logger::Logger()
    : size_limit(207*207), current_logger_info(logger_space::Level::INFO), current_size(0), file_name("log.txt"),message("log file")
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
  current_logger_info = info;
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
    try {
        current_size_temp =
            static_cast<int>(std::filesystem::file_size(file_name));
    } catch (...) {
        current_size_temp = 0;
    }

    if (current_size_temp <= size_)
        return;

    // --- persistent counter ---
    static int count = 0;
    count++;

    // --- close current log file ---
    if (fileout.is_open()) {
        fileout.close();
    }

    // --- build new file name ---
    std::string new_name = "log" + std::to_string(count) + ".txt";

    // --- rename old file ---
    std::filesystem::rename(file_name, new_name);

    // --- reset to base log file ---
    file_name = "log.txt";

    // --- open new log file ---
    fileout.open(file_name, std::ios::out | std::ios::app);
}



} // namespace logger_space
#endif // LOGGER_CPP
