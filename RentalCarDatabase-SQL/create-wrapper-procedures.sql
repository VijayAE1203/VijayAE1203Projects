USE car_rental;

DELIMITER \\
DROP PROCEDURE IF EXISTS w_add_new_customer \\
CREATE PROCEDURE w_add_new_customer (IN p_First_Name VARCHAR(50),
								  IN p_Last_Name VARCHAR(50),
								  IN p_Email VARCHAR(50),
								  IN p_Password VARCHAR(50),
                                  IN p_Phone VARCHAR(50),
                                  IN p_DL_Number VARCHAR(50),
                                  IN p_Address VARCHAR(50))
BEGIN
	
	DECLARE exit handler FOR SQLEXCEPTION
    BEGIN
		SHOW ERRORS;
		ROLLBACK;
	END;
    
	START TRANSACTION;
		CALL add_new_customer(p_First_Name, p_Last_Name, p_Email, p_Password, p_Phone, p_DL_Number, p_Address);
        CALL fill_full_name(LAST_INSERT_ID());
		COMMIT;
END \\

CALL w_add_new_customer('Vijay','Lakshmanan','vradhak@clemson.edu','babu','12342341223','TN-123434','123 Dr,City');
