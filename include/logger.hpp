
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <mutex>
#include <cstddef>
#include <cstdint>

namespace logger {

    enum Level : std::uint8_t {
        INFO = 0,
        WARN = 1,
        ERROR = 2
    };

    class Logger {

        int size_limit;
        std::mutex mtx;
        uint8_t current_logger_info;
        int current_size;
        std::string file_name;
     
    Logger() : size_limit(1024*1024), current_logger_info(0), current_size(0), file_name("log.txt") {}

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    ~Logger() {}

    void logMessage();
    void rotateifNeeded();

    public:
        static Logger& getInstance(){
            static Logger instance;
            return instance;
        }
void log();

void warn();

void error();

    };

} // namespace logger

#endif // LOGGER_HPP

