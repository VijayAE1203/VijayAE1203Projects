DROP DATABASE IF EXISTS car_rental;
CREATE DATABASE car_rental;
USE car_rental;

CREATE TABLE Customers(
	Customer_ID INT NOT NULL AUTO_INCREMENT,
    Name VARCHAR(50) NOT NULL,
    Email_ID VARCHAR(50) NOT NULL,
    Password VARCHAR(50) NOT NULL,
    Phone VARCHAR(50) NOT NULL,
    DL_Number VARCHAR(50) NOT NULL,
    Address VARCHAR(50) DEFAULT NULL,
    PRIMARY KEY (Customer_ID)
);
INSERT INTO Customers VALUES(1,'John','john@gmail.com','12345','1234567890','IL-12345','123 Dr,Chicago,IL');
INSERT INTO Customers VALUES(2,'Jake','jake@gmail.com','23456','2345678901','IA-23456',DEFAULT);
INSERT INTO Customers VALUES(3,'Alex','alex@gmail.com','34567','3456789012','IA-34567','234 Dr,Des Moines,IA');
INSERT INTO Customers VALUES(4,'Katy','katy@gmail.com','45678','4567890123','NY-45678','345 Dr,New York,NY');
INSERT INTO Customers VALUES(5,'Bob','bob@gmail.com','56789','5678901234','SC-12345','123 Dr,Greenville,SC');

CREATE TABLE Orders(
	Order_ID INT NOT NULL AUTO_INCREMENT,
    Customer_ID INT NOT NULL,
    Car_ID INT NOT NULL,
    Order_Date DATE NOT NULL,
    PickUp_Date DATE NOT NULL,
    Drop_Date DATE NOT NULL,
    PickUp_Location VARCHAR(50) NOT NULL,
    Drop_Location VARCHAR(50) NOT NULL,
    Status_ID TINYINT NOT NULL,
    Miles_Driven MEDIUMINT NOT NULL DEFAULT 0,
    PRIMARY KEY (Order_ID),
    FOREIGN KEY k_Customer_ID (Customer_ID) REFERENCES Customers(Customer_ID)
);
INSERT INTO Orders VALUES(1,1,2,'2024-05-01','2024-05-05','2024-05-14','Chicago','Chicago',3,300);
INSERT INTO Orders VALUES(2,2,3,'2024-06-01','2024-06-02','2024-06-10','Ankeny','Ankeny',1,DEFAULT);
INSERT INTO Orders VALUES(3,2,4,'2023-05-10','2023-05-10','2023-05-20','Ankeny','Ankeny',3,250);
INSERT INTO Orders VALUES(4,3,1,'2024-02-07','2024-02-05','2024-02-11','Des Moines','Des Moines',3,325);
INSERT INTO Orders VALUES(5,4,7,'2024-05-31','2024-06-01','2024-07-01','New York','New York',2,DEFAULT);
INSERT INTO Orders VALUES(6,5,6,'2023-07-04','2023-07-05','2023-07-21','Greenville','Greenville',3,215);
INSERT INTO Orders VALUES(7,5,5,'2024-01-16','2024-01-16','2024-01-25','Greenville','Greenville',3,340);

CREATE TABLE Order_Status(
	Status_ID TINYINT NOT NULL,
    Status VARCHAR(50) NOT NULL,
    PRIMARY KEY (Status_ID)
);
INSERT INTO Order_Status VALUES(1,'Booked');
INSERT INTO Order_Status VALUES(2,'Picked up');
INSERT INTO Order_Status VALUES(3,'Returned');

CREATE TABLE Cars(
	Car_ID INT NOT NULL AUTO_INCREMENT,
    Make VARCHAR(50) NOT NULL,
    Model VARCHAR(50) NOT NULL,
    Currently_Booked TINYINT DEFAULT 0,
    Mileage INT NOT NULL,
    Price_Per_Day DECIMAL(10,2) NOT NULL,
    Last_Known_Location VARCHAR(50) NOT NULL,
    PRIMARY KEY (Car_ID)
);
INSERT INTO Cars Values(1,'Toyota','Corolla',0,50000,150.0,'Greenville');
INSERT INTO Cars Values(2,'Honda','Accord',0,40000,170.0,'Greenville');
INSERT INTO Cars Values(3,'Ford','Edge',0,35000,180.0,'Greenville');
INSERT INTO Cars Values(4,'Chevrolet','Trail Blazer',0,40000,170.0,'Greenville');
INSERT INTO Cars Values(5,'Chrysler','Pacifica',0,20000,220.0,'Greenville');
INSERT INTO Cars Values(6,'Dodge','RAM 1500',0,15000,200.5,'Greenville');
INSERT INTO Cars Values(7,'Subaru','WRX STI',0,10000,220.5,'Greenville');