show databases;

drop database if exists typelock_db;

CREATE DATABASE IF NOT EXISTS typelock_db;

use typelock_db;

-- table to hold user's name and metrics...
CREATE TABLE user_data( username varchar(20) PRIMARY KEY NOT NULL,
										name varchar(150) NOT NULL,
                                        passphrase MEDIUMTEXT);
                                        
 
 describe user_data;
 -- describe passphrase;
 

-- DML STARTS HERE --
INSERT INTO user_data VALUES
	('tn334', 'Taylor Nielsen', "[['h', 1679889122.2529793], ['e', 1679889122.4101489], ['l', 1679889122.7005913], ['l', 1679889122.835895], ['o', 1679889123.0113287], [' ', 1679889123.3163812], ['w', 1679889123.4281843], ['o', 1679889123.5736675], ['r', 1679889123.6950784], ['l', 1679889123.8027327], ['d', 1679889123.9605658]]");


-- describe passphrase;
--  TABLE passphrase(letter_index int NOT NULL,
-- 										username varchar(20) NOT NULL,
-- 										key_press varchar(255) NOT NULL,
--                                      timestamp double(17, 7) NOT NULL,
--                                      PRIMARY KEY (letter_index, username),
--                                      foreign key (letter_index) references user_data(username) on delete cascade);

-- INSERT INTO passphrase VALUES
-- 	(1, 'tn334', 'h', 1679889122.2529793),
-- 	(2, 'tn334', 'e', 1679889122.4101489),
-- 	(3, 'tn334', 'l', 1679889122.7005913),
-- 	(4, 'tn334', 'l', 1679889122.835895),
-- 	(5, 'tn334', 'o', 1679889123.0113287),
-- 	(6, 'tn334', ' ', 1679889123.3163812),
-- 	(7, 'tn334', 'w', 1679889123.4281843),
-- 	(8, 'tn334', 'o', 1679889123.5736675),
-- 	(9, 'tn334', 'r', 1679889123.6950784),
-- 	(10, 'tn334', 'l', 1679889123.8027327),
-- 	(11, 'tn334', 'd', 1679889123.9605658);