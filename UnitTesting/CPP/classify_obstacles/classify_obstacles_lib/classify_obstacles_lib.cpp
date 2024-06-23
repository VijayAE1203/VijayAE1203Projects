#include "classify_obstacles_lib.hpp"
#include "custom_exception/custom_exception.hpp"
#include <iostream>

namespace unittestdemo
{
    obstaclesClassified classify_obstacles(const float* distances_ptr, const int size)
    {
        obstaclesClassified obstacles;
        for (int i=0;i<size;i++)
        {
            float distance = *(distances_ptr+i);
            if (distance>0 && distance<=5)
            {
                obstacles.push_back(std::make_pair(distance,"Close"));
            }
            else if (distance>5 && distance<=15)
            {
                obstacles.push_back(std::make_pair(distance,"Medium"));
            }
            else if (distance>15 && distance<=100)
            {
                obstacles.push_back(std::make_pair(distance,"Far"));
            }
            else if (distance<0)
            {
                throw abnormal_distance_exception("Distance is negative");
            }
            else
            {
                throw abnormal_distance_exception("Distance is too far");
            }
        }
        return obstacles;
    }

}