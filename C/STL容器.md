# STL容器

## STL容器简介

## 分类

![img](https://oi-wiki.org/lang/csl/images/container1.png)

## 序列式容器

- **向量（`vector`）**后端可高效增加元素的顺序表。
- **数组（array）C++11,**定长的顺序表，C风格数组的简单包装。
- **双端队列（deque）**双端都可高效增加元素的顺序表。
- **列表（list）**可以沿双向遍历的链表。
- **单向列表（forward_list）**只能沿一个方向遍历的链表。

## 关联式容器

- **集合（set）**用以有序地存储**互异**元素的容器。其实现是由节点组成的红黑树，每个节点都包含着一个元素，节点之间以某种比较元素大小的谓词进行排列。
- **多重集合（multiset）**用以有序地存储元素的容器。允许存在相等的元素。
- **映射（map）**由{键，值}对组成的集合，以某种比较大小关系的谓词进行排列。
- **多重映射（multimap）**由{键，值}对组成的多重集合，亦允许键有相等情况的映射。

## 无序（关联式）容器

- **无序（多重）集合（`unordered_set / unorder_multiset / `）**与 `set / multiset`的区别在于元素无序，只关心"元素是否存在"，使用哈希实现。
- **无序（多重）映射（`unorder_map / unorder_multimap`）**与 `map / multimap`的区别在于键(key)无序，只关心“键与值的对应关系”，使用哈希实现。

## 容器适配器

容器适配器其实并不是容器。它们不具有容器的某些特点（如：有迭代器、有 `clear()` 函数……）。

> ”适配器是使一种事物的行为类似于另外一种事物行为的一种机制”，适配器对容器进行包装，使其表现出另外一种行为。

- **栈** `(stack` ) 后进先出 (LIFO) 的容器。
- **队列** ( `queue` ) 先进先出 (FIFO) 的容器。
- **优先队列** ( `priority_queue` ) 元素的次序是由作用于所存储的值对上的某种谓词决定的的一种队列。

## 共同点[¶](https://oi-wiki.org/lang/csl/container/#_6)

### 容器声明[¶](https://oi-wiki.org/lang/csl/container/#_7)

都是 `containerName<typeName,...> name` 的形式，但模板参数（ `<>` 内的参数）的个数、形式会根据具体容器而变。

本质原因：STL 就是“标准模板库”，所以容器都是模板类。

### 迭代器[¶](https://oi-wiki.org/lang/csl/container/#_8)

STL 容器中的元素都可以用迭代器指向。

迭代器是一种类似指针的东西，可以通过 `containerName<typeName,...>::iterator` 来声明，通过 `*it` 来访问所指向的元素，通过 `++` / `--` 来访问下一个/上一个元素（向前迭代器不能 `--` ）。

迭代器分为输入/输出/向前/双向/随机访问迭代器、正向/反向迭代器。

### 共有函数[¶](https://oi-wiki.org/lang/csl/container/#_9)

`=` ：有赋值运算符以及复制构造函数。

`begin()` ：返回指向开头元素的迭代器。

`end()` ：返回指向末尾的下一个元素的迭代器。 `end()` 不指向某个元素，但它是末尾元素的后继。

`size()` ：返回容器内的元素个数。

`max_size()` ：返回容器 **理论上** 能存储的最大元素个数。依容器类型和所存储变量的类型而变。

`empty()` ：返回容器是否为空。

`swap()` ：交换两个容器。

`clear()` ：清空容器。

`==` / `!=` / `<` / `>` / `<=` / `>=` ：按 **字典序** 比较两个容器的大小。（比较元素大小时 `map` 的每个元素相当于 `set<pair<key, value> >` ，无序容器不支持 `<` / `>` / `<=` / `>=` 。）

## 迭代器

在 STL 中，迭代器（Iterator）是用来访问和检查 STL 容器中元素的对象，它的行为模式和指针类似，甚至有不少容器的迭代器类型就是指针。但是它封装了一些有效性检查，并且提供了统一的访问格式。迭代器尽管在使用上与常规的下标访问效果相似，但是由于部分 STL 容器（如 `std::list` ）的下标访问有很大的开销，这时在顺序访问的情况下迭代器会比下标访问更加高效。类似的概念在其他很多高级语言中都存在，如 Python 的 `__iter__` 函数，C# 的 `IEnumerator` 。

## 使用方法[¶](https://oi-wiki.org/lang/csl/iterator/#_1)

