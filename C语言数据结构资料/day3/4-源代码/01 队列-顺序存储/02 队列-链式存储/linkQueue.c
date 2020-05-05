#include "linkQueue.h"

//初始化队列
LinkQueue init_LinkQueue()
{
	struct LQueue * myQueue = malloc(sizeof(struct LQueue));

	if (myQueue == NULL)
	{
		return NULL ;
	}

	myQueue->pHeader.next = NULL;

	myQueue->m_Size = 0;

	myQueue->pTail = &myQueue->pHeader; //尾节点初始化 就是在头节点

	return myQueue;

}

//入队
void push_LinkQueue(LinkQueue queue, void * data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//还原真实队列结构体
	struct LQueue * myQueue = queue;

	//取出用户数据的前四个字节
	struct QueueNode * myNode = data;

	//插入新的节点 
	myQueue->pTail->next = myNode;
	myNode->next = NULL;

	myQueue->pTail = myNode;

	//更新队列长度
	myQueue->m_Size++;
}

//出队
void pop_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct LQueue * myQueue = queue;

	if (myQueue->m_Size <= 0)
	{
		return;
	}

	if (myQueue->m_Size == 1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader;
		myQueue->m_Size = 0;

		return;
	}

	//第一个有数据的节点
	struct QueueNode * pFirst = myQueue->pHeader.next;

	//更新指针的指向

	myQueue->pHeader.next = pFirst->next;

	//更新队列长度
	myQueue->m_Size--;

}

//返回队头
void * front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct LQueue * myQueue = queue;

	return myQueue->pHeader.next;

}

//返回队尾
void * back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct LQueue * myQueue = queue;

	return myQueue->pTail;
}

//返回队伍大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct LQueue * myQueue = queue;

	return myQueue->m_Size;

}

//销毁
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}


	free(queue);
	queue = NULL;

}
