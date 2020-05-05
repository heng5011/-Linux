# deepin-linux常用命令大全

**基本命令您可以通过以下命令来查看系统的信息，其他系统相关命令操作可自行搜索查询。**

### 查看系统版本 

cat /etc/deepin-version

### 查看内核版本 

uname -a

### 查看软件源信息 

cat /etc/apt/sources.list

### 查看命令帮助

 man chmod 或 chmod --help

## Apt命令您可以通过以下命令来查看、安装、卸载、清理、升级等信息。

### 更新包列表 

sudo apt-get update

### 安装/升级所有可用更新 

sudo apt-get dist-upgrade

### 安装应用程序更新 

sudo apt-get upgradedselect

### 安装更新 

sudo apt-get dselect-upgrade

### 查找软件包 

sudo apt-cache search package

### 显示包相关信息 

sudo apt-cache show package

### 显示系统安装统计信息 

sudo apt-cache stats

### 显示包的相关依赖 

sudo apt-cache depends package

### 安装软件

 sudo apt-get install package

### 重装软件

 sudo apt-get install package --reinstall

### 强制安装软件 

sudo apt-get -f install package

### 卸载软件 

sudo apt-get remove package

### 卸载软件及配置 

sudo apt-get remove package --purge

### 清理旧版本软件缓存

 sudo apt-get autoclean

### 清理所有软件缓存 

sudo apt-get clean

### 清理不再使用的孤立软件

 sudo apt-get autoremove



### 删除更新和升级的缓存软件 

cd /var/cache/apt/archives 和 sudo rm \*.deb**

## Deb命令

可以通过以下命令来查看、安装、卸载、清理、升级等信息

`sudo dpkg -l `查看软件包的详细情况，iU表示未安装成功,ii表示安装成功。

`sudo dpkg -s` 查询已安装的deb包的信息。

`sudo dpkg -Lpackage|more `查看软件包的安装情况。

`sudo dpkg -S `查看软件属于哪个软件包。

`sudo dpkg -i `安装`deb`包，部分存在`depends`关系，需要使用`sudo apt-get -finstall`来解决。

`sudo dpkg -r` 卸载指定的`deb`包，不删除软件包的配置文件。

`sudo dpkg -P` 卸载`deb`包同时也删除配置文件，部分存在`depends`关系，需要使用`sudo apt-get remove`来解决。

## 关机和重启

在深度终端界面，可以直接输入 `init 0` 进行关机。

在深度终端界面，可以直接输入  `reboot` 进行重启。

## Vi命令

本章重点介绍vi命令的相关操作，关于系统中如何查看系统硬件信息，如：硬盘、内存、进

程、网络、服务、文件权限等请自行搜索。

### 使用Vi新建或打开

**vi filename :** 打开或新建文件，并将光标置于第一行首

**vi +n filename** ：打开文件，并将光标置于第n行首

**vi + filename ：**打开文件，并将光标置于最后一行首

**vi -r filename ：**在上次正用vi编辑时发生系统崩溃，恢复filename

**vi filename....filename ：**打开多个文件，依次进行编辑移动光标类命令

**h ：**光标左移一个字符

**l ：**光标右移一个字符

**space：**光标右移一个字符

**Backspace：**光标左移一个字符

**k或Ctrl+p：**光标上移一行

**j或Ctrl+n ：**光标下移一行

**Enter ：**光标下移一行

**w或W ：**光标右移一个字至字首

**b或B ：**光标左移一个字至字首

**e或E ：**光标右移一个字至字尾

**shift + ) ：**光标移至句尾

**shift + ( ：**光标移至句首

**shitf + }：**光标移至段落开头

