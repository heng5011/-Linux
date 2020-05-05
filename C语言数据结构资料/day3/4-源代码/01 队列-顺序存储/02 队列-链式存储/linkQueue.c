#include "linkQueue.h"

//��ʼ������
LinkQueue init_LinkQueue()
{
	struct LQueue * myQueue = malloc(sizeof(struct LQueue));

	if (myQueue == NULL)
	{
		return NULL ;
	}

	myQueue->pHeader.next = NULL;

	myQueue->m_Size = 0;

	myQueue->pTail = &myQueue->pHeader; //β�ڵ��ʼ�� ������ͷ�ڵ�

	return myQueue;

}

//���
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

	//��ԭ��ʵ���нṹ��
	struct LQueue * myQueue = queue;

	//ȡ���û����ݵ�ǰ�ĸ��ֽ�
	struct QueueNode * myNode = data;

	//�����µĽڵ� 
	myQueue->pTail->next = myNode;
	myNode->next = NULL;

	myQueue->pTail = myNode;

	//���¶��г���
	myQueue->m_Size++;
}

//����
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

	//��һ�������ݵĽڵ�
	struct QueueNode * pFirst = myQueue->pHeader.next;

	//����ָ���ָ��

	myQueue->pHeader.next = pFirst->next;

	//���¶��г���
	myQueue->m_Size--;

}

//���ض�ͷ
void * front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct LQueue * myQueue = queue;

	return myQueue->pHeader.next;

}

//���ض�β
void * back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct LQueue * myQueue = queue;

	return myQueue->pTail;
}

//���ض����С
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct LQueue * myQueue = queue;

	return myQueue->m_Size;

}

//����
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}


	free(queue);
	queue = NULL;

}
