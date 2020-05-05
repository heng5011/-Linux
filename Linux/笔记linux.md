*打开终端：`ctrl+alt+t`*

*清屏：`ctrl+l`*

*在终端在退出锁定：`ctrl+c`*

*目录：又称为文件夹，是包含所有的文件*

## 目录创建规则：

- 1、大小是`256`
- 2、不能包含特殊字符
- 3、见名知义 

路径：是反应目录和文件的位置
**[绝对位置]**文件位置：windows：盘符：\文件夹\文件.avi
	 linux: /home/主文件夹/0520/day01/a
	
**[相对位置]**当前目录所在位置为 0520 ./day01/a 
		day03 ../day01/a

	.\c...\01jibi\biji.txt
	..\c...\01biji\biji.txt


文件：在计算机中一切皆文件 
在windows中区分文件可以通过扩展名来区分 .exe .txt .ppt
在Linux中文件没有扩展名 可以通过颜色区分 也可以通过命令来区分 file 文件名

## 在Linux中文件分为：

- 普通文件
- 目录文件
- 设备文件   字符设备文件 块设备文件
- 管道文件
- 链接文件

文件权限：
读【`1`】read
写【`w`】write
执行【`x`】execute

d `rwx` `rwx` `rwx` 分为  **三组**
d 目录 成为文件类型

- 第一组：文件的所属用户
- 第二组：文件的所属组
- 第三组：其他用户

## Linux命令：

- 格式 ：`命令 选项  参数 `
- 帮助：

`命令 --help`
`man 命令`

快捷键：
`tab` 智能补全   如果没有重复的选项 自动补全 如果有重复项 **按两下**`tab` 显示列表
`↑ ↓` 历史记录 查看之前敲过的命令 关闭后还会提示 但是同时打开两个终端 相互不会提示

### 常用命令：

#### ls 【查看文件】

格式：
`ls -a` 查看所有文件包含隐藏文件
`ls -l` 以列表形式查看文件，不包含隐藏文件
`ls -lh `以列表形式查看文件，不包含隐藏文件 ，按照**1024**倍数显示**{KB MB GB}**
`ls -all`以列表形式查看文件，包含隐藏文件 快捷方式【`ll`】

通配符：
【*】 匹配任意多个字符【0-256】  a*  一个以上字符 256一下 
【?】 匹配任意一个字符  a？ 两个字符
【[a-z]】 区间法 匹配a到z的所有字符 只能确定一个字符
【[abcde]】 穷举法 权值法 匹配abcde的所有字符 只能确定一个字符

#### 切换工作目录：

`cd` 【切换工作目录】`cd 目录`
**格式：**
`cd` 切换到用户主目录
`cd ~ `切换到当前用户的主目录
`cd ..` 切换到上级目录 
`cd .  `切换到当前目录
`cd - ` 切换到上一次目录

#### 创建目录：

`mkdir` 目录名 -p 递归创建
`rmdir `目录名  目录一定是空的
`rm` 文件  -i询问 -r 递归传出

#### 链接：

格式：
`ln 源文件 链接文件 硬链接`
`ln -s 源文件 链接文件 软连接`
硬链接文件占磁盘空间 但是删除源文件不会影响硬链接文件
软链接文件不占磁盘空间 但是删除源文件会影响软链接文件

硬链接和拷贝（复制）区别 无论你修改了哪一个链接之后的文件 两个文件都会改变 保持一致  但是拷贝不会

- 1、改变软链接文件就是相当于间接的改变了源文件
- 2、查看文件时默认链接数为1 如果有链接一次递增
- 3、如果创建的软链接文件和源文件在不同的目录下，需要使用绝对路径

#### 文本搜索1：

`grep  '搜索内容' 文件名`
`-n` 显示行号
`-v` 反选
`-i `忽略大小写

通配符：
【^a】以a为起始的字符搜索文件
【a$】以a为结尾的字符搜索文件
【.】 配匹任意一个非换行的字符
【*】匹配任意字符（大于0的整数）

#### 文件搜索2：

`find 目录 参数 文件名（可以使用通配符）`
`-name` 文件名
`-size `大小
`-perm rwx`

#### 归档：

`tar -cvf 归档文件名.tar 文件1 文件2  目录1 目录2`

#### 解归档：

`tar -xvf 归档文件名.tar  -C 路径`

#### 压缩：

`gzip 归档文件名.tar`  生成了一个文件 `归档文件名.tar.gz `文件大小 小于归档文件大小 `归档文件名.tar`不存在了

#### 解压缩：

`gzip -d 归档文件名.tar.gz `生成了一个文件` 归档文件名.tar`

#### 一步归档压缩：

`tar -czvf 文件名.tar.gz 文件1 文件2 目录1 目录2`

#### 一步解归档压缩：

`tar -xzvf 文件名.tar.gz -C 路径`

