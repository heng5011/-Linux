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
