#include "seqQueue.h"

//��ʼ������
seqQueue init_SeqQueue()
{
	struct dynamicArray * arr =  init_DynamicArray(MAX);

	return arr;
}

//���
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

	//��� === β��
	insert_dynamicArray(myQueue, myQueue->m_size, data);

}

//����
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

//���ض�ͷԪ��
void * front_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * myQueue = queue;

	return myQueue->pAddr[0];

}

//���ض�βԪ��
void * back_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * myQueue = queue;
	return myQueue->pAddr[myQueue->m_size - 1];

}

//���ض����С
int size_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct dynamicArray * myQueue = queue;
	return myQueue->m_size;


}

//����
void destroy_SeqQueue(seqQueue queue)
{
	
	if (queue == NULL)
	{
		return;
	}

	destroy_DynamicArray(queue);

}