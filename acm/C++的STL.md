# C++ cin的详细用法

## 1.cin简介

cin是C++编程语言中的标准输入流对象，即istream类的对象。cin主要用于从标准输入读取数据，这里的标准输入，指的是终端的键盘。此外，cout是输出流对象，即ostream类的对象，cerr是标准错误输出流的对象，也是ostream 类的对象。这里的标准输出指的是终端键盘，标准错误输出指的是终端的屏幕。

在理解cin功能时，不得不提标准输入缓冲区。当我们从键盘输入字符串的时候需要敲一下回车键才能够将这个字符串送入到缓冲区中，那么敲入的这个回车键(\r)会被转换为一个换行符\n，这个换行符\n也会被存储在cin的缓冲区中并且被当成一个字符来计算！比如我们在键盘上敲下了123456这个字符串，然后敲一下回车键（\r）将这个字符串送入了缓冲区中，那么此时缓冲区中的字节个数是7 ，而不是6。



cin读取数据也是从缓冲区中获取数据，缓冲区为空时，cin的成员函数会阻塞等待数据的到来，一旦缓冲区中有数据，就触发cin的成员函数去读取数据。



## 2.cin的常用读取方法

使用cin从标准输入读取数据时，通常用到的方法有`cin>>`,`cin.get`,`cin.getline`。

### 2.1.cin>>的用法

