# 大数

## 大数乘法 bug

```c++
/*************************************************************************
	> File Name: cheng.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019е№ґ03жњ€31ж—Ґ жџжњџж—Ґ 10ж—¶15е€†09з§’
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int num[100] = {0};
int a[100] ={0};
int main() {
    int i, j;
    num[0] = num[1] = 1;
    for(i = 1; i <= 50; i++) {
        for(j = 1; j <= num[0];j++) {
            num[j] *= i;
        }
    for(j = 1; j <= num[0]; j++) {
        if(num[j] < 10) {
            continue;
        } else {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
            num[0] += (j == num[0]);
        }
       // cout<<num<<endl;
    }
        for(int i = num[0]; i > 0;i--) {
            cout<<num[i];
        }
        cout<<endl;
    }
    return 0;
}

```

## 大数加法

```c++
/*************************************************************************
	> File Name: dashu+.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019е№ґ03жњ€31ж—Ґ жџжњџж—Ґ 09ж—¶38е€†53з§’
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define max 1000
int addition(char num1[], char num2[], int sum[]) {
    int i, j, len;
    int n2[max] = {0};
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    len = len1 > len2 ? len1 : len2;
    for(i = len1 - 1, j = 0; i >= 0; i--,j++)
    sum[j] = num1[i] - '0';
    for(i = len2 - 1, j = 0; i >= 0; i--,j++)
    n2[j] = num2[i] - '0';
    for(i = 0; i <= len; i++) {
        sum[i] += n2[i];
        if(sum[i] > 9) {
            sum[i] -= 10;
            sum[i + 1] ++;
        }
    }
    if(sum[len] != 0) 
       len++;
    return len;
}
int main() {
    int i, len;
    int sum[max] = {0};
    char num1[] = "1234567891234567891234";
    char num2[] = "2345678912345678913345";
    len = addition(num1, num2, sum);
    //cout<<num1<<endl<<num2<<endl;
    printf("%s\n +\n%s\n =\n", num1, num2);
    for(i = len - 1; i >= 0;i--) 
       cout<<sum[i];
    cout<<endl;
    return 0;
}

```

## 大数除法

```c++
/*************************************************************************
	> File Name: 高精度除以高精度.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月29日 星期五 23时44分04秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int a[100], b[100], c[100];
int compare(int a[], int b[]) {
    int i;
    if(a[0] > b[0])
      return 1;
    if(a[0] < b[0])  
      return -1;
    for(i = a[0]; i > 0; i--) { //从高位到低位比较
        if(a[i] > b[i])
           return 1;
        if(a[i] < b[i])
           return -1;
    }
    return 0;
}
void subduction(int a[], int b[]) { // 计算a = a - b
    int flag;
    int i;
    flag = compare(a,b) ;
    if(flag == 0) { //相等
        a[0] = 0;
        return;
    }
                                   if(flag == 1) { //大于
                                       for(i = 1; i <= a[0]; i++) {
                                           if(a[i] < b[i]) { // 若不够向上借位
                                               a[i + 1] --;
                                               a[i] += 10;
                                           }
                                           a[i]-=b[i];
                                       }
                                                  while(a[0] > 0 && a[a[0]] == 0) //删除前导0
                                                      a[0]--;
                                                  return ;
                                   }
}
int main() {
    char str1[100], str2[100];
    int i, j;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    cin>>str1>>str2;
    a[0] = strlen(str1); //a[0]储存串1的位数
    b[0] = strlen(str2); //b[0]储存串2的位数
    for(i = 1; i <= a[0]; i++) {
        a[i] = str1[a[0] - i] - '0';  
    }
    for(i = 1; i <= b[0]; i++) {
        b[i] = str2[b[0] - i] - '0';
    }
    int temp[100];
    c[0] = a[0] - b[0] + 1;
    for(i = c[0]; i > 0;i--) {
        memset(temp, 0, sizeof(temp));
        for(j = 1;j <= b[0];j++) { //从i开始的地方，复制数组temp
            temp[j + i - 1] = b[j];
        }
            temp[0] = b[0] + i - 1;
        while(compare(a,temp) >= 0) { //用减法模拟
            c[i] ++;
            subduction(a, temp);
        }
    }
    while(c[0] > 0 && c[c[0]] == 0) {
        c[0]--;
        cout<<"商为：";
        if(c[0] == 0) //输出结果
        cout<<0<<endl;
        else {
            for(i = c[0]; i > 0;i--) {
                cout<<c[i];
            }
            cout<<endl;
        }
        cout<<"余数为:";
        if(a[0] == 0) //输出数
        cout<<0<<endl;
        else {
            for(i = a[0]; i > 0;i--) {
                cout<<a[i];
            }
            cout<<endl;
        }
    }
    return 0;
}

```

