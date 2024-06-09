USE car_rental;

DROP FUNCTION IF EXISTS check_column_exists;
DELIMITER //
CREATE FUNCTION check_column_exists(p_column_name VARCHAR(50),p_table_name VARCHAR(50))
RETURNS TINYINT
READS SQL DATA
BEGIN
	DECLARE col_count INT;
    DECLARE col_exists TINYINT;
    
    SELECT COUNT(*)
	INTO col_count
	FROM information_schema.COLUMNS
	WHERE TABLE_SCHEMA = DATABASE()
	AND TABLE_NAME = p_table_name
	AND COLUMN_NAME = p_column_name;
    
	SET col_exists = IF(col_count>0,1,0);
    RETURN col_exists;
END //
DELIMITER ;
