#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//#define  MAX 1024
////栈的结构体
//struct SStack
//{
//	void * data[MAX]; //数组
//
//	//栈的元素个数
//	int m_Size;
//};

typedef void * seqStack;

//初始化栈
seqStack init_SeqStack();


//入栈
void push_SeqStack(seqStack stack, void * data);

//出栈
void pop_SeqStack(seqStack stack);


//获取栈顶元素
void * top_SeqStack(seqStack stack);


//栈的大小
int size_SeqStack(seqStack stack);



//判断栈是否为空
int isEmpty_SeqStack(seqStack stack);


//销毁栈
void destroy_SeqStack(seqStack stack);