- `cin>>`的用法

  cin可以连续从键盘读取想要的数据，以空格、tab或换行作为分隔符。实例程序如下。

  ```c++
  #include <iostream>
  using namespace std;
  
  int main()
  {
  	char a;
  	int b;
  	float c;
  	string 
  	cin>>a>>b>>c;
  	cout<<a<<" "<<b<<" "<<c<<" "<<endl;
  
  	system("pause");
  	return 0;
  }
  
  ```

  在屏幕中一次输入：a[回车]11[回车]5.56[回车]，程序将输出如下结果：

  ```c++
  a
  11
  5.56
  a 11 5.56
  
  ```

  （1）cin>>等价于cin.operator>>()，即调用成员函数operator>>()进行读取数据。
  （2）当cin>>从缓冲区中读取数据时，若缓冲区中第一个字符是空格、tab或换行这些分隔符时，cin>>会将其忽略并清除，继续读取下一个字符，若缓冲区为空，则继续等待。但是如果读取成功，字符后面的分隔符是残留在缓冲区的，cin>>不做处理。
  （3）不想略过空白字符，那就使用 noskipws 流控制。比如cin>>noskipws>>input;

  ​    验证程序如下：

  ```c++
  #include <string> 
  #include <iostream>
  using namespace std;
  
  int main()
  {
  	char a;
  	int b;
  	float c;
  	string str;
  	cin>>a>>b>>c>>str;
  	cout<<a<<" "<<b<<" "<<c<<" "<<str<<endl;
  
  	string test;
  	getline(cin,test);//不阻塞
  	cout<<"test:"<<test<<endl;
  	system("pause");
  	return 0;
  }
  
  ```

  从键盘输入:[回车][回车][回车]a[回车]5[回车]2.33[回车]hello[回车]，输出结果是：

  ![这里写图片描述](https://img-blog.csdn.net/20150904213554338)

​     从结果可以看出，cin>>对缓冲区中的第一个换行符视而不见，采取的措施是忽略清除，继续阻塞等待缓冲区有效数据的到来。但是，getline()读取数据时，并非像cin>>那样忽略第一个换行符，getline()发现cin的缓冲区中有一个残留的换行符，不阻塞请求键盘输入，直接读取，送入目标字符串后，再将换行符替换为空字符’\0’，因此程序中的test为空串。

### 2.2.cin.get的用法

该函数有有多种重载形式，分为四种格式：无参，一参数，二参数，三个参数。常用的的函数原型如下：

```c++
int cin.get();
istream& cin.get(char& var);
istream& get ( char* s, streamsize n );
istream& get ( char* s,  streamsize  n, char delim )。

```

其中streamsize 在VC++中被定义为long long型。另外，还有两个重载形式不怎么使用，就不详述了，函数原型如下：

```c++
istream& get ( streambuf& sb);
istream& get ( streambuf& sb, char delim );

```

#### 2.2.1 cin.get 读取一个字符

读取一个字符，可以使用cin.get或者cin.get(var)，示例代码如下：

```c++
#include <iostream>
using namespace std;

int main()
{
	char a;
	char b;
	a=cin.get();
	cin.get(b);
	cout<<a<<b<<endl;
	system("pause");
	return 0;
}

```

输入：e[回车]，输出：

![这里写图片描述](https://img-blog.csdn.net/20150904213700306)

（1）从结果可以看出，cin.get()从输入缓冲区读取单个字符时不忽略分隔符，直接将其读取，就出现了如上情况，将换行符读入变量b，输出时换行两次，一次是变量b，一次是endl。

（2）cin.get()的返回值是int类型，成功则返回读取字符的ASCII码值，遇到文件结束符时，返回EOF，即-1。Windows下命令行输入文件结束符的方式为Ctrl+z，Linux为Ctrl+d。

（3）cin.get(char var)如果成功返回的是cin对象，因此可以支持链式操作，如`cin.get(b).get(c)`。

#### 2.2.2cin.get 读取一行

读取一行可以使用istream& get ( char* s, streamsize n )或者istream& get ( char* s, size_t n, streamsize delim )。二者的区别是前者默认以换行符结束，后者可指定结束符。n表示目标空间的大小。示例代码如下：

```c++
#include <iostream>
using namespace std;

int main()
{
	char a;
	char array[20]={NULL}; 
	cin.get(array,20);
	cin.get(a);
	cout<<array<<" "<<(int)a<<endl;
	system("pause");
	return 0;
}

```

输入：123456789[回车]，输出：

```c++
123456789
123456789 10

```

（1）从结果可以看出，cin.get(array,20);读取一行时，遇到换行符时结束读取，但是不对换行符进行处理，换行符仍然残留在输入缓冲区。第二次由cin.get()将换行符读入变量b，打印输入换行符的ASCII码值为10。这也是cin.get()读取一行与使用getline读取一行的区别所在。getline读取一行字符时，默认遇到’\n’时终止，并且将’\n’直接从输入缓冲区中删除掉，不会影响下面的输入处理。

（2）cin.get(str,size);读取一行时，只能将字符串读入C风格的字符串中，即char*，但是C++的getline函数可以将字符串读入C++风格的字符串中，即string类型。鉴于getline较cin.get()的这两种优点，建议使用getline进行行的读取。

### 2.3 cin.getline 读取一行

函数作用：从标准输入设备键盘读取一串字符串，并以指定的结束符结束。 函数原型有两个：

```c++
istream& getline(char* s, streamsize count); //默认以换行符结束
istream& getline(char* s, streamsize count, char delim);

```

使用示例：

```c++
#include <iostream>
using namespace std;
int main()
{
	char array[20]={NULL};
	cin.getline(array,20); //或者指定结束符，使用下面一行
	//cin.getline(array,20,'\n');
	cout<<array<<endl;
	system("pause");
	return 0;
}

```

注意，`cin.getline`与`cin.get`的区别是，`cin.getline`不会将结束符或者换行符残留在输入缓冲区中。

## 3. cin的条件状态

使用cin读取键盘输入时，难免发生错误，一旦出错，cin将设置条件状态(condition state)。条件状态标识符号为：

```c++
goodbit:无错误
eofbit:已到达文件尾
failbit:非致命的输入/输出错误，可挽回
badbit:致命的输入/输出错误,无法挽回

```

与这些条件状态对应的就是设置、读取和判断条件状态的流对象的成员函数。他们主要有：

```c++
s.eof()：若流s的eofbit置位，则返回true；
s.fail()：若流s的failbit置位，则返回true；
s.bad()：若流s的badbit置位，则返回true；
s.good()：若流s的goodbit置位，则返回true；
s.clear(flags)：清空状态标志位，并将给定的标志位flags置为1，返回void。
s.setstate(flags)：根据给定的flags条件状态标志位，将流s中对应的条件状态位置为1，返回void。
s.rdstate()：返回流s的当前条件状态，返回值类型为strm::iostate。strm::iostate是与机器相关的整型类型，由ios_base类定义，用于定义条件状态。

```

了解以上关于输入流的条件状态与相关操作函数，下面看一个因输入缓冲区未读取完造成的条件状态位failbit被置位，再通过clear()复位的例子。

```
#include <iostream>
using namespace std;

int main()
{
	char ch, str[20]; 
	cin.getline(str, 5);
	cout<<"flag1:"<<cin.good()<<endl;    // 查看goodbit状态，即是否有异常
	cin.clear();                         // 清除错误标志
	cout<<"flag1:"<<cin.good()<<endl;    // 清除标志后再查看异常状态
	cin>>ch; 
	cout<<"str:"<<str<<endl;
	cout<<"ch:"<<ch<<endl;

	system("pause");
	return 0;
}

```

输入：12345[回车]，输出结果为：

```c++
12345
flag1:0
flag1:1
str:1234
ch:5

```

可以看出，因输入缓冲区未读取完造成输入异常，通过clear()可以清除输入流对象cin的异常状态。，不影响后面的cin>>ch从输入缓冲区读取数据。因为cin.getline读取之后，输入缓冲区中残留的字符串是：5[换行]，所以cin>>ch将5读取并存入ch，打印输入并输出5。

如果将clear()注释，cin>>ch;将读取失败，ch为空。cin.clear()等同于cin.clear(ios::goodbit);因为cin.clear()的默认参数是ios::goodbit，所以不需显示传递，故而你最常看到的就是:cin.clear()。

## 4. cin清空输入缓冲区

从上文中可以看出，上一次的输入操作很有可能是输入缓冲区中残留数据，影响下一次的输入。那么如何解决这个问题呢？自然而然，我们想到了在进行输入时，对输入缓冲区进行清空和状态条件的复位。条件状态的复位使用clear()，清空输入缓冲区应该使用：
函数原型：`istream &ignore( streamsize num=1, int delim=EOF );`
函数作用：跳过输入流中n个字符，或在遇到指定的终止字符时提前结束（此时跳过包括终止字符在内的若干字符）。

使用示例如下：

```c++
#include <iostream>
using namespace std;

int main()
{
	char str1[20]={NULL},str2[20]={NULL};
    cin.getline(str1,5);
    cin.clear();  // 清除错误标志   
	cin.ignore(numeric_limits<std::streamsize>::max(),'\n'); //清除缓冲区的当前行
	cin.getline(str2,20);
	cout<<"str1:"<<str1<<endl;
	cout<<"str2:"<<str2<<endl;
	system("pause");
	return 0;
}

```

程序输入：12345[回车]success[回车]，程序输出：

```c++
12345
success
str1:1234
str2:success
```

（1）程序中使用`cin.ignore`清空了输入缓冲区的当前行，使上次的输入残留下的数据没有影响到下一次的输入，这就是`ignore()`函数的主要作用。其中，`numeric_limits<std::streamsize>::max()`不过是`<limits>`头文件定义的流使用的最大值，你也可以用一个足够大的整数代替它。如果想清空输入缓冲区，去掉换行符，使用：
`cin.ignore(numeric_limits< std::streamsize>::max());`清除cin里所有内容。

（2）`cin.ignore()；`当输入缓冲区没有数据时，也会阻塞等待数据的到来。

（3）有个疑问，网上很多资料说调用cin.sync()即可清空输入缓冲区，本人测试了一下，VC++可以，但是在Linux下使用GNU C++却不行，无奈之下，Linux下就选择了`cin.ignore()`。

## 5.从标准输入读取一行字符串的其它方法

### 5.1 getline 读取一行

C++中定义了一个在std名字空间的全局函数getline，因为这个getline函数的参数使用了string字符串，所以声明在了`<string>`头文件中了。

getline利用cin可以从标准输入设备键盘读取一行，当遇到如下三种情况会结束读操作：
（1）文件结束；
（2）遇到行分隔符；
（3）输入达到最大限度。

函数原型有两个重载形式：

```c++
istream& getline ( istream& is, string& str);						//默认以换行符\n分隔行
istream& getline ( istream& is, string& str, char delim);

```

使用示例：

```c++
#include <string> 
#include <iostream>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	cout<<str<<endl;
	system("pause");
	return 0;
}

```

输入： hello world[回车]， 输出：

```c++
hello world
hello world

```

注意，getline()遇到结束符时，会将结束符一并读入指定的string中，再将结束符替换为空字符。因此，进行从键盘读取一行字符时，建议使用getline，较为安全。但是，最好还是要进行标准输入的安全检查，提高程序容错能力。

cin.getline()与getline()类似，但是因为cin.getline()的输出是char*，getline()的输出是string，所以cin.getline()属于istream流，而getline()属于string流，二者是不一样的函数。

### 5.2 gets读取一行

`gets`是`C`中的库函数，在`<stdio.h>`申明，从标准输入设备读字符串，可以无限读取，不会判断上限，以回车结束或者`EOF`时停止读取，所以程序员应该确保`buffer`的空间足够大，以便在执行读操作时不发生溢出。
函数原型：`char *gets( char *buffer );`
使用示例：

```c++
#include <iostream>
using namespace std;
int main()
{
	char array[20]={NULL};
	gets(array);
	cout<<array<<endl;
	system("pause");
	return 0;
}

```

输入：I am lvlv[回车]，输出：

```c++
I am lvlv
I am lvlv

```

由于该函数是C的库函数，所以不建议使用，既然是C++程序，就尽量使用C++的库函数吧。

[链接](<https://blog.csdn.net/k346k346/article/details/48213811>)

<https://blog.csdn.net/k346k346/article/details/48213811>

---

# 对C++的atoi(), substr(), c_str() 函数的理解

` year = atoi(dateStr.substr(0, 4).c_str());` 

```c++
 year = atoi(dateStr.substr(0, 4).c_str());
```

里面包含三个函数,分别是`atoi(), substr(), c_str().`

**百度**：

- `atoi()`函数原型为: `int atoi(char *str)`,用途是将字符串转换成一个整数值, `str`是待转化成整数值的字符串.成功则返回转化后的整数值,失败返回0.

  

- `substr()` 函数原型为：`basic string::substr(string,start,length)`, 也可以把`string`移到外面，为`string &a,a.substr(start,length)`,其中`a`是待截取的字符串,`start`表示从截取开始的前一位,`length`表示截取长度,例如`string &a="hello world"`,则`a.substr(6,5)=world.`

- `c_str()`函数原型为:`const char *c_str()`,如果要将`string`对象，转化为`char*`对象，`c_str()`提供了这样一种方法，它返回一个客户程序可读不可改的指向字符数组的指针。 

  ------

  `year=atoi(dateStr.substr(0,4).c_str())` 的作用就是：

  截取`string`型的对象`dateStr`，并转化为`char *`对象， 然后将此字符串转换成一个整数值， 赋值给`year(year 是 int 型)`.

  