# 一、文件目录类：

## 1、cd命令

这是一个非常基本，也是大家经常需要使用的命令，它用于切换当前目录，它的参数是要切换到的目录的路径，可以是绝对路径，也可以是相对路径。如：

```
cd           #root根目录
cd   /       #系统根目录 
cd  ../../   #返回上上一层目录 
```

## 2、ls命令

这是一个非常有用的查看文件与目录的命令，list之意，它的参数非常多，下面就列出一些我常用的参数吧，如下：

```
-l ：列出长数据串，包含文件的属性与权限数据等
-a ：列出全部的文件，连同隐藏文件（开头为.的文件）一起列出来（常用）
-d ：仅列出目录本身，而不是列出目录的文件数据
-h ：将文件容量以较易读的方式（GB，kB等）列出来
-R ：连同子目录的内容一起列出（递归列出），等于该目录下的所有文件都会显示出来
					
注：这些参数也可以组合使用，下面举两个例子：
ls -l #以长数据串的形式列出当前目录下的数据文件和目录
ls -lR #以长数据串的形式列出当前目录下的所有文件
```

## 3、chgrp命令

该命令用于改变文件所属用户组，它的使用非常简单，它的基本用法如下：

```
chgrp [-R] dirname/filename
-R ：进行递归的持续对所有文件和子目录更改
# 例如：
chgrp users -R ./dir # 递归地把dir目录下中的所有文件和子目录下所有文件的用户组修改为users
```

## 4、chmod 改变文件/目录的权限

```
chmod ugo+r    文件          #所有人皆可读取
chmod a+r      文件          #所有人皆可读取
chmod ug+w,o-w 文件          #设为该档案拥有者，与其所属同一个群体者可写入，但其他以外的人则不可写入
chmod u+x      文件          #创建者拥有执行权限 
chmod a-x      文件          #收回所有用户的对文件的执行权限
chmod 777      文件          #所有人可读，写，执行
```

## 5、pwd (print working directory) 显示工作目录

```
pwd          #显示当前工作目录
```

## 6、dirs  显示目录记录

```
dirs    +n       #显示从左边算起第n笔的目录。
dirs    -n       #退一级目录的路径
dirs    -l       #显示目录完整的记录。
```

## 7、mkdir (make directories) 显示目录

```
mkdir            +文件名                        #创建目录
mkdir   -m      （--mode）+a=权限+目录名         #设置目录权限（rwx）例：mkdir -m a=rw bbb   创建目录bbb，权限为rw（a是模式固定写法）
mkdir   -p      （--parents）+父目录/子目录      #若所要建立目录的上层目录目前尚未建立，则会一并建立上层目录  例1：mkdir -p 111/abc    创建abc目录，111为子目录  例2：mkdir -p /ms/{sales,hr,web}   创建一个名为/ms的目录，其中有sales、hr、web的子目录 
mkdir   -pv      +目录名                        #批量创建目录  例：mkdir -pv /tmp/test/{a1,b1}/{c1,d1}
mkdir   -v      （--verbose）                   #创建目录,并显示详细信息
```

## 8、rmdir 删除空目录

```
rmdir            +目录名             #删除目录，注意必须是空目录
rmdir    -p      +目录/目录/目录      #删除指定目录及其上级文件夹  例：rmdir -p a/b/c
```

## 9、touch 创建文件

```
touch            +文件名           #将文件的创建时间改为当前时间，文件不存在则建之  例：touch test.php  将test.php的档案时间改为，当前时间，文件不存在建之
touch   -c -t 时间 +文件名          #将档案时间改为特定时间  例：touch -c -t 05061803 test.php     将档案时间改为,5月6日18点3分
touch   -r                         #参考文件名 目标文件名  将目标文件档案改成跟参考文件一样 例： touch -r abc.php test.php   将test.php档案改成跟abc.php一样
touch   d 时间 文件名                #将文件日期改为特定天数时间  例：touch -d "2 days ago" test.php   将test.php日期修改为2天以前
```