迭代器听起来比较晦涩，其实迭代器本身可以看作一个数据指针。迭代器主要支持两个运算符：自增和解引用（单目 `*` 运算符），其中自增用来移动迭代器，解引用可以获取或修改它指向的元素。 最常用的使用方法是用迭代器替换普通的 `for` 循环，例如下列代码中两个循环的效果是一致的。（假设已经引用了 `std` 空间中的相关类型）

```
vector<int> data(10);

for (int i = 0; i < data.size(); i++)
  cout << data[i] << endl;  // 使用下标访问元素

for (vector<int>::iterator iter = data.begin(); iter != data.end(); iter++)
  cout << *iter << endl;  // 使用迭代器访问元素
// 在C++11后可以使用 auto iter = data.begin() 来简化上述代码
```



## 分类[¶](https://oi-wiki.org/lang/csl/iterator/#_2)

在 STL 的定义中，迭代器根据其支持的操作依次分为以下几类：

- InputIterator：只要求支持拷贝、自增和解引访问
- OutputIterator：只要求支持拷贝、自增和解引赋值
- ForwardIterator：即同时满足 InputIterator 和 OutputIterator 的要求
- BidirectionalIterator：在 ForwardIterator 的基础上支持自减（即反向访问）
- RandomAccessIterator：在 BidirectionalIterator 的基础上支持加减运算和比较运算（即随机访问）

不同的 STL 容器支持的迭代器类型不同，在使用时需要留意。

## 获取途径[¶](https://oi-wiki.org/lang/csl/iterator/#_3)