---

# 二分

## 二分查找

找到的话且这个数唯一则返回下标位置，如果不唯一则返回最右边的下标；找不到的话返回比它大的第一个数（即右边的数）的下标。

```c++
int bSearch　(int begin, int end, int e)　{  
    int mid, left = begin, right = end;  
    while(left <= right)  
    {  
        mid = (left + right) >> 1;  
        if(arr[mid] >= e) right = mid - 1;  
        else left = mid + 1;  
    }  
    return left;  
}  
```

以下代码经过细微修改，找不到的话返回比它小的第一个数（即左边的数）的下标

```c++
int bSearch　(int begin, int end, int e) {  
    int mid, left = begin, right = end;  
    while(left <= right)  
    {  
        mid = (left + right) >> 1;  
        if(arr[mid] > e) right = mid - 1;//等号  
        else left = mid + 1;  
    }  
    return right;  
}  
```

---

```c++
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int search(int *arr, int len, int key) {
	int l = 0, r = len - 1, mid;
	while (l <= r) {
		mid = (r + l) / 2;
		// mid = l + (r - l) / 2;
		if (arr[mid] == key) return 1;
		if (arr[mid] > key) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

void init_arr(int *arr) {
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 50;
	}
	return ;
}

void output(int *arr) {
	cout << "arr" << endl;
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return ;
}

int main() {
	srand(time(0));
	int arr[20] = {0};
	init_arr(arr);
	sort(arr, arr + 20);
	output(arr);
	int key = rand() % 50; 
	cout << "key：" << key << endl;
	cout << search(arr, 20, key) << endl;
	return 0;
} 
```

```c++
// 111111000000
int binary_search1(int *num, int n) {
    int l = -1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (num[mid] == 1) l = mid;
        else r = mid - 1;
    }
    return l;
}

```

```c++
// 0000001111111
int binary_search2(int *num, int n) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (num[mid] == 1) l = mid;
        else r = mid + 1;
    }
    return l == n ? -1 : l;
}
```

---



# 线性筛模板

## 模板：

```
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
using namespace std;

int check[100000] = {0};
int prime[100000] = {0};
int cnt = 0;

void Init () {
    int N = 100000;
    for (int i = 2; i <= N; i++) { 
        if (!check[i]) prime[cnt++] = i;//没被筛掉，判为素数
        for (int j = 0; j < cnt && prime[j] * i <= N; j++) { //枚举现有素数
            check[prime[j] * i] = 1; //筛掉合数
            if (i % prime[j] == 0) break; //保证每个数只被最小因子筛掉
        }
    }
    return ;
}

int main() {
    int n;
    Init ();
    while (cin >> n) {
        int flag = 0;
        for (int i = 2; i <= n; i++) {
            if (!check[n]) {
                flag = 1;
            }
        }
        cout << (flag ? "yes" : "no") << endl;
    }
    return 0;
}
```



## 素数筛

```c++
#include<iostream>
#define max 100
int prime[max + 5] = {0};
using namespace std;
void init() {
    prime[0] = prime[1] = 1;
    for(int i = 2; i * i <= max;++i) {
        if(prime[i]) continue;
        for(int j = 2 * i; j <= max; j += i) {
            prime[j] = 1;
        }
    }
}
int main() {
    init();
    int n;
    while(cin>>n) {
        if(n <= max && prime[n] == 0) 
        cout<<"YES"<<endl;
       else {
          cout<<"NO"<<endl;
        }
    }
    return 0;
}

```



---

# 基础数据结构 栈和队列

## 1栈

一、头文件

```
#include<queue> //队列的头文件
#include<stack> //栈的头文件
```

二、 定义方式

```
stack<int> s; //参数也是数据类型，这是栈的定义方式
queue<int> q; //参数是数据类型， 这是队列的定义方式
```

三、常用操作