**shift + {：**光标移至段落结尾

**shift + nG：**光标移至第n行首

**n+：**光标下移n行

**n-：**光标上移n行

**n$：**光标移至第n行尾

**H ：**光标移至屏幕顶行

**M ：**光标移至屏幕中间行

**L ：**光标移至屏幕最后行

**0：**光标移至当前行首-注意是数字零

**$：**光标移至当前行尾

### 屏幕翻滚类命令

**Ctrl+u：**向文件首翻半屏

**Ctrl+d：**向文件尾翻半屏

**Ctrl+f：**向文件尾翻一屏

**Ctrl+b：**向文件首翻一屏

### 插入文本类命令**

i ：在光标前

I ：在当前行首

a：光标后

A：在当前行尾

o：在当前行之下新开一行

O：在当前行之上新开一行

r：替换当前字符

R：替换当前字符及其后的字符，直至按ESC键

s：从当前光标位置处开始，以输入的文本替代指定数目的字符

S：删除指定数目的行，并以所输入文本代替之

ncw或nCW：修改指定数目的字

nCC：修改指定数目的行删除命令

ndw或ndW：删除光标处开始及其后的n-1个字

do：删至行首

d$：删至行尾

ndd：删除当前行及其后n-1行

x或X：删除一个字符，x删除光标后的，而X删除光标前的

Ctrl+u：删除输入方式下所输入的文本搜索及替换命令

/pattern：从光标开始处向文件尾搜索pattern

?pattern：从光标开始处向文件首搜索pattern

n：在同一方向重复上一次搜索命令

N：在反方向上重复上一次搜索命令

:s/p1/p2/g：将当前行中所有p1均用p2替代

:n1,n2s/p1/p2/g：将第n1至n2行中所有p1均用p2替代

:g/p1/s//p2/g：将文件中所有p1均用p2替换行方式命令

:n1,n2 co n3 将n1行到n2行之间的内容拷贝到第n3行下

:n1,n2 m n3 将n1行到n2行之间的内容移至到第n3行下

:n1,n2 d 将n1行到n2行之间的内容删除

:w 保存当前文件

:e filename 打开文件filename进行编辑

:x 保存当前文件并退出

:q 退出vi

:q! 不保存文件并退出vi

## 系统安装及更新

sudo apt-get update  更新

sudo apt-get upgrade  更新

sudo apt-get dist-upgrade 更新

fc-cache -vf  安装字体**

sudo nautilus /etc/apt/sources.list.d   ****显示部分安装的源，可以进行删除**

**软件安装（一些必要软件）**

sudo apt-get install synaptic 安装新立得软件包管理器

sudo apt-get install deepin-appstore　安装深度软件商店

sudo apt-get install deepin-game-center　安装深度游戏中心

sudo apt autoremove  卸载无用的包

sudo apt-get clean  清理包

sudo apt install browser-plugin-freshplayer-pepperflash  安装flash

sudo update-pepperflashplugin-nonfree --install   更新flash

sudo apt-get install firefox-locale-zh-hans 火狐浏览器中文界面

sudo apt-get install thunderbird-locale-zh-hans  雷鸟邮件 中文界面

sudo rm /etc/apt/sources.list.d/maxthon-browser.list 删除遨游源

sudo apt-get install love-wallpaper  安装爱壁纸软件

<<<<<<< HEAD
sudo apt-get install dkms -y  安装dkms**

sudo aptitude purge maxthon-browser-stable -y  卸载遨游软件**

sudo install fcitx-table-wbpy  安装五笔拼音**
=======
sudo apt-get install dkms -y  安装dkms

sudo aptitude purge maxthon-browser-stable -y  卸载遨游软件

sudo install fcitx-table-wbpy  安装五笔拼音
>>>>>>> first

## 优化处理

sudo apt-get autoclean         清理过期的软件包

sudo apt-get  autoremove    **自动卸载没有软件依赖关系的软件**

sudo apt-get clean    清理apt下载安装软件时的缓存文件

sudo os-prober 搜索其他系统

sudo update-grub 更新启动项设置

deepin-appstore -c 清除商店缓存

sudo nautilus /var/cache/apt/archives　优化下载软件

sudo service  lightdm restart      重启桌面

sudo apt-get install nload    打开深度终端，安装 nload 并用它查看网速，执行如下命令:`nload -u K`

***https://www.zcjun.com/linux/59.html***

google-chrome &  在后台运行谷歌浏览器