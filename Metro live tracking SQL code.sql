CREATE TABLE train_location (
   train_id INT PRIMARY KEY,
   latitude DECIMAL(10, 8),
   longitude DECIMAL(11, 8),
   speed DECIMAL(5, 2)
);
CREATE TABLE user_info (
   user_id INT PRIMARY KEY,
   latitude DECIMAL(10, 8),
   longitude DECIMAL(11, 8),
   name VARCHAR(50)
);
CREATE TABLE travel_log (
   user_id INT,
   station_name VARCHAR(50),
   FOREIGN KEY (user_id) REFERENCES user_info(user_id)
);
CREATE TABLE metro_stations (
   station_id INT PRIMARY KEY,
   station_name VARCHAR(50),
   latitude DECIMAL(10, 8),
   longitude DECIMAL(11, 8)
);
INSERT INTO metro_stations (station_id, station_name, latitude, longitude) VALUES
(1, 'RajivChowk', 28.633912, 77.218434),
(2, 'PatelNagar', 28.654081, 77.173192),
(3, 'Saket', 28.524578, 77.213074),
(4, 'Vaishali', 28.641425, 77.334932),
(5, 'INA', 28.575073, 77.206808),
(6, 'JorBagh', 28.584210, 77.207007),
(7, 'Ghitorni', 28.490920, 77.140932),
(8, 'KashmiriGate', 28.667856, 77.230715),
(9, 'QutubMinar', 28.501325, 77.186950),
(10, 'NoidaSector-4', 28.573128, 77.323790);
INSERT INTO user_info (user_id, latitude, longitude, name) VALUES (1, 28.633912,
77.218434, 'Navdeep Singh Jakhar');
INSERT INTO train_location (train_id, latitude, longitude, speed) VALUES (1001,
28.6139, 77.2090, 50);
INSERT INTO travel_log (user_id, station_name) VALUES (1, 'RajivChowk');