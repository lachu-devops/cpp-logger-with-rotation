# cpp-logger-with-rotation
A simple C++ logger with file rotation and timestamps







# build commands

g++ -std=c++17 main.cpp src/logger_impl.cpp -Iinclude -o logger_app ---> //to compile whole project

 g++ -std=c++17 main.cpp include/logger.hpp -o logger_app --->  // to compile hpp

 # Test command

 g++ -std=c++17 -I. test/logger_test.cpp -o logger_test && ./logger_test 



 combine command:   g++ -std=c++17 -I. -Iinclude test/logger_test.cpp src/logger_impl.cpp -o logger_test && ./logger_test
