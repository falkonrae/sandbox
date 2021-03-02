#!/bin/bash

service nginx start
echo "nginx started"

service mysql start
echo "mysql started"

service php7.3-fpm start
echo "php7.3-fpm started"

echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "database created"
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "priveleges granted"
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "priveleges flushed"
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password
echo "user plugins updated"

chown -R www-data /var/www/*
chmod -R 755 /var/www/*
echo "/var/www permissions updated"

/bin/bash