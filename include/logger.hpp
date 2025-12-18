
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <mutex>
#include <cstddef>
#include <cstdint>
#include <fstream>

namespace logger_space {

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
        std::ofstream fileout;
        int cycle;

        Logger();

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        ~Logger();

        void execute(int cycle);
    void WritelogMessage();
    void RotateIfNeeded(int ccz , int current_size);

    public:
        static Logger& getInstance()
        {
            static Logger instance;
            return instance;
        }

void info();
void warn();
void error();

    };

} // namespace logger_space

#endif // LOGGER_HPP