**栈**

```
s.empty() //如果栈为空， 返回true， 否则返回false
s.size() //返回栈中元素的个数
s.pop() //删除栈顶元素 但不返回其值
s.top() //返回栈顶的元素， 但不删除该元素
s.push(X) //在栈顶压入新元素， 参数X为要压入的元素
```

**队列**

```
q.empty() //如果队列为空 ， 返回true， 否则返回false
q.size() //返回队列中元素的个数
q.pop() //删除队列首元素 ， 但不返回其值
q.front() //返回队首元素的值， 但不删除该元素
q.push(X) //在队尾压入新元素， X为要压入的元素
q.back() //返回队列元素的值， 但不删除该元素
```





##  万能头文件

```c++
#include<bits/stdc++.h>
```





## 圆周率π　

`acos(-1.0)`  = **- 1**的反余弦函数值，等于　*3.141592653589793*  **15位小数**

---



## 查表输出法

```c++
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

double a[1000];// = {0};
int main() {
    memset(a, 0, sizeof(a));
    for(int i = 1; i < 1000; i++) {
        double t;
        if(i % 2 == 0) {
            t = -1.0 / i;
        } else {
            t = 1.0 / i;
        }
        a[i] = a[i - 1] + t;
    }
    //现将符合条件的结果存放起来　然后直接输出它的值
    int m, n;
    while(cin >> m) {
        while(m--) {
            cin >> n;
            cout << setiosflags(ios::fixed) << setprecision(2) << a[n] <<endl;
          //  printf("%.2f\n", a[n]);
        }
    }
    return 0;
}

```



---



# DP

## 数位dp

###  <数位DP>

　所谓数位DP就是基于考虑数字的每一位来转移的DP。

　例如求比456小的数，可以这么考虑，

```c++

　　　　　　　　4          5               6

　　　　　　　  4　        5             (0~6)

　　　　　　　　4        (0~4)          (0~9)

　　　　　　　(0~3)     (0~9)          (0~9)
```

### 模板：

```c++
typedef long long ll;
int a[20];
ll dp[20][state];//不同题目状态不同
ll dfs(int pos,/*state变量*/,bool lead/*前导零*/,bool limit/*数位上界变量*/)//不是每个题都要判断前导零
{
    //递归边界，既然是按位枚举，最低位是0，那么pos==-1说明这个数我枚举完了
    if(pos==-1) return 1;/*这里一般返回1，表示你枚举的这个数是合法的，那么这里就需要你在枚举时必须每一位都要满足题目条件，也就是说当前枚举到pos位，一定要保证前面已经枚举的数位是合法的。不过具体题目不同或者写法不同的话不一定要返回1 */
    //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)
    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];
    /*常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应，具体为什么是有条件的记忆化后面会讲*/
    int up=limit?a[pos]:9;//根据limit判断枚举的上界up;这个的例子前面用213讲过了
    ll ans=0;
    //开始计数
    for(int i=0;i<=up;i++)//枚举，然后把不同情况的个数加到ans就可以了
    {
        if() ...
        else if()...
        ans+=dfs(pos-1,/*状态转移*/,lead && i==0,limit && i==a[pos]) //最后两个变量传参都是这样写的
        /*这里还算比较灵活，不过做几个题就觉得这里也是套路了
        大概就是说，我当前数位枚举的数是i，然后根据题目的约束条件分类讨论
        去计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目
        要求数位上不能有62连续出现,那么就是state就是要保存前一位pre,然后分类，
        前一位如果是6那么这意味就不能是2，这里一定要保存枚举的这个数是合法*/
    }
    //计算完，记录状态
    if(!limit && !lead) dp[pos][state]=ans;
    /*这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了*/
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)//把数位都分解出来
    {
        a[pos++]=x%10;//个人老是喜欢编号为[0,pos),看不惯的就按自己习惯来，反正注意数位边界就行
        x/=10;
    }
    return dfs(pos-1/*从最高位开始枚举*/,/*一系列状态 */,true,true);//刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛
}
int main()
{
    ll le,ri;
    while(~scanf("%lld%lld",&le,&ri))
    {
        //初始化dp数组为-1,这里还有更加优美的优化,后面讲
        printf("%lld\n",solve(ri)-solve(le-1));
    }
}
```



---



# 数学公式

