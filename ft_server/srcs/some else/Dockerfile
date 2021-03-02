FROM debian:buster

LABEL maintainer name="Wtahm@Roza Minnullina"
LABEL mail="wtahm@student.21-school.ru" 

RUN apt-get update && apt-get install -y wget nginx mariadb-server php7.3 php-mysql php-fpm \
php-pdo php-gd php-cli php-mbstring php-xml

WORKDIR /var/www/html/

RUN wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm -rf latest.tar.gz

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz && \
tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz && \
mv phpMyAdmin-5.0.1-english phpmyadmin

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School/OU=21Kazan/CN=localhost" \
-newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

COPY config.inc.php phpmyadmin/
COPY wp-config.php wordpress/
COPY nginx.conf /etc/nginx/sites-enabled/ft_server.conf
COPY init.sh .

CMD ["/bin/bash", "init.sh"]

#CMD ["bash"]