------

# 二、文件管理类：

## 1、find命令

find是一个基于查找的功能非常强大的命令，相对而言，它的使用也相对较为复杂，参数也比较多，所以在这里将给把它们分类列出，它的基本语法如下：

```
find [PATH] [option] [action]

# 与时间有关的参数：
-mtime n : n为数字，意思为在n天之前的“一天内”被更改过的文件；
-mtime +n : 列出在n天之前（不含n天本身）被更改过的文件名；
-mtime -n : 列出在n天之内（含n天本身）被更改过的文件名；
-newer file : 列出比file还要新的文件名
# 例如：
find /root -mtime 0 # 在当前目录下查找今天之内有改动的文件

# 与用户或用户组名有关的参数：
-user name : 列出文件所有者为name的文件
-group name : 列出文件所属用户组为name的文件
-uid n : 列出文件所有者为用户ID为n的文件
-gid n : 列出文件所属用户组为用户组ID为n的文件
# 例如：
find /home/ljianhui -user ljianhui # 在目录/home/ljianhui中找出所有者为ljianhui的文件

# 与文件权限及名称有关的参数：
-name filename ：找出文件名为filename的文件
-size [+-]SIZE ：找出比SIZE还要大（+）或小（-）的文件
-tpye TYPE ：查找文件的类型为TYPE的文件，TYPE的值主要有：一般文件（f)、设备文件（b、c）、
             目录（d）、连接文件（l）、socket（s）、FIFO管道文件（p）；
-perm mode ：查找文件权限刚好等于mode的文件，mode用数字表示，如0755；
-perm -mode ：查找文件权限必须要全部包括mode权限的文件，mode用数字表示
-perm +mode ：查找文件权限包含任一mode的权限的文件，mode用数字表示
# 例如：
find / -name passwd # 查找文件名为passwd的文件
find . -perm 0755 # 查找当前目录中文件权限的0755的文件
find . -size +12k # 查找当前目录中大于12KB的文件，注意c表示byte
```

## 2、cp命令

该命令用于复制文件，copy之意，它还可以把多个文件一次性地复制到一个目录下，它的常用参数如下：
-a ：将文件的特性一起复制
-p ：连同文件的属性一起复制，而非使用默认方式，与-a相似，常用于备份
-i ：若目标文件已经存在时，在覆盖时会先询问操作的进行
-r ：递归持续复制，用于目录的复制行为
-u ：目标文件与源文件有差异时才会复制
例如 ：

```
cp -a file1 file2 #连同文件的所有特性把文件file1复制成文件file2
cp file1 file2 file3 dir #把文件file1、file2、file3复制到目录dir中
```

## 3、mv命令

该命令用于移动文件、目录或更名，move之意，它的常用参数如下：

```
mv  -b       (--backup）+ 目标文件或路径 　      #移动到目标目录，若覆盖文件，则先备份
mv  -f      （--force ）+ 目标文件或路径         #强制覆盖，没有目标文件时相当于备份
mv  -i      （--interactive）+ 目标文件或路径  　#覆盖前先行询问用户
mv  -u      （--update）+ 目标文件或路径 　      #在移动或更改文件名时，若目标文件已存在，且其文件日期比源文件新，则不覆盖目标文件。 
```

## 4、rm命令

该命令用于删除文件或目录，remove之间，它的常用参数如下：

```
-f ：就是force的意思，忽略不存在的文件，不会出现警告消息
-i ：互动模式，在删除前会询问用户是否操作
-r ：递归删除，最常用于目录删除，它是一个非常危险的参数
例如：
rm -i file # 删除文件file，在删除之前会询问是否进行该操作
rm -fr dir # 强制删除目录dir中的所有文件
```

## 5、file命令

该命令用于判断接在file命令后的文件的基本数据，因为在Linux下文件的类型并不是以后缀为分的，所以这个命令对我们来说就很有用了，它的用法非常简单，基本语法如下：

