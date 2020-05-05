/*************************************************************************
	> File Name: zhan栈的顺序存储.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月10日 星期二 18时44分32秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqStack.h"

struct Person {
    char name[64];
    int age;
};

void test () {

    //初始化栈
    SeqStack stack = Init_SeqStack();

    //创建数据
    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"ccc", 30};
    struct Person p4 = {"ddd", 40};
    struct Person p5 = {"eee", 50};
    struct Person p6 = {"fff", 60};

    //输入栈
    Push_SeqStack (stack, &p1);
    Push_SeqStack (stack, &p2);
    Push_SeqStack (stack, &p3);
    Push_SeqStack (stack, &p4);
    Push_SeqStack (stack, &p5);
    Push_SeqStack (stack, &p6);

    //输出栈中所有元素
    while (Size_SeqStack (stack) > 0) {
        //获得栈顶元素
        struct Person *person = (struct Person *) Top_SeqStack (stack);

        //打印
        printf ("Name:%s Age: %d\n", person -> name, person -> age);

        printf ("Size: %d\n", Size_SeqStack (stack));
        //弹出栈顶元素
        Pop_SeqStack (stack);
    }

    printf ("\n\nSize: %d\n", Size_SeqStack (stack));

    //销毁栈
    Destory_SeqStack (stack);
}


int main() {

    test ();

    return 0;
}
