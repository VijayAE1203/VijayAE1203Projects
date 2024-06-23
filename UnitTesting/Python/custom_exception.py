"""
distance_negative_exception class: Custom exception to handle negative object distances
"""
class distance_negative_exception(Exception):

    """
    Constructor for the distance_negative_exception class
    Raises an exception with the error message as distance negative
    """
    def __init__(self):
        self.message = "Distance is negative"
        super().__init__(self.message)