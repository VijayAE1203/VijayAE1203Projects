#include <iostream>
#include "classify_obstacles_lib/classify_obstacles_lib.hpp"
#include "custom_exception/custom_exception.hpp"

using unittestdemo::obstaclesClassified;
using unittestdemo::classify_obstacles;
using unittestdemo::abnormal_distance_exception;

int main(void)
{
    const float distances[10] = {14,23,5,45,2,7,13,64,41,0};
    int size = sizeof(distances)/sizeof(distances[0]);
    obstaclesClassified obstacles;
    try
    {
        obstacles = classify_obstacles(distances,size);
    }
    catch(abnormal_distance_exception e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
