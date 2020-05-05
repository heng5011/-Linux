#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//链表节点
struct QueueNode
{
	struct QueueNode * next; //只维护指针域
};

//队列结构体
struct LQueue
{
	//头节点
	struct QueueNode pHeader;

	//队列大小
	int m_Size;

	//维护尾节点的指针
	struct QueueNode * pTail;

};

typedef void * LinkQueue;

//初始化队列
LinkQueue init_LinkQueue();

//入队
void push_LinkQueue( LinkQueue queue, void * data );

//出队
void pop_LinkQueue(LinkQueue queue);

//返回队头
void * front_LinkQueue(LinkQueue queue);

//返回队尾
void * back_LinkQueue(LinkQueue queue);

//返回队伍大小
int size_LinkQueue(LinkQueue queue);

//销毁
void destroy_LinkQueue(LinkQueue queue);
