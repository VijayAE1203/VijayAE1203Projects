USE car_rental;

DELIMITER \\
DROP PROCEDURE IF EXISTS add_new_customer \\
CREATE PROCEDURE add_new_customer(IN p_First_Name VARCHAR(50),
								  IN p_Last_Name VARCHAR(50),
								  IN p_Email VARCHAR(50),
								  IN p_Password VARCHAR(50),
                                  IN p_Phone VARCHAR(50),
                                  IN p_DL_Number VARCHAR(50),
                                  IN p_Address VARCHAR(50))
BEGIN
	INSERT INTO Customers (First_Name,
						   Last_Name,
						   Email_ID,
                           Password,
                           Phone,
                           DL_Number,
                           Address)
    VALUES(p_First_Name,
		   p_Last_Name,
           p_Email,
           p_Password,
           p_Phone,
           p_DL_Number,
           p_Address);
	CALL fill_full_name(LAST_INSERT_ID());
END \\

DROP PROCEDURE IF EXISTS fill_full_name \\
CREATE PROCEDURE fill_full_name(IN p_Customer_ID INT)
BEGIN
	UPDATE Customers
    SET Full_Name = CONCAT(First_Name,' ',Last_Name)
    WHERE Customer_ID = p_Customer_ID;
    
    SELECT * FROM Customers
    WHERE Customer_ID=p_Customer_ID;
END \\

DROP PROCEDURE IF EXISTS get_available_cars \\
CREATE PROCEDURE get_available_cars(IN p_pickup_location VARCHAR(50), IN p_pickup_date date, IN p_drop_date date)
BEGIN
	SELECT c.Make,c.Model,c.Mileage,c.Price_Per_day
    FROM Cars c
    JOIN Orders o
    ON c.Car_ID = o.Car_ID
    WHERE c.Last_Known_Location = p_pickup_location
    AND (o.Drop_Date<p_pickup_date OR o.Pickup_Date>p_drop_date);
END \\ 

DROP PROCEDURE IF EXISTS update_order_status \\
CREATE PROCEDURE update_order_status(IN p_order_id INT, IN p_order_status_id TINYINT)
BEGIN
	UPDATE Orders o
    SET o.Status_ID = p_order_status_id
    WHERE o.Order_ID = p_order_id;
    
    IF p_order_status_id = 3 THEN
		UPDATE Cars c
		SET c.Last_Known_Location = (SELECT ord1.Drop_Location
									FROM Orders ord1
									WHERE ord1.Order_ID = p_order_id)
		WHERE c.Car_ID = (SELECT ord2.Car_ID
						FROM Orders ord2
						WHERE ord2.Order_ID = p_order_id);
	END IF;
END \\

DELIMITER ;