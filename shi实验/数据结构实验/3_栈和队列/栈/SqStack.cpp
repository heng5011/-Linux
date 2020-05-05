/*************************************************************************
	> File Name: SqStack.cpp
	> Author: kwh
	> Mail: 
	> Created Time: 2019年10月11日 星期五 11时13分55秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include "SqStack.h"
using namespace std;

//初始化
Status SqStack :: InitStack (SqStack *S) {
    base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof (SElemType));
    if (!base) exit(OVERFLOW);
    top = base;
    stacksize = STACK_INIT_SIZE;
    return OK;
}

//销毁
Status SqStack :: DestroyStack (SqStack *S) {
    free (base); 
    stacksize = 0;
    return OK;
}

//清空
Status SqStack :: ClearStack (SqStack *S) {
    top = base;
    return OK;
}

//判断是否为空栈
Status SqStack :: StackEmpty (SqStack *S) {
    if (base == top) return TRUE;
    else return FALSE;
}

//求栈长度
int SqStack :: StackLength (SqStack *S) {
    return top - base - 1;
    //return base - top;
}

//出栈
Status SqStack :: GetTop (SElemType &e) {
    if (top == base) return ERROR;
    e = *(top - 2); //top - 1不行
    return OK;
}

//入栈
Status SqStack :: Push (SqStack *S, SElemType e) {
    if (top - base >= stacksize) {
        base = (SElemType *) realloc (base, (stacksize + STACK_INIT_SIZE) * sizeof (SElemType));
        if (!base) exit (OVERFLOW);
        top = base + stacksize;
        stacksize += STACKINCREMENT;
    }
    *top++ = e;
    return OK;
}

//删除栈顶元素
Status SqStack :: Pop (SqStack *S, SElemType &e) {
    if (top == base) return ERROR;
    e = * --top;
    return OK;
}

//从栈顶往下打印栈中数据
Status SqStack :: PrintSqStack (SqStack *S) {
    SElemType *p = top;
    while (p != base) {
        printf ("%d ", *(p -1));
        p--;
    }
    printf ("\n");
    return OK;
}
