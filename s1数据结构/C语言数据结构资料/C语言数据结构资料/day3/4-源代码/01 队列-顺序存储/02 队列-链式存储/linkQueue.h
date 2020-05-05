#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//����ڵ�
struct QueueNode
{
	struct QueueNode * next; //ֻά��ָ����
};

//���нṹ��
struct LQueue
{
	//ͷ�ڵ�
	struct QueueNode pHeader;

	//���д�С
	int m_Size;

	//ά��β�ڵ��ָ��
	struct QueueNode * pTail;

};

typedef void * LinkQueue;

//��ʼ������
LinkQueue init_LinkQueue();

//���
void push_LinkQueue( LinkQueue queue, void * data );

//����
void pop_LinkQueue(LinkQueue queue);

//���ض�ͷ
void * front_LinkQueue(LinkQueue queue);

//���ض�β
void * back_LinkQueue(LinkQueue queue);

//���ض����С
int size_LinkQueue(LinkQueue queue);

//����
void destroy_LinkQueue(LinkQueue queue);
