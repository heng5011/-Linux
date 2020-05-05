# 使用vim编辑一个C++程序

程序实例：写一个整型的坐标点类point，然后在主程序中创建三个坐标点类的对象，并放入容器vector中，通过调用坐标点类point中的成员函数point::print()来输出每一个点的坐标。该程序一个包含三个文件：

- **main.cpp**
- **point.cpp**
- **point.h**

## （1）创建一个C++工程项目目录

- 新建一个名为`“Point”`的目录

```
mkdir Point
```

## （2）编辑三个C++文件

进入`./Point`目录并使用vim编辑三个C++文件

```
cd ./Point
vim point.h
vim point.cpp
vim main.cpp
```

三个C++文件的内容如下

- **point.h**

```c++
class point{
private:
        int x;
        int y;
public:
        point(int a,int b):x(a),y(b){}
        void print();
        ~point(){}
};
```

- **point.cpp**

```
#include <iostream>
#include "point.h"

void point::print() {
        std::cout<<"x="<<this->x<<",y="<<this->y<<"\n";
}
```

- **main.cpp**

    #include <iostream>
    #include <vector>
    #include "point.h"
    using namespace std;
    
    int main(){
    
            point p0(3,4);//创建三个point对象
            point p1(1,2);
            point p2(5,8);
    
            vector<point> v;//创建一个存储point对象的容器
    
            v.push_back(p0);
            v.push_back(p1);
            v.push_back(p2);
    
            for(int i=0;i<v.size();i++)//打印容器中的所有point对象
                    v[i].print();
    
            return 0;
    }


# 三、构建C++工程项目

## （1）编辑Makefile文件

- 在`./Point`目录下，使用vim编辑一个名为`Makefile`或者`makefile`的文件

```
cd ./Point
vim Makefile #vim makefile也是可以的，命令make会在当前目录下寻找Makefile或者makefile
```

- **Makefile内容如下**

```
all:
    g++ main.cpp point.cpp -o app -std=c++11
clean:
    rm app
```

- **解释Makefile里面的内容**

```
g++ main.cpp point.cpp # 使用g++编译器编译当前所有的cpp文件，main.cpp一定要放在第一个
-o app # 参数-o表示最终生成的可执行文件为app
-std=c++11 # 用于支持c++11的标准，-std=gnu++11用于支持c++11标准和gnu扩展特性
rm app # 删除app
```

## （2）使用命令make构建C++工程项目

- 进入./Point目录下

```
cd ./Point # 该Point目录下应该有如下图的四个文件
```

![这里写图片描述](https://img-blog.csdn.net/2018063009310221?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMyNTk5NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)



+ **在当前目录下执行命令make**

```
make # 执行make，就可以构建C++项目
./app # 执行生成的app文件，可以看到最后的结果
```

![这里写图片描述](https://img-blog.csdn.net/20180630093359135?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzMyNTk5NDc5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

