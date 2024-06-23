#include <vector>
#include <string>

namespace unittestdemo
{
    //User defined datatypes
    using obstaclesClassified = std::vector<std::pair<float,std::string>>;

    //Functions
    obstaclesClassified classify_obstacles(const float* distances_ptr, const int size);
}