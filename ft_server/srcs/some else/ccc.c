server {
        listen 80;
        listen [::]:80;
        server_name localhost;
        return 301 https://$host$request_uri;
}
server {       
        listen 443 ssl ;
        listen [::]:443 ssl ;

        server_name localhost;

        ssl on;
        ssl_certificate /etc/ssl/nginx-selfsigned.crt;
        ssl_certificate_key /etc/ssl/nginx-selfsigned.key;
        root /var/www/html;
        index index.php;

        location / {
                autoindex on;
                try_files $uri $uri/ =404;
        }

        location ~ \.php$ {
                include snippets/fastcgi-php.conf;
                fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
        }
}




// ljkhfglkjdhfglkjshdlfkgjhsldjfghlsdjhglsdkjhgldsjhfgldsjhglksdhfglshdflgjhsdflgjhsdlfgjhsdlfkgjhdsfklgjhsdlfkgjhsdlfkghsdlfkgjhdsflkgjhdf it was file nginx.conf

<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'put your unique phrase here' );
define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );
define( 'LOGGED_IN_KEY',    'put your unique phrase here' );
define( 'NONCE_KEY',        'put your unique phrase here' );
define( 'AUTH_SALT',        'put your unique phrase here' );
define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );
define( 'LOGGED_IN_SALT',   'put your unique phrase here' );
define( 'NONCE_SALT',       'put your unique phrase here' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';





// roiehgoihsodgihosdiughosiduhgodisuhgoisdhgoisdhogish it was file wp-config.php






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





//asufgasd\kashgjhakgjhasgfkasd  it was init.sh