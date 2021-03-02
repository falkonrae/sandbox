FROM debian:buster
COPY cli.php /cli.php

RUN apt-get update && apt-get upgrade -y
RUN apt-get install wget && apt-get install nginx && apt-get install mariadb-server && 
# установка утилиты wget, nginx, mysql (-y?)



RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
# устанока php утилит
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gzRUN mv phpMyAdmin-5.0.1-english phpmyadmin
# скачивает архив, распаковывает и удаляет архив.
COPY ./srcs/config.inc.php phpmyadmin


RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
# скачиваю архив вордпресса и распаковываю
COPY ./srcs/configwp.php wordpress
CMD ["9"] 
## CMD переопределяется, изменяется, если пользователь подает в консоль новое значение

# конфиг для нжинкс, папку копи (создать внутри контейнера), что делать с файлом в смд (два аргумента: баш и путь к скрипту с скриптом)