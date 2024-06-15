from custom_exception import distance_negative_exception

"""
classify_obstacles function: Classifies obstacles based on their distances from ego vehicle
@param distance Distance of the objects in a list format
@return obstacles Dictionary with keys Close, Medium and Far and corresponding values
"""
def classify_obstacles(distance=[]):
    
    #Initialize a dictionary with empty lists
    obstacles = {"Close":[],
                 "Medium":[],
                 "Far":[]}
    
    #Check for empty list
    if len(distance)==0:
        return obstacles
    #Categorize the distances
    # 0 to 5 - Close
    # 5.1 to 15 - Medium
    # 15.1 to 100 - Far
    else:
        for dist in distance:
            if dist>0 and dist<=5:
                obstacles["Close"].append(dist)
            elif dist>5 and dist<=15:
                obstacles["Medium"].append(dist)
            elif dist>15 and dist<=100:
                obstacles["Far"].append(dist)
            elif dist<0:
                raise distance_negative_exception
        return obstacles