STL 容器一般支持从一端或两端开始的访问，以及对 [const 修饰符](https://oi-wiki.org/lang/const/) 的支持。例如容器的 `begin()`函数可以获得指向容器头部的迭代器，而 `rbegin()` 函数可以获得指向容器尾部的元素的反向迭代器。

# 序列式容器

## `vector`[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector)

`std::vector` 是 STL 提供的 **内存连续的** 、 **可变长度** 的数组（亦称列表）数据结构。能够提供线性复杂度的插入和删除，以及常数复杂度的随机访问。

### 为什么要使用 `vector`[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector_1)

作为 OIer，对程序效率的追求远比对工程级别的稳定性要高得多，而 `vector` 由于其对内存的动态处理，时间效率在部分情况下低于静态数组，并且在 OJ 服务器不一定开全优化的情况下更加糟糕。所以在正常存储数据的时候，通常不选择 `vector` 。下面给出几个 `vector` 优秀的特性，在需要用到这些特性的情况下， `vector` 能给我们带来很大的帮助。

#### `vector` 可以动态分配内存[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector_2)

很多时候我们不能提前开好那么大的空间（eg：预处理 1~n 中所有数的约数）。尽管我们能知道数据总量在空间允许的级别，但是单份数据还可能非常大，这种时候我们就需要 `vector` 来把内存占用量控制在合适的范围内。 `vector` 还支持动态扩容，在内存非常紧张的时候这个特性就能派上用场了。

#### `vector` 重写了比较运算符及赋值运算符[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector_3)

`vector` 重载了六个比较运算符，以字典序实现，这使得我们可以方便的判断两个容器是否相等（复杂度与容器大小成线性关系）。例如可以利用 `vector<char>` 实现字符串比较（当然，还是用 `std::string` 会更快更方便）。另外 `vector` 也重载了赋值运算符，使得数组拷贝更加方便。

#### `vector` 便利的初始化[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector_4)

由于 `vector` 重载了 `=` 运算符，所以我们可以方便的初始化。此外从 C++11 起 `vector` 还支持 [列表初始化](https://zh.cppreference.com/w/cpp/language/list_initialization) ，例如 `vector<int> data {1, 2, 3};` 。

### `vector` 的使用方法[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector_5)

以下介绍常用用法，详细内容 [请参见 C++ 文档](https://zh.cppreference.com/w/cpp/container/vector) 。

#### 构造函数[¶](https://oi-wiki.org/lang/csl/sequence-container/#_1)

用例参见如下代码（假设你已经 `using` 了 `std` 命名空间相关类型）：

```
// 1. 创建空vector; 常数复杂度
vector<int> v0;
// 1+. 这句代码可以使得向vector中插入前3个元素时，保证常数时间复杂度
v0.reserve(3);
// 2. 创建一个初始空间为3的vector，其元素的默认值是0; 线性复杂度
vector<int> v1(3);
// 3. 创建一个初始空间为3的vector，其元素的默认值是2; 线性复杂度
vector<int> v2(3, 2);
// 4. 创建一个初始空间为3的vector，其元素的默认值是1，
// 并且使用v2的空间配置器; 线性复杂度
vector<int> v3(3, 1, v2.get_allocator());
// 5. 创建一个v2的拷贝vector v4， 其内容元素和v2一样; 线性复杂度
vector<int> v4(v2);
// 6. 创建一个v4的拷贝vector v5，其内容是{v4[1], v4[2]}; 线性复杂度
vector<int> v5(v4.begin() + 1, v4.begin() + 3);
// 7. 移动v2到新创建的vector v6，不发生拷贝; 常数复杂度; 需要 C++11
vector<int> v6(std::move(v2));  // 或者 v6 = std::move(v2);
```



测试代码

```
// 以下是测试代码，有兴趣的同学可以自己编译运行一下本代码。
cout << "v1 = ";
copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v2 = ";
copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v3 = ";
copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v4 = ";
copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v5 = ";
copy(v5.begin(), v5.end(), ostream_iterator<int>(cout, " "));
cout << endl;
cout << "v6 = ";
copy(v6.begin(), v6.end(), ostream_iterator<int>(cout, " "));
cout << endl;
```

可以利用上述的方法构造一个 `vector` ，足够我们使用了。

#### 元素访问[¶](https://oi-wiki.org/lang/csl/sequence-container/#_2)

`vector` 提供了如下几种方法进行元素访问

1. `at()`

   `v.at(pos)` 返回容器中下标为 `pos` 的引用。如果数组越界抛出 `std::out_of_range` 类型的异常。

2. `operator[]`

   `v[pos]` 返回容器中下标为 `pos` 的引用。不执行越界检查。

3. `front()`

   `v.front()` 返回首元素的引用。

4. `back()`

   `v.back()` 返回末尾元素的引用。

5. `data()`

   `v.data()` 返回指向数组第一个元素的指针。

#### 迭代器[¶](https://oi-wiki.org/lang/csl/sequence-container/#_3)

vector 提供了如下几种 [迭代器](https://oi-wiki.org/lang/csl/iterator/)

1. `begin()/cbegin()`

   返回指向首元素的迭代器，其中 `*begin = front` 。

2. `end()/cend()`

   返回指向数组尾端占位符的迭代器，注意是没有元素的。

3. `rbegin()/rcbegin()`

   返回指向逆向数组的首元素的逆向迭代器，可以理解为正向容器的末元素。

4. `rend()/rcend()`

   返回指向逆向数组末元素后一位置的迭代器，对应容器首的前一个位置，没有元素。

以上列出的迭代器中，含有字符 `c` 的为只读迭代器，你不能通过只读迭代器去修改 `vector` 中的元素的值。如果一个 `vector` 本身就是只读的，那么它的一般迭代器和只读迭代器完全等价。只读迭代器自 C++11 开始支持。

#### 长度和容量[¶](https://oi-wiki.org/lang/csl/sequence-container/#_4)

`vector` 有以下几个与容器长度和容量相关的函数。注意， `vector` 的长度（size）指有效元素数量，而容量（capacity）指其实际分配的内存长度，相关细节请参见后文的实现细节介绍。

**与长度相关** ：

- `empty()` 返回一个 `bool` 值，即 `v.begin() == v.end()` ， `true` 为空， `false` 为非空。

- `size()` 返回容器长度（元素数量），即 `std::distance(v.begin(), v.end())` 。

- `resize()` 改变 `vector` 的长度，多退少补。补充元素可以由参数指定。

- `max_size()` 返回容器的最大可能长度。

  **与容量相关** ：

- `reserve()` 使得 `vector` 预留一定的内存空间，避免不必要的内存拷贝。

- `capacity()` 返回容器的容量，即不发生拷贝的情况下容器的长度上限。

- `shrink_to_fit()` 使得 `vector` 的容量与长度一致，多退但不会少。

### 元素增删及修改[¶](https://oi-wiki.org/lang/csl/sequence-container/#_5)

- `clear()` 清除所有元素
- `insert()` 支持在某个迭代器位置插入元素、可以插入多个。 **复杂度与 pos 距离末尾长度成线性而非常数的**
- `erase()` 删除某个迭代器或者区间的元素，返回最后被删除的迭代器。复杂度与 `insert` 一致。
- `push_back()` 在末尾插入一个元素，均摊复杂度为 **常数** ，最坏为线性复杂度。
- `pop_back()` 删除末尾元素，常数复杂度。
- `swap()` 与另一个容器进行交换，此操作是 **常数复杂度** 而非线性的。

### `vector` 的实现细节[¶](https://oi-wiki.org/lang/csl/sequence-container/#vector_6)

`vector` 的底层其实仍然是定长数组，它能够实现动态扩容的原因是增加了避免数量溢出的操作。首先需要指明的是 `vector` 中元素的数量（长度）  与它已分配内存最多能包含元素的数量（容量）  是不一致的， `vector` 会分开存储这两个量。当向 `vector` 中添加元素时，如发现  ，那么容器会分配一个尺寸为  的数组，然后将旧数据从原本的位置拷贝到新的数组中，再将原来的内存释放。尽管这个操作的渐进复杂度是  ，但是可以证明其均摊复杂度为  。而在末尾删除元素和访问元素则都仍然是  的开销。 因此，只要对 `vector` 的尺寸估计得当并善用 `resize()` 和 `reserve()` ，就能使得 `vector` 的效率与定长数组不会有太大差距。

### `vector<bool>`[¶](https://oi-wiki.org/lang/csl/sequence-container/#vectorbool)

标准库特别提供了对 `bool` 的 `vector` 特化，每个“ `bool` ”只占 1 bit，且支持动态增长。但是其 `operator[]` 的返回值的类型不是 `bool&` 而是 `vector<bool>::reference` 。因此，使用 `vector<bool>` 使需谨慎，可以考虑使用 `deque<bool>` 或 `vector<char>` 替代。而如果你需要节省空间，请直接使用 [`bitset` ](https://oi-wiki.org/lang/csl/bitset/)。

## `array` (C++11)[¶](https://oi-wiki.org/lang/csl/sequence-container/#array-c11)

`std::array` 是 STL 提供的 **内存连续的** 、 **固定长度** 的数组数据结构。其本质是对原生数组的直接封装。

### 为什么要用 `array`[¶](https://oi-wiki.org/lang/csl/sequence-container/#array)

`array` 实际上是 STL 对数组的封装。它相比 `vector` 牺牲了动态扩容的特性，但是换来了与原生数组几乎一致的性能（在开满优化的前提下）。因此如果能使用 C++11 特性的情况下，能够使用原生数组的地方几乎都可以直接把定长数组都换成 `array` ，而动态分配的数组可以替换为 `vector`。

### `array` 的使用方法[¶](https://oi-wiki.org/lang/csl/sequence-container/#array_1)

`array` 的使用方法与 `vector` 高度相似，仅有声明方式与 `vector` 不同，以及没有元素增删的能力（如 `push_back` ）。这里只给出一段例子，详细内容 [请参见 C++ 文档](https://zh.cppreference.com/w/cpp/container/array) 。

```
// 1. 创建空array，长度为3; 常数复杂度
std::array<int, 3> v0;
// 2. 用指定常数创建array; 常数复杂度
std::array<int, 3> v1{1, 2, 3};

v0.fill(1);  // 填充数组

// 访问数组
for (int i = 0; i != arr.size(); ++i) cout << arr[i] << " ";
```

## `deque`[¶](https://oi-wiki.org/lang/csl/sequence-container/#deque)

`std::deque` 是 STL 提供的 [双端队列](https://oi-wiki.org/ds/queue/) 数据结构。能够提供线性复杂度的插入和删除，以及常数复杂度的随机访问。

### `deque` 的使用方法[¶](https://oi-wiki.org/lang/csl/sequence-container/#deque_1)

以下介绍常用用法，详细内容 [请参见 C++ 文档](https://zh.cppreference.com/w/cpp/container/deque) 。 `deque` 的迭代器函数与 `vector` 相同，因此不作详细介绍。

#### 构造函数[¶](https://oi-wiki.org/lang/csl/sequence-container/#_6)

参见如下代码（假设你已经 `using` 了 `std` 命名空间相关类型）：

```
// 1. 定义一个int类型的空双端队列 v0
deque<int> v0;
// 2. 定义一个int类型的双端队列 v1，并设置初始大小为10; 线性复杂度
deque<int> v1(10);
// 3. 定义一个int类型的双端队列 v2，并初始化为10个1; 线性复杂度
deque<int> v2(10, 1);
// 4. 复制已有的双端队列 v1; 线性复杂度
deque<int> v3(v1);
// 5. 创建一个v2的拷贝deque v4，其内容是v4[0]至v4[2]; 线性复杂度
deque<int> v4(v2.begin(), v2.begin() + 3);
// 6. 移动v2到新创建的deque v5，不发生拷贝; 常数复杂度; 需要 C++11
deque<int> v5(std::move(v2));
```

#### 元素访问[¶](https://oi-wiki.org/lang/csl/sequence-container/#_7)

与 `vector` 一致，但无法访问底层内存。其高效的元素访问速度可参考实现细节部分。

- `at()` 返回容器中指定位置元素的引用，执行越界检查， **常数复杂度** 。
- `operator[]` 返回容器中指定位置元素的引用。不执行越界检查， **常数复杂度** 。
- `front()` 返回首元素的引用。
- `back()` 返回末尾元素的引用。

#### 迭代器[¶](https://oi-wiki.org/lang/csl/sequence-container/#_8)

与 `vector` 一致。

#### 长度[¶](https://oi-wiki.org/lang/csl/sequence-container/#_9)

与 `vector` 一致，但是没有 `reserve()` 和 `capacity()` 函数。（仍然有 `shrink_to_fit()` 函数）

#### 元素增删及修改[¶](https://oi-wiki.org/lang/csl/sequence-container/#_10)

与 `vector` 一致，并额外有向队列头部增加元素的函数。

- `clear()` 清除所有元素
- `insert()` 支持在某个迭代器位置插入元素、可以插入多个。 **复杂度与 pos 与两端距离较小者成线性** 。
- `erase()` 删除某个迭代器或者区间的元素，返回最后被删除的迭代器。复杂度与 `insert` 一致。
- `push_front()` 在头部插入一个元素， **常数复杂度** 。
- `pop_front()` 删除头部元素， **常数复杂度** 。
- `push_back()` 在末尾插入一个元素， **常数复杂度** 。
- `pop_back()` 删除末尾元素， **常数复杂度** 。
- `swap()` 与另一个容器进行交换，此操作是 **常数复杂度** 而非线性的。

### `deque` 的实现细节[¶](https://oi-wiki.org/lang/csl/sequence-container/#deque_2)

`deque` 通常的底层实现是多个不连续的缓冲区，而缓冲区中的内存是连续的。而每个缓冲区还会记录首指针和尾指针，用来标记有效数据的区间。当一个缓冲区填满之后便会在之前或者之后分配新的缓冲区来存储更多的数据。更详细的说明可以参考 [STL 源码剖析——deque 的实现原理和使用方法详解](https://blog.csdn.net/baidu_28312631/article/details/48000123) 。

## `list`[¶](https://oi-wiki.org/lang/csl/sequence-container/#list)

`std::list` 是 STL 提供的 [双向链表](https://oi-wiki.org/ds/linked-list/) 数据结构。能够提供线性复杂度的随机访问，以及常数复杂度的插入和删除。

### `list` 的使用方法[¶](https://oi-wiki.org/lang/csl/sequence-container/#list_1)

`list` 的使用方法与 `deque` 基本相同，但是增删操作和访问的复杂度不同。详细内容 [请参见 C++ 文档](https://zh.cppreference.com/w/cpp/container/list) 。 `list` 的迭代器、长度、元素增删及修改相关的函数与 `deque` 相同，因此不作详细介绍。

#### 元素访问[¶](https://oi-wiki.org/lang/csl/sequence-container/#_11)

由于 `list` 的实现是链表，因此它不提供随机访问的接口。若需要访问中间元素，则需要使用迭代器。

- `front()` 返回首元素的引用。
- `back()` 返回末尾元素的引用。

#### 操作[¶](https://oi-wiki.org/lang/csl/sequence-container/#_12)

`list` 类型还提供了一些针对其特性实现的 STL 算法函数。由于这些算法需要 [随机访问迭代器](https://oi-wiki.org/lang/csl/iterator/) ，因此 `list` 提供了特别的实现以便于使用。这些算法有 `splice()` 、 `remove()` 、 `sort()` 、 `unique()` 、 `merge()` 等。

## `forward_list` （C++11）[¶](https://oi-wiki.org/lang/csl/sequence-container/#forward_list-c11)

`std::forward_list` 是 STL 提供的 [单向链表](https://oi-wiki.org/ds/linked-list/) 数据结构，相比于 `std::list` 减小了空间开销。

### `forward_list` 的使用方法[¶](https://oi-wiki.org/lang/csl/sequence-container/#forward_list)

`forward_list` 的使用方法与 `list` 几乎一致，但是迭代器只有单向的，因此其具体用法不作详细介绍。详细内容 [请参见 C++ 文档](https://zh.cppreference.com/w/cpp/container/forward_list)

# 关联式容器

## `set`[¶](https://oi-wiki.org/lang/csl/associative-container/#set)

`set` 是关联容器，含有键值类型对象的已排序集，搜索、移除和插入拥有对数复杂度。 `set` 内部通常采用红黑树实现。

和数学中的集合相似， `set` 中不会出现值相同的元素。

### 插入与删除操作[¶](https://oi-wiki.org/lang/csl/associative-container/#_1)

- `insert(x)` 当容器中没有等价元素的时候，将元素 x 插入到 `set` 中。
- `erase(x)` 删除值为 x 的元素，返回删除元素的个数。
- `erase(pos)` 删除迭代器为 pos 的元素，要求迭代器必须合法。
- `erase(first,last)` 删除迭代器在 [first, last)  范围内的所有元素。
- `clear()` 清空 `set` 。

### 迭代器[¶](https://oi-wiki.org/lang/csl/associative-container/#_2)

`set` 提供了以下几种迭代器：

1. `begin()/cbegin()` 
   返回指向首元素的迭代器，其中 `*begin = front` 。
2. `end()/cend()` 
   返回指向数组尾端占位符的迭代器，注意是没有元素的。
3. `rbegin()/rcbegin()` 
   返回指向逆向数组的首元素的逆向迭代器，可以理解为正向容器的末元素。
4. `rend()/rcend()` 
   返回指向逆向数组末元素后一位置的迭代器，对应容器首的前一个位置，没有元素。

以上列出的迭代器中，含有字符 `c` 的为只读迭代器，你不能通过只读迭代器去修改 `set` 中的元素的值。如果一个 `set` 本身就是只读的，那么它的一般迭代器和只读迭代器完全等价。只读迭代器自 C++11 开始支持。

### 查找操作[¶](https://oi-wiki.org/lang/csl/associative-container/#_3)

- `count(x)` 返回 `set` 内键为 x 的元素数量。
- `find(x)` 在 `set` 内存在键为 x 的元素时会返回该元素的迭代器，否则返回 `end()` 。
- `lower_bound(x)` 返回指向首个不小于给定键的元素的迭代器。
- `upper_bound(x)` 返回指向首个大于给定键的元素的迭代器。
- `empty()` 返回容器是否为空。
- `size()` 返回容器内元素个数。

## `multiset`[¶](https://oi-wiki.org/lang/csl/associative-container/#multiset)

`multiset` 是关联容器，含有键值类型对象的已排序集，搜索、移除和插入拥有对数复杂度。

与 `set` 不同的是， `multiset` 允许不同元素间拥有相同的值。

### 插入与删除操作[¶](https://oi-wiki.org/lang/csl/associative-container/#_4)

- `insert(x)` 将元素 x 插入到 `multiset` 中。
- `erase(x)` 删除值为 x 的 **所有** 元素，返回删除元素的个数。
- `erase(pos)` 删除迭代器为 pos 的元素，要求迭代器必须合法。
- `erase(first,last)` 删除迭代器在 [first, last)  范围内的所有元素。
- `clear()` 清空 `multiset` 。

### 迭代器[¶](https://oi-wiki.org/lang/csl/associative-container/#_5)

`multiset` 的迭代器和 `set` 的 [迭代器](https://oi-wiki.org/lang/csl/associative-container/#_2) 类似，这里不再赘述。

### 查找操作[¶](https://oi-wiki.org/lang/csl/associative-container/#_6)

`multiset` 的查找操作和 `set` 的 [查找操作](https://oi-wiki.org/lang/csl/associative-container/#_3) 类似，这里不再赘述。

## `map`[¶](https://oi-wiki.org/lang/csl/associative-container/#map)

`map` 是有序键值对（Attribute–value pair）容器，它的元素的键是唯一的。搜索、移除和插入操作拥有对数复杂度。 `map` 通常实现为红黑树。

你可能需要存储一些键值对，例如存储学生姓名对应的分数： `Tom 0` ， `Bob 100` ， `Alan 100`。 但是由于数组下标只能为非负整数，所以无法用姓名作为下标来存储，这个时候最简单的办法就是使用 STL 中的 `map` 了！

`map` 重载了 `operator[]` ，可以用任意定义了 `operator <` 的类型作为下标（在 `map` 中叫做 `key` ，也就是索引）：

```
map<Key, T> yourMap;
```

其中， `Key` 是键的类型， `T` 是值的类型，下面是使用 `map` 的实例：

```
map<string, int> mp;
```

### 添加元素[¶](https://oi-wiki.org/lang/csl/associative-container/#_7)

1. 直接赋值，例如 `mp["Tom"]=0`
2. 通过插入一个类型为 `pair<Key, T>` 的值，例如 `mp.insert(pair<string,int>("Alan",100));`
3. 使用 `initializer_list` ：

```
map<string, int> mp = {{"Tom", 0}, {"Bob", "100"}, {"Alan", 100}};
```

### 查找、修改元素[¶](https://oi-wiki.org/lang/csl/associative-container/#_8)

1. 使用赋值语法： `int grade=mp["Tom"]` 。
2. 使用成员函数 `iterator find( const Key& key );` 来确定一个索引是否在 `map` 中。它会返回指向该元素的迭代器；如果索引不在 `map` 中，则会返回尾后迭代器 `mp.end()` 。
3. 如果你想获得 `map` 里全部的元素，请使用迭代器，解引用迭代器会得到一个类型为 `pair<Key, T>` 的值：

```
for (iter = mp.begin(); iter != mp.end(); ++iter)
  cout << iter->first << " " << iter->second << endl;
```

其中使用 `mp.begin()` 可以得到指向 `map` 首元素的迭代器。 如果使用 C++11（及以上），还可以使用 C++11 的范围 for 循环

```
for (auto &i : mp) {
  printf("Key : %d, Value : %d\n", i.first, i.second);
}
```

使用迭代器遍历大小为  的 `map` 的时间复杂度是  。

### 删除元素[¶](https://oi-wiki.org/lang/csl/associative-container/#_9)

如果你想删除 `Tom` 这个元素，则可以利用 `find` 函数找到 `Tom` ，然后再 `erase` 如下

```
map<string, int>::iterator it;
it = mp.find("Tom");
mp.erase(it)
```

如果你想清空所有的元素，可以直接 `mp.clear()`

### 其他函数[¶](https://oi-wiki.org/lang/csl/associative-container/#_10)

- `count` 返回匹配特定键的元素出现的次数，例如 `mp.count("Tom")` 。
- `swap` 可以交换两个 `map` ，例如 `swap(m1,m2)` 。
- `size` 返回 `map` 中元素的个数。
- `empty` 如果 `map` 为空则返回 `true` ，例如 `mp.empty()` 。

# 无序关联式容器



---



# 容器适配器

## stack[¶](https://oi-wiki.org/lang/csl/container-adapter/#stack)

STL 栈 ( `std::stack` ) 是一种后进先出 (Last In, First Out) 的容器适配器，仅支持查询或删除最后一个加入的元素（栈顶元素），不支持随机访问，且为了保证数据的严格有序性，不支持迭代器。

### 头文件和命名空间[¶](https://oi-wiki.org/lang/csl/container-adapter/#_1)

```
#include <stack>
using std::stack
```

### 栈的定义[¶](https://oi-wiki.org/lang/csl/container-adapter/#_2)

```
stack<TypeName> s;  // 使用默认底层容器 deque，数据类型为 TypeName
stack<TypeName, Container> s;  // 使用 Container 作为底层容器

stack<TypeName> s2(s1);  // 以 s1 为模板定义一个栈 s2
```

### 成员函数[¶](https://oi-wiki.org/lang/csl/container-adapter/#_3)

#### 以下所有函数均为常数复杂度[¶](https://oi-wiki.org/lang/csl/container-adapter/#_4)

- `top()` 访问栈顶元素（如果栈为空，此处会出错）
- `push(x)` 向栈中插入元素 x
- `pop()` 删除栈顶元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

### 简单示例[¶](https://oi-wiki.org/lang/csl/container-adapter/#_5)

```
stack<int> s1;
s1.push(2);
s1.push(1);
stack<int> s2(s1);
s1.pop();
std::cout << s1.size() << " " << s2.size() << endl;  // 1 2
std::cout << s1.top() << " " << s2.top() << endl;    // 2 1
s1.pop();
std::cout << s1.empty() << " " << s2.empty() << endl;  // 1 0
```

## queue[¶](https://oi-wiki.org/lang/csl/container-adapter/#queue)

STL 队列 ( `std::queue` ) 是一种先进先出 (First In, First Out) 的容器适配器，仅支持查询或删除第一个加入的元素（队首元素），不支持随机访问，且为了保证数据的严格有序性，不支持迭代器。

### 头文件和命名空间[¶](https://oi-wiki.org/lang/csl/container-adapter/#_6)

```
#include <queue>
using std::queue
```

### 队列的定义[¶](https://oi-wiki.org/lang/csl/container-adapter/#_7)

```
queue<TypeName> q;  // 使用默认底层容器 deque，数据类型为 TypeName
queue<TypeName, Container> q;  // 使用 Container 作为底层容器

queue<TypeName> q2(q1);  // 以 q1 为模板定义一个队列 q2
```

### 成员函数[¶](https://oi-wiki.org/lang/csl/container-adapter/#_8)

#### 以下所有函数均为常数复杂度[¶](https://oi-wiki.org/lang/csl/container-adapter/#_9)

- `front()` 访问队首元素（如果队列为空，此处会出错）
- `push(x)` 向队列中插入元素 x
- `pop()` 删除队首元素
- `size()` 查询容器中的元素数量
- `empty()` 询问容器是否为空

### 简单示例[¶](https://oi-wiki.org/lang/csl/container-adapter/#_10)

```
stack<int> q1;
q1.push(2);
q1.push(1);
stack<int> q2(q1);
q1.pop();
std::cout << q1.size() << " " << q2.size() << endl;    // 1 2
std::cout << q1.front() << " " << q2.front() << endl;  // 1 2
q1.pop();
std::cout << q1.empty() << " " << q2.empty() << endl;  // 1 0
```

## priority_queue[¶](https://oi-wiki.org/lang/csl/container-adapter/#priority_queue)

```
#include <queue>  // std::priority_queue
// 本文里的所有优先队列都会加上命名空间
// 如果不想加命名空间，需要使用：using std::priority_queue;
// 不推荐直接使用 using namespace std;
std::priority_queue<T, Container, Compare> q;
/*
 * T: 储存的元素类型
 * Container:
 * 储存的容器类型，且要求满足顺序容器的要求、具有随机访问迭代器的要求 且支持
 * front() / push_back() / pop_back() 三个函数， 标准容器中 std::vector /
 * std::deque 满足这些要求。 Compare: 默认为严格的弱序比较类型
 * priority_queue 是按照元素优先级大的在堆顶，根据 operator <
 * 的定义，默认是大根堆， 我们可以利用
 * greater<T>（若支持），或者自定义类的小于号重载实现排序。
 * 注意：只支持小于号重载而不支持其他比较符号的重载。
 */
// 构造方式 ：
std::priority_queue<int> q1;
std::priority_queue<int, vector<int>> q2;
// C++11 前，请使用 vector<int> >，空格不可省略
std::priority_queue<int, deque<int>, greater<int>> q3;
// 注意：不可跳过容器参数直接传入比较类
```

### 成员函数[¶](https://oi-wiki.org/lang/csl/container-adapter/#_11)

1. `top()` : 访问栈顶元素 常数复杂度
2. `empty()` : 检查底层的容器是否为空 常数复杂度
3. `size()` : 返回底层容器的元素数量 常数复杂度
4. `push()` : 插入元素，并对底层容器排序 最坏  均摊 
5. `pop()` : 删除第一个元素 最坏 

由于 `std::priority_queue` 原生不支持 `modify()` / `join()` / `erase()` 故不做讲解。

### 示例[¶](https://oi-wiki.org/lang/csl/container-adapter/#_12)

```
q1.push(1);
// 堆中元素 ： [1];
for (int i = 2; i <= 5; i++) q1.push(i);
// 堆中元素 :  [1, 2, 3, 4, 5];
std::cout << q1.top() << std::endl;
// 输出结果 : 5;
q1.pop();
std::cout << q1.size() << std::endl;
// 输出结果 ：4
// 堆中元素 : [1, 2, 3, 4];
q1.push(10);
// 堆中元素 : [1, 2, 3, 4, 10];
std::cout << q1.top() << std::endl;
// 输出结果 : 10;
q1.pop();
// 堆中元素 : [1, 2, 3, 4];
```

---

