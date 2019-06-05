#!/bin/bash

echo "installation openssl"
echo "extraction"
cd /home/pi
sudo tar xvzf /home/pi/openssl-1.1.0j.tar.gz -C /usr/local/src
cd /usr/local/src/openssl-1.1.0j/
echo "configuration"
sudo ./config
sudo make
sudo make install
echo "installation openssl finit"
echo "installation poco"
echo "extraction"
cd /home/pi
sudo tar xvzf /home/pi/poco-1.9.0-all.tar.gz -C /usr/local
cd /usr/local/poco-1.9.0-all/
echo "configuration"
sudo ./configure
sudo make -s -j4
sudo make install 
sudo cp /usr/local/lib/*.so.60 /usr/lib