```
file filename
#例如：
file ./test
```

## 6、tar命令

该命令用于对文件进行打包，默认情况并不会压缩，如果指定了相应的参数，它还会调用相应的压缩程序（如gzip和bzip等）进行压缩和解压。它的常用参数如下：

```
-c ：新建打包文件
-t ：查看打包文件的内容含有哪些文件名
-x ：解打包或解压缩的功能，可以搭配-C（大写）指定解压的目录，注意-c,-t,-x不能同时出现在同一条命令中
-j ：通过bzip2的支持进行压缩/解压缩
-z ：通过gzip的支持进行压缩/解压缩
-v ：在压缩/解压缩过程中，将正在处理的文件名显示出来
-f filename ：filename为要处理的文件
-C dir ：指定压缩/解压缩的目录dir
```

------

**通常只要记住以下3条命令即可：**

```
压缩：tar -jcv -f filename.tar.bz2 要被处理的文件或目录名称
查询：tar -jtv -f filename.tar.bz2
解压：tar -jxv -f filename.tar.bz2 -C 欲解压缩的目录
```

**注意：** 文件名并不定要以后缀tar.bz2结尾，这里主要是为了说明使用的压缩程序为bzip2

##  7、chgrp命令

该命令用于改变文件所属用户组，它的使用非常简单，它的基本用法如下：

```
chgrp [-R] dirname/filename
-R ：进行递归的持续对所有文件和子目录更改
# 例如：
chgrp users -R ./dir # 递归地把dir目录下中的所有文件和子目录下所有文件的用户组修改为users
```

## 8、chown命令

该命令用于改变文件的所有者，与chgrp命令的使用方法相同，只是修改的文件属性不同，不再详述。

## 

------

## 

# 三、进程管理类：

## 1、ps命令

该命令用于将某个时间点的进程运行情况下并输出，process之意，它的常用参数如下：

```
-A ：所有的进程均显示出来
-a ：不与terminal有关的所有进程
-u ：有效用户的相关进程
-x ：一般与a参数一起使用，可列出较完整的信息
-l ：较长，较详细地将PID的信息列出
```

其实我们只要记住ps一般使用的命令参数搭配即可，它们并不多，如下：

```
ps aux # 查看系统所有的进程数据
ps ax # 查看不与terminal有关的所有进程
ps -lA # 查看系统所有的进程数据
ps axjf # 查看连同一部分进程树状态
```

## 2、kill命令

该命令用于向某个工作（%jobnumber）或者是某个PID（数字）传送一个信号，它通常与ps和jobs命令一起使用，它的基本语法如下：

```
kill -signal PID
```

**signal**的常用参数如下：

注：最前面的数字为信号的代号，使用时可以用代号代替相应的信号。

```
1：SIGHUP，启动被终止的进程
2：SIGINT，相当于输入ctrl+c，中断一个程序的进行
9：SIGKILL，强制中断一个进程的进行
15：SIGTERM，以正常的结束进程方式来终止进程
17：SIGSTOP，相当于输入ctrl+z，暂停一个进程的进行
```

**eg:**

```
# 以正常的结束进程方式来终于第一个后台工作，可用jobs命令查看后台中的第一个工作进程
kill -SIGTERM %1 
# 重新改动进程ID为PID的进程，PID可用ps命令通过管道命令加上grep命令进行筛选获得
kill -SIGHUP PID
```

## 3、killall命令

该命令用于向一个命令启动的进程发送一个信号，它的一般语法如下：

```
killall [-iIe] [command name]
```

**它的参数如下：**

```
-i ：交互式的意思，若需要删除时，会询问用户
-e ：表示后面接的command name要一致，但command name不能超过15个字符
-I ：命令名称忽略大小写
# 例如：
killall -SIGHUP syslogd # 重新启动syslogd
```

## 4、time命令

