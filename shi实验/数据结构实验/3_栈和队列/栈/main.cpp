/*************************************************************************
	> File Name: main.cpp
	> Author: kwh
	> Mail: 
	> Created Time: 2019年10月11日 星期五 12时05分08秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "status.h"
#include "SqStack.h"
using namespace std;

void test () {
    SqStack s;
    SElemType e1;
    Status re;

    //初始化
    re = s.InitStack (&s);
    cout << (re == OK ?  "初始化成功!" : "初始化失败!") << endl;
    
    for (int i = 0; i < STACKINCREMENT; i++) {
        s.Push (&s, i);
    }

    while (s.StackEmpty (&s)) {
        s.PrintSqStack (&s);
    }

    cout << "栈的长度为: " << s.StackLength (&s) << '\n';

    s.GetTop (e1);
    printf ("栈顶元素为：e1 = %d\n", e1);

    //依次出栈
    printf ("依次出栈：");
    for (int i = 0; i < STACKINCREMENT; i++) {
        s.Pop (&s, i);
    }

    re = s.PrintSqStack (&s);
    cout << ((re == OK) ? "从栈顶往下打印栈中数据　测试成功!" : "从栈顶往下打印栈中数据　测试失败!") << endl;
    s.PrintSqStack (&s);
    //栈长
    //cout << "栈的长度为: " << s.StackLength (&s) << '\n';

    //清空
    re = s.ClearStack (&s);
    cout << ((re == OK) ? "清空成功!" : "清空失败!") << endl;
    s.ClearStack (&s);

    //销毁
    re = s.DestroyStack (&s);
    cout << ((re == OK) ? "销毁成功!" : "销毁失败!") << endl;
    s.DestroyStack (&s);
}

int main () {

    test ();

    return 0;
}
