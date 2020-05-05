/*************************************************************************
	> File Name: test.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月09日 星期一 20时48分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SeqStack.h"

//初始化
SeqStack Init_SeqStack () {
    struct SStack *stack = malloc (sizeof (struct SStack));
    if (NULL == stack) {
        return NULL;
    }

    memset (stack, 0, sizeof (struct SStack));
    stack -> size = 0;
    return stack;
}

//入栈
void Push_SeqStack (SeqStack stack, void *data) {
    if (NULL == stack) {
        return ;
    }

    if (NULL == data) {
        return ;
    }

    struct SStack *s = (struct SStack *) stack;

    s -> data [s -> size] = data;
    s -> size++;
}

//出栈
void Pop_SeqStack (SeqStack stack) {
    if (NULL == stack) {
        return ;
    }

    struct SStack *s = (struct SStack *) stack;

    if (s -> size == 0) {
        return ;
    }

    s -> data[s -> size - 1] = NULL;
    s -> size--;
}

//获得栈顶元素
void *Top_SeqStack (SeqStack stack) {
    if (NULL == stack) {
        return NULL;
    }

    struct SStack *s = (struct SStack *) stack;

    if (s -> size == 0) {
        return NULL;
    }

    return s -> data[s -> size - 1];
}

//获得大小
int Size_SeqStack (SeqStack stack) {
    if (NULL == stack) {
        return -1;
    }

    struct SStack *s = (struct SStack *) stack;

    return s -> size;
}

//销毁栈
void Destory_SeqStack (SeqStack stack) {
    if (NULL == stack) {
        return ;
    }
    free (stack);
    stack = NULL;
}