该命令用于测算一个命令（即程序）的执行时间。它的使用非常简单，就像平时输入命令一样，不过在命令的前面加入一个time即可，例如：

```
time ./process
time ps aux
```

**在程序或命令运行结束后，在最后输出了三个时间，它们分别是：**

user：用户CPU时间，命令执行完成花费的用户CPU时间，即命令在用户态中执行时间总和；

system：系统CPU时间，命令执行完成花费的系统CPU时间，即命令在核心态中执行时间总和；

real：实际时间，从command命令行开始执行到运行终止的消逝时间；

**

注：**用户CPU时间和系统CPU时间之和为CPU时间，即命令占用CPU执行的时间总和。实际时间要大于CPU时间，因为Linux是多任务操作系统，往往在执行一条命令时，系统还要处理其它任务。另一个需要注意的问题是即使每次执行相同命令，但所花费的时间也是不一样，其花费时间是与系统运行相关的。**

------



# 四、文件查看类：

## 1、vim命令

vim是一个非常好用的==文本编辑器==，两张图概括它`８０％`的命令（剩下的**20%自己探索**）：

![vim](/home/heng/Documents/My_Markdown/my思维导图/vim.png)

![vim 键盘图](/home/heng/Documents/My_Markdown/my思维导图/vim 键盘图.gif)



## 2、cat命令

该命令用于查看文本文件的内容，后接要查看的文件名，通常可用管道与more和less一起使用，从而可以一页页地查看数据。例如：

```
cat text | less # 查看text文件中的内容
# 注：这条命令也可以使用less text来代替
```

## 3、 echo 显示一行文本 (可使用通配符，正则表达式)

```
echo            +文本内容              #显示文本   
echo   -n       +文本内容              #显示不带尾部回车符的文本
echo   -e       +"文本内容"            #允许使用转义字符输出文本  例：echo -e "a\nb\nc" 
echo            +新文本内容 > 文件名    #重定向，清除源文件所有内容，并插入单行   例：echo "hello word" >jackonill.txt
echo            +新文本内容 >> 文件名   #追加重定向，在原有文件基础上末尾插入一行文本逐行
```

## 

------



# 五、编译命令：

## 1、gcc

gcc是linux系统集成的编译器。在linux环境下编辑程序，首先需要克服的便是没有集成开发环境的一键式操作所带来的麻烦。这其中涉及命令行操作、编译选项的设定、文件依赖关系的书写(makefile)等问题。这里主要介绍的是关于gcc的常用命令行参数及其相应的作用。(若编译C++文件，则只需将下列命令的 gcc 换为 g++，源文件的后缀应为 .C/.cpp/.c++/.cc等)

```
-o ：output之意，用于指定生成一个可执行文件的文件名
-c ：用于把源文件生成目标文件（.o)，并阻止编译器创建一个完整的程序
-I ：增加编译时搜索头文件的路径
-L ：增加编译时搜索静态连接库的路径
-S ：把源文件生成汇编代码文件
-lm：表示标准库的目录中名为libm.a的函数库
-lpthread ：连接NPTL实现的线程库
-std= ：用于指定把使用的C语言的版本

# 例如：
# 把源文件test.c按照c99标准编译成可执行程序test
gcc -o test test.c -lm -std=c99
#把源文件test.c转换为相应的汇编程序源文件test.s
gcc -S test.c
```

## 2、g++

------



# 六、VPN：

## 1、ifconfig   /   ip addr (Centos) 显示或设置网络设备

```
ifconfig             #处于激活状态的网络接口
ifconfig     -a      #所有配置的网络接口，不论其是否激活 
```

## 2、ping 检测主机 (127.0.0.1 为主机， 可检验网卡， 可用于检测内网)

```
ping    +ip/域名         #检测外网
```

------



# 七、日常工具

### 1、date 显示日期

