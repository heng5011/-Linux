#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//#define  MAX 1024
////ջ�Ľṹ��
//struct SStack
//{
//	void * data[MAX]; //����
//
//	//ջ��Ԫ�ظ���
//	int m_Size;
//};

typedef void * seqStack;

//��ʼ��ջ
seqStack init_SeqStack();


//��ջ
void push_SeqStack(seqStack stack, void * data);

//��ջ
void pop_SeqStack(seqStack stack);


//��ȡջ��Ԫ��
void * top_SeqStack(seqStack stack);


//ջ�Ĵ�С
int size_SeqStack(seqStack stack);



//�ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(seqStack stack);


//����ջ
void destroy_SeqStack(seqStack stack);


