#include "seqStack.h"

#define  MAX 1024
//ջ�Ľṹ��
struct SStack
{
	void * data[MAX]; //����

	//ջ��Ԫ�ظ���
	int m_Size;
};

typedef void * seqStack;

//��ʼ��ջ
seqStack init_SeqStack()
{
	struct SStack * stack = malloc(sizeof(struct SStack));

	if (stack == NULL)
	{
		return NULL;
	}

	//��������е�ÿ��Ԫ��
	memset(stack->data, 0, sizeof(void*)*MAX);

	stack->m_Size = 0;

	return stack;
}

//��ջ
void push_SeqStack(seqStack stack, void * data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	//�ж��Ƿ��Ѿ�ջ�� ,������� ����������ջ��
	struct SStack * myStack = stack;
	if (myStack->m_Size == MAX)
	{
		return;
	}

	myStack->data[myStack->m_Size] = data; //��ջ  β��

	myStack->m_Size++; //����ջ��С
}

//��ջ
void pop_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	//����ǿ�ջ ��ִ�г�ջ
	struct SStack * myStack = stack;
	if (myStack->m_Size <= 0)
	{
		return;
	}

	//ִ�г�ջ
	myStack->data[myStack->m_Size - 1] = NULL;
	//����ջ�Ĵ�С
	myStack->m_Size--;
}


//��ȡջ��Ԫ��
void * top_SeqStack(seqStack stack)
{

	if (stack == NULL)
	{
		return NULL;
	}

	struct SStack * myStack = stack;

	//����ǿ�ջ   ���� NULL
	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->data[myStack->m_Size - 1];


}

//ջ�Ĵ�С
int size_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct SStack * myStack = stack;

	return myStack->m_Size;
}


//�ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1; //��
	}

	struct SStack * myStack = stack;
	if (myStack->m_Size <= 0)
	{
		return 1; //��
	}

	return  0; //���ؼ� �����ǿ�ջ
}


//����ջ
void destroy_SeqStack(seqStack stack)
{

	if (stack == NULL)
	{
		return;
	}

	free(stack);
	stack = NULL;
}
