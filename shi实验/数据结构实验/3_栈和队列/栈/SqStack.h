/*************************************************************************
	> File Name: SqStack.h
	> Author: kwh
	> Mail: 
	> Created Time: 2019年10月11日 星期五 11时06分55秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#endif

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#include "status.h"

class SqStack {
    private :
        SElemType *base;
        SElemType *top;
        int stacksize;
    public :
        Status InitStack (SqStack *S);
        Status DestroyStack (SqStack *S);
        Status ClearStack (SqStack *S);
        Status StackEmpty (SqStack *S);
        int StackLength (SqStack *S);//栈一般不求长度
        Status GetTop (SElemType &e);
        Status Push (SqStack *S, SElemType e);
        Status Pop (SqStack *S, SElemType &e);
        Status PrintSqStack (SqStack *S);
}; //分号

