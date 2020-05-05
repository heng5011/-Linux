#!/bin/bash

#下载源代码
#git clone https://github.com/oblique/create_ap

#安装create_ap
#cd create_ap
#make install

#设置wifi
#sudo create_ap wlp3s0 enp2s0f1 your_ap_name your_ap_password
#your_ap_name：你要设置的热点名称
#your_ap_password：密码


cd /home/heng/create_ap
sudo create_ap wlp3s0 enp2s0 倒影_linux 66666666

exit 0
