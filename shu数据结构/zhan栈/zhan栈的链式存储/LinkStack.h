/*************************************************************************
	> File Name: LinkStack.h
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月11日 星期三 10时15分12秒
 ************************************************************************/

#ifndef _LINKSTACK_H
#define _LINKSTACK_H
#endif

#include <stdlib.h>

struct StackNode {
    struct StackNode *next;
};

struct LStack {
    struct StackNode header; //头结点
    int size;
};

typedef void* LinkStack;

//初始化
LinkStack Init_LinkStack ();
//入栈
void Push_LinkStack (LinkStack stack, void *data);
//出栈
void Pop_LinkStack (LinkStack stack);
//获得栈顶元素
void* Top_LinkStack (LinkStack stack);
//获得大小
int Size_LinkStack (LinkStack stack);
//判断是否为空
int isEmpty_LinkStack (LinkStack stack);
//销毁栈
void Destory_LinkStack (LinkStack);

