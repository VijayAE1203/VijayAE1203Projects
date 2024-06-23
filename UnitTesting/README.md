This is a small project that implements unit testing in python using pytest and C++ using google tests.
A function that classifies the obstacles into different categories as Close, Mid and Far based on distances is created.
A custom exception for handling negative distance and distances greater than 100m is created.
Unit tests with different scenarios: Negative, Far, Edge cases and valid inputs are created

To run pytest: pytest .\tests\test_classify_distance.py
To build C++ program: bazel build //custom_exception:custom_exception; bazel build //classify_obstacles_lib:classify_obstacles_lib; bazel build //classify_obstacles:classify_obstacles 
To run C++ google test: bazel test --test_output=all //google_test:classify_obstacles_test

Note: Navigate to the corresponding folders or change the folder paths in the command. 

Dependencies: For python, install pytest
              For C++, install bazel and MSVC compiler
