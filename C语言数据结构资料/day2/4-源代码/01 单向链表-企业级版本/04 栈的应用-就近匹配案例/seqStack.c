#include "seqStack.h"

#define  MAX 1024
//栈的结构体
struct SStack
{
	void * data[MAX]; //数组

	//栈的元素个数
	int m_Size;
};

typedef void * seqStack;

//初始化栈
seqStack init_SeqStack()
{
	struct SStack * stack = malloc(sizeof(struct SStack));

	if (stack == NULL)
	{
		return NULL;
	}

	//清空数组中的每个元素
	memset(stack->data, 0, sizeof(void*)*MAX);

	stack->m_Size = 0;

	return stack;
}

//入栈
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

	//判断是否已经栈满 ,如果满了 不可以再入栈了
	struct SStack * myStack = stack;
	if (myStack->m_Size == MAX)
	{
		return;
	}

	myStack->data[myStack->m_Size] = data; //入栈  尾插

	myStack->m_Size++; //更新栈大小
}

//出栈
void pop_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	//如果是空栈 不执行出栈
	struct SStack * myStack = stack;
	if (myStack->m_Size <= 0)
	{
		return;
	}

	//执行出栈
	myStack->data[myStack->m_Size - 1] = NULL;
	//更新栈的大小
	myStack->m_Size--;
}


//获取栈顶元素
void * top_SeqStack(seqStack stack)
{

	if (stack == NULL)
	{
		return NULL;
	}

	struct SStack * myStack = stack;

	//如果是空栈   返回 NULL
	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->data[myStack->m_Size - 1];


}

//栈的大小
int size_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	struct SStack * myStack = stack;

	return myStack->m_Size;
}


//判断栈是否为空
int isEmpty_SeqStack(seqStack stack)
{
	if (stack == NULL)
	{
		return -1; //真
	}

	struct SStack * myStack = stack;
	if (myStack->m_Size <= 0)
	{
		return 1; //真
	}

	return  0; //返回假 代表不是空栈
}


//销毁栈
void destroy_SeqStack(seqStack stack)
{

	if (stack == NULL)
	{
		return;
	}

	free(stack);
	stack = NULL;
}
