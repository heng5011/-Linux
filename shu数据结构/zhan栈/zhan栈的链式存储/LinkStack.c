/*************************************************************************
	> File Name: LinkStack.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月11日 星期三 10时21分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

//初始化
LinkStack Init_LinkStack () {
    struct LStack *stack = malloc (sizeof (struct LStack));
    if (NULL == stack) {
        return NULL;
    }

    stack -> header.next = NULL;
    stack -> size = 0;
    return stack;
}
//入栈
void Push_LinkStack (LinkStack stack, void *data) {
    if (NULL == stack) {
        return ;
    }

    if (NULL == data) {
        return ;
    }

    struct LStack *ls = (struct LStack *) stack;
    struct StackNode *node = (struct StackNode *)data;

    node -> next = ls -> header.next;
    ls -> header.next = node;

    ++(ls -> size);
}

//出栈
void Pop_LinkStack (LinkStack stack) {
    if (NULL == stack) {
        return ;
    }

    struct LStack *ls = (struct LStack *) stack;

    if (ls -> size == 0) {
        return;
    }

    //保存第一个节点　栈顶元素
    struct StackNode *pFirst = ls -> header.next;

    ls -> header.next = pFirst -> next;

    //更新链表长度　栈大小
    ls -> size--;
      
}

//获得栈顶元素
void* Top_LinkStack (LinkStack stack) {
    if (NULL == stack) {
        return NULL;
    }

    struct LStack *ls = (struct LStack *)stack;

    if (ls -> size == 0) {
        return NULL;
    }
    
    return ls -> header.next;
}

//判断是否为空
int isEmpty_LinkStack (LinkStack stack) {
    if (NULL == stack) {
        return -1;
    }
    struct LStack *ls = (struct LStack *)stack;  
    if (ls -> size <= 0) {
        return 1;
    }

    return 0;
}

//获得大小
int Size_LinkStack (LinkStack stack) {
    if (NULL == stack) {
        return -1;
    }

    struct LStack *ls = (struct LStack *) stack;
    return ls -> size;
}

//销毁栈
void Destory_LinkStack (LinkStack stack) {
    if (NULL == stack) {
        return ;
    }
    free (stack);
    stack = NULL;
}