#### bzip2压缩：

`tar -cjvf 文件名.tar.bz2 文件1 文件2 目录1 目录2`

#### bzip2解压缩：

`tar -xjvf 文件名.tar.bz2 -C 路径`

#### zip压缩：

`zip 文件名 文件1 文件2 目录1 目录2  生成一个文件为：文件名.zip`

#### unzip解压缩：

`unzip 文件名.zip -C 路径`





# 特殊装b特效命令 ：

```
sl                  #跑火车 sudo apt-get install sl
cmatrix             #代码雨    
cowsay +字符串       #小奶牛说你想说的话
命令 | lolcat        #彩虹效果展示命令效果
rev                 #一行接一行地颠倒字符串
aafire              #一把火  sudo apt-get install libaa-bin
cmatrix             #这个很酷！《黑客帝国》那种矩阵风格的动画效果。  cmatrix
boxes               #在输入的文本或者代码周围框上各种ASCII 艺术画   boxes
                     运行：& echo "shiyanlou.com" | boxes or 
                     $ echo "shiyanlou.com" | boxes                                                   -d dog
 xeyes 命令          # 一双眼      安装xeyes 
```



# 命令行打开应用

## 谷歌和deepin应用商店

```bash
google-chrome //谷歌
deepin-appstore -c //应用商店

```

## wps的一些操作

### 不带操作对象

```bash
et //wps表格
wps //wps文字
wpp //wps演示

```

### 带操作对象

```bash
et a.xls //打开wps表格程序,　并编辑a.xls文档
wps a.doc //打开wps文字程序, 并编辑a.doc文档
wps -w a.doc //打开新窗口
wps a.ppt //打开wps程序, 并编辑a.ppt文档
```

### 在后台运行

```bash
nohup et a.xls &
nohup wps a.doc &
nohup wpp a.ppt &
```



# **vim编写C、C++程序过程(以hello world为例)：**

**打开终端：`ctrl+alt+t`**
**清屏：`ctrl+l`**
**在终端在退出锁定：`ctrl+c`**

1、vim hello.c/hello.cpp。//创建hello.c/hello.cpp文件，并进入vim界面;

2、键入i，进入输入模式。
3、编写hello.c/hello.cpp程序。
4、先按Esc键，退出输入模式；然后，按Shift+:键，进入命令模式。输入wq，保存并退出。
5、编译hello.c/hello.cpp。
  5.1、对于C程序：用gcc hello.c便可编译;
  5.2、对于C++程序：用g++ hello.cpp可编译。编译后，均生成a.out的可执行文件;
6、键入指令"./a.out"，运行程序。

7、在Terminal上显示"hello world"即成功。

# 将文件上传到github仓库（本地操作）

### 1、终端运行以下指令：

```
git init
git add README.md
git commit -m"first commit"
git remote add origin git@github.com:××××××/day01.git
git push -u origin master
```

### 2、接下来创建一个文件夹

![DeepinScreenshot_select-area_20190410233151](/home/heng/Desktop/DeepinScreenshot_select-area_20190410233151.png)

把github上面的仓库克隆到本地

```
git clone https://github.com/xxxxx（https://github.com/xxxxx替换成你之前复制的地址）
```

![DeepinScreenshot_select-area_20190410232819](/home/heng/Desktop/DeepinScreenshot_select-area_20190410232819.png)

### 3、把需要上传的文件拷贝到刚下载的新文件夹中

### 4、接下来依次输入以下代码即可完成上传操作：

```
git add  . （注：别忘记后面的 . ，此操作是把Test文件夹下面的文件都添加进来）

git commit -m“提交信息” （注：“提交信息”里面换成你需要，如“first commit”）

git push -u origin master （注：此操作目的是把本地仓库push到github上面，此步骤需要你输入帐号和密码）
```

![DeepinScreenshot_select-area_20190410233334](/home/heng/Desktop/DeepinScreenshot_select-area_20190410233334.png)



![DeepinScreenshot_select-area_20190410233452](/home/heng/Desktop/DeepinScreenshot_select-area_20190410233452.png)

### 5、刷新网站页面就可以看到已经上传的文件

---

## ssh， github配置

```
cd .ssh
ls
ssh-keygen -t rsa
找到id_rsa.pub复制. 登录github 点击头像 选择settings 进入设置，然后选择ssh GPG keys 按钮 点击ssh添加 粘贴
ssh -T git@github.com

 # GitHub Start 
192.30.253.112 github.com 
192.30.253.119 gist.github.com 
151.101.100.133 assets-cdn.github.com 
151.101.100.133 raw.githubusercontent.com 
151.101.100.133 gist.githubusercontent.com 
151.101.100.133 cloud.githubusercontent.com 
151.101.100.133 camo.githubusercontent.com 
151.101.100.133 avatars0.githubusercontent.com 
151.101.100.133 avatars1.githubusercontent.com 
151.101.100.133 avatars2.githubusercontent.com 
151.101.100.133 avatars3.githubusercontent.com 
151.101.100.133 avatars4.githubusercontent.com 
151.101.100.133 avatars5.githubusercontent.com 
151.101.100.133 avatars6.githubusercontent.com 
151.101.100.133 avatars7.githubusercontent.com 
151.101.100.133 avatars8.githubusercontent.com
 # GitHub End
https://blog.csdn.net/qq_36589706/article/details/80573008
```



