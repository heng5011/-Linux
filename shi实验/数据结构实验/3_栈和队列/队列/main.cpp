/*************************************************************************
	> File Name: main.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年10月24日 星期四 19时18分47秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include "LinkQueue.h"
using namespace std;

void test () {
    Status re;
    int i = 0, l;
    QElemType d;
    LinkQueue Q;
    
    //测试初始化队列
    re = Q.InitQueue (Q);
    //Q.InitQueue (Q);
    cout << (re == OK ? "队列初始化成功!" : "队列初始化失败！") << endl;


    for (int i = 0; i < MAXSIZE - 1; i++) {
        Q.EnQueue (Q, i);
    }

    //Q.QueueLength (Q);
    printf ("队长为： %d\n", Q.QueueLength (Q));

    Q.QueueTraverse (Q); //不为空遍历测试

    Q.GetHead (Q, d);
    printf ("对头元素为: d =  %d\n", d);
    printf ("依次出队: \n");

    for (l = 1; l < MAXSIZE; l++) {
        Q.DeQueue (Q, d);
        printf ("d%d", l);
        printf (" = %d\n", d);
        //printf ("对头元素为: d =  %d\n", d); //测试队头元素
    }

    re = Q.ClearQueue (Q);
    cout << (re == OK ? "队列清空成功！" : "队列清空失败！") << endl;

    re = Q.DestroyQueue (Q);
    cout << (re == OK ? "队列销毁成功！" : "队列销毁失败！") << endl;

    Q.QueueTraverse (Q); //空队列遍历测试

}

int main () {

    test ();

    return 0;
}
