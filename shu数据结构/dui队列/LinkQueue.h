/*************************************************************************
	> File Name: LinkQueue.h
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月14日 星期六 14时16分00秒
 ************************************************************************/

#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H
#endif

//链表结点的数据类型
struct QueueNode {
    struct QueueNode *next;
};

//链表数据类型
struct LQueue {
    struct QueueNode header; //头结点
    int size;
    struct QueueNode *rear; //尾指针, 始终指向链表的最后一个结点
};

typedef void* LinkQueue;

//初始化
LinkQueue Init_LinkQueue ();
//入队
void Push_LinkQueue (LinkQueue queue, void *data);
//出队
void Pop_LinkQueue (LinkQueue queue);
//获得队头元素
void* Front_LinkQueue (LinkQueue queue);
//获得队尾元素
void* Back_LinkQueue (LinkQueue queue);
//大小
int Size_LinkQueue (LinkQueue queue);
//销毁队列
void Destory_LinkQueue ();
