# Setting up an Apache Web Server on Debian.

These are the two references I used to deploy my application:
https://www.bogotobogo.com/python/Flask/Python_Flask_HelloWorld_App_with_Apache_WSGI_Ubuntu14.php
https://www.digitalocean.com/community/tutorials/how-to-deploy-a-flask-application-on-an-ubuntu-vps

For this lecture we are going to get a simple flask application running.

To start, make sure you have git installed and clone this repository.

```
sudo apt-get install git
git clone https://github.com/melvyniandrag/NJCU_Linux_Class.git
```

Then install some dependencies.

```
sudo su -
sudo apt-get install python3-pip python3-dev
sudo apt-get install apache2 libapache2-mod-wsgi-py3
pip3 install flask flask_restful
```
Then set up your webserver to host the web application stored in NJCU_Linux_Class/Week9/Apache*.

FLASKAPPS goes under /var/www

Remove or rename /var/www/html

flaskapp.conf goes under /etc/apache2/sites-available

Change ServerName in /etc/apache2/sites-available/flaskapp.conf to point to your server ip addresss

( a way to  get the server ip  is curl ipinfo.io/ip )

```
sudo a2enmod wsgi
sudo a2ensite flaskapp
sudo service apache2 restart
```

Then you can access the website with curl ( from a different machine! Don't do this from the web server, it won't work. )

```
curl $IP_ADDRESS
```

If you can't access the site on a different ip address, then update your /etc/hosts and the apache conf. This could happen due to firewall settings that will ( for a variety of reasons ) prevent you from accessing your website.

flaskapp.conf:
ServerName mysite.com

/etc/hosts:
127.0.0.1 mysite.com

Then restart the server and now you can use curl like

curl localhost

