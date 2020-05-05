#include "seqQueue.h"

//初始化队列
seqQueue init_SeqQueue()
{
	struct dynamicArray * arr =  init_DynamicArray(MAX);

	return arr;
}

//入队
void push_SeqQueue(seqQueue queue, void * data)
{
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct dynamicArray * myQueue = queue;
	if (myQueue->m_size >= MAX)
	{
		return;
	}

	//入队 === 尾插
	insert_dynamicArray(myQueue, myQueue->m_size, data);

}

//出队
void pop_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return;
	}

	struct dynamicArray * myQueue = queue;

	if (myQueue->m_size <= 0)
	{
		return;
	}

	removeByPos_DynamicArray(myQueue, 0);

}

//返回队头元素
void * front_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * myQueue = queue;

	return myQueue->pAddr[0];

}

//返回队尾元素
void * back_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * myQueue = queue;
	return myQueue->pAddr[myQueue->m_size - 1];

}

//返回队伍大小
int size_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myQueue = queue;
	return myQueue->m_size;


}

//销毁
void destroy_SeqQueue(seqQueue queue)
{
	
	if (queue == NULL)
	{
		return;
	}

	destroy_DynamicArray(queue);

}