```
date                          #打印时间
date     -s      +时间         #设置时间  例：date -s '14:35:40' 
date     +%m%d%H%M%S           #按照格式输出时间
```

### 2、 cal 显示日历

```
heng@heng-PC:~$ cal 2 2019
      二月 2019         
日 一 二 三 四 五 六  
                1  2  
 3  4  5  6  7  8  9  
10 11 12 13 14 15 16  
17 18 19 20 21 22 23  
24 25 26 27 28        
```

### 3、bc 计算器

```
heng@heng-PC:~$ bc
bc 1.07.1
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty'. 
10 % 3
1
9 / 3
3
9 * 3
27
9 - 3
6
9 + 3
12

```



------

# 八、系统及用户：

## 1、sleep 休眠

```
sleep n;命令      #n秒后，执行某命令,注意分号
```

## 2、shutdown/poweroff/halt 关机/重启命令

```
shutdown -h now或/poweroff或halt   #立刻关机
shutdown -h 时间                   #在特定时间关机
shutdown -H now                   #立刻停机
shutdown –r now或reboot           #重启
```

## 3、diff 比较两个文件的差异

```
diff    文件1 文件2                 #比较二个文件的不同 
diff    文件夹1/ 文件夹2/            #比较二个文件夹的不同
diff    -r  文件夹1/ 文件夹2/        #递归比较二个文件夹的不同
```

## 4、apt-get/yum/dnf 下载软件包命令

```
apt-get install  软件/包           #安装包
apt-get update   软件/包           #更新软件
apt-get remove   软件/包           #卸载软件
apt-get upgrade                   #更新已安装的包
apt-get clean                     #清理无用的包
```

## 5、service 服务

```
service 服务名 status      #查看某服务状态
service 服务名 start       #开启某服务
service 服务名 restart     #重启某服务
service 服务名 stop        #停止某服务
service 服务名 reload      #重新加载某服务配置文件 
```

## 6、ssh 远程连接某主机

```
ssh 用户@ip地址    #远程ssh连接某主机
```

## 7、useradd 添加用户

```
useradd     用户名          #添加某用户
用户名       passwd         #为某用户添加密码
useradd -r      用户名      #添加系统用户
useradd -d 路径 用户名       #添加用户，并且指定，home目录
```

## 8、history 查看用户历史操作

```
history         #查看所有执行过的命令
history  n      #显示n条历史记录
!n              #执行编号历史是n的命令，注意感叹号       例：!4             执行编号是4的命令
history -c      #清除历史记录

```

## 9、id/who 查看用户

```
id/who           #显示当前用户的信息
id   某用户       #显示某用户的信息
who -a           #显示目前登入系统的用户详细信息
who -b           #上次系统启动时间

```

## 10、df 报告文件系统磁盘空间的使用情况

```
df          #列出各文件系统的磁盘空间使用情况
df -a       #显示所有文件系统的磁盘使用情况
df -ia      #列出各文件系统ionde使用情况
df -h      （--human）#目前磁盘空间和使用情况 以更易读的方式显示
```

### 11、sync 数据同步写入磁盘

```
heng@heng-PC:~$ sync
```

## 12、安装和卸载apt：

**安装软件：**

```
示例：sudo apt-get install xx
实例：sudo apt-get install gcc
```

**卸载软件：**

```
示例：sudo apt-get --purge remove xx
实例：sudo apt-get --purge remove gcc
```

**查看软件：**

```
实例：dpkg --list 
```

------



# 九、几个重要的热键[Tab],[ctrl]-c,[ctrl]-d

```
[Tab]     按键---具有【命令补全】不【档案补齐】的功能
[Ctrl]-c  按键---让当前的程序【停掉】
[Ctrl]-d  按键---通常代表着：【键盘输入结束(End Of File, EOF 戒 End                   OfInput)】的意思；另外，他也可以用来取代exit

```

------



# 十、特殊装b特效命令 ：

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
 xeyes 命令         #一双眼      安装xeyes 
```
