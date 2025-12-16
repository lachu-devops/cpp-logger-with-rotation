#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <logger.hpp>
#include <iostream>
#include <fstream>

using namespace std;
namespace logger_space{

 



void logger_space::Logger::RotateIfNeeded(int size_, int current_size_temp)
{
    if(true)
    {
        cout<<"file created"<<endl;
  ofstream fileout("file_name");

  if (!fileout.is_open()) {
    cout<<"file created"<<endl;
  fileout<<"hello";
  }

    }

}


}//namespace logger_space



#endif // LOGGER_CPP