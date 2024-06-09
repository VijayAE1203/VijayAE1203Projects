1. All the contents in this project is my first attempt in creating a SQL database to help me learn MySQL.
2. The DataBaseDesign ppt file gives the architecture of the database
3. "create-database" creates an initial database with all the tables and some initial data to work with
4. "create-stored-procedures" creates a bunch of procedures to update tables and get some results. These are aimed at helping applications
    that can make use of this database and build an app or website.
5. "create-function-check-col-exists" creates a function to check if a column exists in a table. I created this just to learn how to do it.
6. "create-view" creates a view with the locations and the cars available in each location.
7. "create-wrapper-procedure" creates an outer procedure to add a new customer and also fill the customer's full name based on the first 
    and last name. Two stored procedures are called within a transaction to prevent from multiple sessions updating the table concurrently.
8. "modify-customer-table" is another sql script that modifies the database. Just a learning experience.
9. The python application folder has a python script that connects to the MySQL server (using mysql-connector-python module) and closes the connection. 
    A python application can be developed using this and can be tied to a frontend to create a website.

How to run/play with each script:
1. Just run the scripts in the following order to see what they do:
  a. create-database
  b. modify-customer-table
  c. create-function-check-col-exists,create-view,create-stored-procedures
  d. create-wrapper-procedure

2. You'd need to install MySQL and setup the server and create a local instance to connect to the server, before trying to run the scripts.