## 抛物线

**面积：**

一个抛物线与 **x**轴两点横坐标**x1, x2 (x2 > x1)**，定点纵坐标为**y**，那么它与**x**轴所围面积等于**(2 / 3)  ×  (x2 - x1) ×  y**

## 三角形面积

##### 1.海伦公式：

![formula](https://ss0.baidu.com/6ONWsjip0QIZ8tyhnq/it/u=3652749987,823871558&fm=58)

公式描述：公式中a，ｂ，ｃ分别为三角形三边长，ｐ为半周长，Ｓ为三角形的面积。

```mathematica
p = (a+b+c)/2;  
S = sqrt(p*(p-a)*(p-b)*(p-c));
```

##### **2:叉积求解：一直三点：**

```mathematica
A(x1,y1),B(x2,y2),C(x3,y3);  
S = fabs(-x2 * y1 + x3*y1+x1*y2-x3*y2-x1*y3+x2*y3) / 2.0;
```

## 斯特林公式（阶乘）

斯特林公式是一条用来取n[阶乘](https://zh.wikipedia.org/wiki/%E9%9A%8E%E4%B9%98)[近似值](https://zh.wikipedia.org/wiki/%E8%BF%91%E4%BC%BC%E5%80%BC)的[数学](https://zh.wikipedia.org/wiki/%E6%95%B8%E5%AD%B8)[公式](https://zh.wikipedia.org/wiki/%E5%85%AC%E5%BC%8F)。一般来说，当n很大的时候，n阶乘的计算量十分大，所以斯特林公式十分好用，而且，即使在n很小的时候，斯特林公式的取值已经十分准确。

公式为：![n! \approx \sqrt{2\pi n}\, \left(\frac{n}{e}\right)^{n}.](https://wikimedia.org/api/rest_v1/media/math/render/svg/89f2825420a3001dc539f1363784f421dcc6d569)

斯特林公式的编程写法：N！=sqrt（2×pi×N）*（N/e）^N；（pi=3.1415926=acos（-1.0），e=2.718）

斯特林公式的转换：lgN！=(lg(2×pi)+lgN)/2+N*(lgN-lge); //+1即为长度。

**模板：**

```
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int PI = acos(-1.0);

int main () {
    int n;
    while (cin >> n) {
        double ans;
        ans = (0.5 * log (2 * PI * n) + n * (log(n) - 1)) / log(10);
        cout << (ll) ans + 1 << endl;
    }
    return 0;
}
```

------



## 

---

# 最大子序列和问题 O(n)

```c++
int maxSubsequenceSum(const int a[], int n) {
    int i;
    int maxSum, thisSum;
    maxSum = thisSum = 0;
    for (i = 0; i < n; i++) {
        thisSum += a[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}
```



#　模板BFS(临接矩阵):

```ｃ++
queue<int> q;
bool visited[N];
void BFS(int start)
{
  q.push(start); visited[start]=true;
do
   {
    int a=q.front(); q.pop();
    // 处理点a
    cout<<a<<' ';
    for (int i=0;i<n;i++)
    if  ((!visited[i]) && (G[a][i]!=INF))
      {
    q.push(i);
           visited[a]=true;
    }
    } while (!q.empty());
    }
```

```c++
	memset(visited,0,sizeof(visited));
    for (int i=0;i<n;i++)
    if (!visited[i]) BFS(i);
```

---



# 模板DFS (邻接矩阵):

```c++
 bool visited[N];
    void DFS(int start)
    {
      visited[start]=true;    // 处理点start
      cout<<start<<' ';
      for (int i=0; i<n; i++)
         if ((!visited[i]) && (G[start][i]!=INF))
    DFS(i);
```

```c++
    memset(visited,0,sizeof(visited));
    for (int i=0;i<n;i++)
    if (!visited[i]) DFS(i);
```

---

# 并查集

## get操作

```c++
int get(int x){
    if(x==fa[x])    return x;
    return fa[x]=get(fa[x]);//路径压缩
}

or

int get(int x) {
	x == fa[x] ? x : fa[x] = get(fa[x]);
}
```

## merge操作

```c++
void merge(int x,int y){
    fa[get(x)]=get(y);
} // 可以直接写在程序里
```

==注==：**并查集一定要初始化，即fa[i]=i，表示i的爹是它自己**

