USE car_rental;

ALTER TABLE Customers
CHANGE Name First_Name VARCHAR(50);
    
ALTER TABLE Customers
ADD COLUMN Last_Name VARCHAR(50) AFTER First_Name;

ALTER TABLE Customers
ADD COLUMN Full_Name VARCHAR(100) AFTER Last_Name;

UPDATE Customers
SET Last_Name = (CASE WHEN Customer_ID=1 THEN 'Smith'
					  WHEN Customer_ID=2 THEN 'Johnson'
                      WHEN Customer_ID=3 THEN 'Stuart'
                      WHEN Customer_ID=4 THEN 'Babu'
                      WHEN Customer_ID=5 THEN 'Rob'
				END)
WHERE Customer_ID IN (1,2,3,4,5);

UPDATE Customers
SET Full_Name = CONCAT(First_Name,' ',Last_Name);

SELECT * FROM Customers;