## 硬件

### 查看deepin下的网卡型号，主板型号，CPU/显卡信息，硬盘型号等

#### 系统

```
lspci | grep -i ethernet //查看电脑网卡型号
lspci -tv //列出所有PCI设备
lsmod /列出加载的内核模块
env /查看环境变量
uname -a //查看内核/操作系统/CPU信息
head -n 1 /etc/issue /查看操作系统版本
cat /proc/cpuinfo /查看CPU信息
hostname /查看计算机名

```

#### 资源

```
free -m //查看内存使用量和交换分区使用量
df -h //查看各分区使用情况
du -sh<目录名> //查看指定目录的大小
grep MemTotal /proc/meminfo //查看内存总量 /grep Mem Total /proc/meminfo
grep MemFree /proc/meminfo //查看空闲内存量 /grep Mem Free /proc/meminfo
uptime //查看系统运行时间、用户数、负载
cat /proc/loadavg //查看系统负载

```

#### 磁盘分区

```
mount | column -t //查看挂接的分区状态
fdisk -l // 查看所有分区
swapon -s //查看所有交换分区
hdparm -i /dev/hda //查看磁盘参数（仅适用于IDE设备）
dmesg | grep IDE //查看启动时IDE设备检测状况

```

#### 网络

```
ifconfig //查看所有网络接口的属性
iptables -L //查看防火墙设置
route -n //查看路由表
netstat -lntp //查看所有监听端口
netstat -antp //查看所有已经建立的链接
netstat -s //查看网络统计信息
nmcli //查看电脑DNS

```

### 进程

```
ps -ef //查看所有进程
top //实时显示进程状态

```

#### 用户

```
w //查看活动用户
id <用户名> //查看指定用户信息
last //查看用户登录日志
cut -d: -f1 /etc/passwd //查看系统所有用户
cut -d: -f1 /etc/group //查看系统所有组
crontab -l //查看当前用户计划任务

```

#### 服务

```
rpm -qa //查看所有安装包
```

---

# 一个命令安装系统所需基本软件

Deepin/Ubuntu缺省情况下，并没有提供C/C++的编译环境，因此还需要手动安装。但是如果单独安装``gcc``以及``g++``比较麻烦，幸运的是，Deepin/Ubuntu提供了一个`build-essential`软件包。查看该软件包的依赖关系：

```
y@ubuntu:~$ apt-cache depends build-essential
build-essential
 |Depends: libc6-dev
  Depends: <libc-dev>
    libc6-dev
  Depends: gcc
  Depends: g++
  Depends: make
    make-guile
  Depends: dpkg-dev
```

## 安装方法

```
sudo apt-get install build-essential #支持gcc/g++、make等命令
```

---

# 测试main()函数的返回值状态

## 使用echo $?查看命令执行成功的原理

在进行源代码编译，或者执行命令无法确认所执行的命令是否成功执行的情况下，我们都会使用echo $?来进行测试。

```
如果返回值是 0 ,就是执行成功；如果是返回值是 0 ,以外的值，就是失败。
```

```
当一个进程执行完毕时，该进程会调用一个名为_exit的例程来通知内核它已经做好"消亡"的准备了。该进程会提供一个退出码(一个整数)表明它准备退出的原因。按照惯例，0用来表示正常的或者说"成功"的终止。
```

​	也就是说我们在执行**echo $?**时返回的值就是进程的退出码。而且，这个退出码是由刚刚执行完的进程提供给系统内核的。



# 更换内核(可以解决触摸板不能用问题)

[deepin wiki]:<https://wiki.deepin.org/wiki/Linux%E5%86%85%E6%A0%B8>
[ubuntu主要的内核版本地址]:<https://kernel.ubuntu.com/~kernel-ppa/mainline/>



# 清除已卸载软件遗留配置

```
dpkg --get-selections |grep deinstall | sed 's/deinstall/\lpurge/' | sudo dpkg --set-selections; sudo dpkg -Pa

```

---

# 开机突然显示XFRM

```bash
vim /etc/default/grub

acpi_osi=Linux nomodeset
或
acpi_osi="!Windows 2015"


```

# deepin窗口特效无法开启

```bash
sudo apt-get install deepin-wm

deepin-wm --replace> /dev/null 2>&1 &
```

