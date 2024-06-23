#include "classify_obstacles_lib/classify_obstacles_lib.hpp"
#include "custom_exception/custom_exception.hpp"
#include <gtest/gtest.h>

using unittestdemo::obstaclesClassified;
using unittestdemo::classify_obstacles;
using unittestdemo::abnormal_distance_exception;

TEST(classify_obstacles_test,HandlesTooFarInputs)
{
    const float distances[3] = {14,23,500};
    int size = sizeof(distances)/sizeof(distances[0]);
    obstaclesClassified obstacles;
    try
    {
        obstacles = classify_obstacles(distances,size);
    }
    catch(const abnormal_distance_exception& e)
    {
        EXPECT_STREQ(e.what(),"Distance is too far");
    }
}

TEST(classify_obstacles_test,HandlesNegativeInputs)
{
    const float distances[3] = {14,23,-20};
    int size = sizeof(distances)/sizeof(distances[0]);
    obstaclesClassified obstacles;
    try
    {
        obstacles = classify_obstacles(distances,size);
    }
    catch(const abnormal_distance_exception& e)
    {
        EXPECT_STREQ(e.what(),"Distance is negative");
    }
}

TEST(classify_obstacles_test,HandlesValidInputs)
{
    const float distances[3] = {4,11,25};
    int size = sizeof(distances)/sizeof(distances[0]);
    obstaclesClassified obstacles;
    obstaclesClassified obstacles_expected;
    obstacles_expected.push_back(std::make_pair(4,"Close"));
    obstacles_expected.push_back(std::make_pair(11,"Medium"));
    obstacles_expected.push_back(std::make_pair(25,"Far"));
    try
    {
        obstacles = classify_obstacles(distances,size);
    }
    catch(const abnormal_distance_exception& e)
    {
        FAIL();
    }
    for(int i=0;i<obstacles.size();i++)
    {
        EXPECT_EQ(obstacles[i].first,obstacles_expected[i].first);
        EXPECT_STREQ(obstacles[i].second.c_str(),obstacles_expected[i].second.c_str());
    }
}

TEST(classify_obstacles_test,HandlesEdgeCases)
{
    const float distances[3] = {5,15,100};
    int size = sizeof(distances)/sizeof(distances[0]);
    obstaclesClassified obstacles;
    obstaclesClassified obstacles_expected;
    obstacles_expected.push_back(std::make_pair(5,"Close"));
    obstacles_expected.push_back(std::make_pair(15,"Medium"));
    obstacles_expected.push_back(std::make_pair(100,"Far"));
    try
    {
        obstacles = classify_obstacles(distances,size);
    }
    catch(const abnormal_distance_exception& e)
    {
        FAIL();
    }
    for(int i=0;i<obstacles.size();i++)
    {
        EXPECT_EQ(obstacles[i].first,obstacles_expected[i].first);
        EXPECT_STREQ(obstacles[i].second.c_str(),obstacles_expected[i].second.c_str());
    }
}