USE car_rental;

CREATE VIEW location_cars
AS
SELECT Last_Known_Location, Make, Model, Mileage,Price_per_day
FROM Cars
ORDER BY Last_Known_Location;