import pytest

from classify_obstacles import classify_obstacles
from custom_exception import distance_negative_exception

"""
test_classify_obstacles function: Unit test function that asserts proper behavior of the classify_obstacles function
"""
def test_classify_obstacles():

    #Test case 1
    #Check if the distances are categorized properly
    distance = [1,6,12]
    des_result = {"Close":[1],
              "Medium":[6,12],
              "Far":[]}
    act_result = classify_obstacles(distance)
    assert act_result == des_result

    #Test case 2
    #Check if the exception is raised when a negative distance is given as input argument
    distance = [1,2,-1]
    des_result = 0
    try:
        classify_obstacles(distance)
        act_result = 1
    except distance_negative_exception:
        act_result = 0
    finally:
        assert act_result == des_result