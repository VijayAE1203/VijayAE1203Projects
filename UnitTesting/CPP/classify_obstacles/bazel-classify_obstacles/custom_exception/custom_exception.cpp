#include "custom_exception.hpp"

namespace unittestdemo
{
          
    abnormal_distance_exception::abnormal_distance_exception(std::string msg) : message(msg){};

    const char* abnormal_distance_exception::what() const
    {
        return this->message.c_str();
    }

}
