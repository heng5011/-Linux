#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct StackNode
{
	struct StackNode * next; //只维护指针域
};

//链式的栈结构体
struct LStack
{
	struct StackNode pHeader; //头节点

	int m_Size; //栈的大小
};

typedef void * LinkStack;

//初始化栈
LinkStack init_LinkStack()
{
	struct LStack * myStack =  malloc(sizeof(struct LStack));

	if ( myStack == NULL)
	{
		return NULL;
	}

	myStack->pHeader.next = NULL;

	myStack->m_Size = 0;

	return myStack;

}

//入栈
void push_LinkStack( LinkStack  stack , void * data)
{
	if ( stack == NULL)
	{
		return;
	}
	if ( data == NULL)
	{
		return;
	}

	//入栈 就是 头插

	struct LStack * myStack = stack;

	//拿到用户数据的前四个字节
	struct StackNode * myNode = data;


	//插入节点
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//更新栈的大小
	myStack->m_Size++;
}

//出栈
void pop_LinkStack( LinkStack stack )
{
	
	if (stack == NULL)
	{
		return;
	}

	struct LStack * myStack = stack;
	//如果是空栈   不出栈了
	if ( myStack->m_Size <= 0 )
	{
		return;
	}

	//保存第一个有数据的节点  栈顶元素
	struct StackNode * pFirst = myStack->pHeader.next;

	myStack->pHeader.next = pFirst->next;

	//更新链表长度  栈大小
	myStack->m_Size--;
}

//返回栈顶元素
void * top_LinkStack(LinkStack stack)
{
	if ( stack == NULL)
	{
		return NULL;
	}

	struct LStack * myStack = stack;
	if (myStack->m_Size <= 0 )
	{
		return NULL;
	}

	return myStack->pHeader.next; //将第一个有数据的节点返回就可以了
}

//返回栈大小
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack * myStack = stack;
	return myStack->m_Size;
}

//判断是否为空
int isEmpty_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack * myStack = stack;
	if (myStack->m_Size <= 0 )
	{
		return 1; 
	}

	return 0;
}
//销毁
void destroy_LinkStack(LinkStack stack)
{

	if (stack == NULL)
	{
		return ;
	}
	free(stack);
	stack = NULL;
}



//测试
struct Person
{
	struct StackNode node;
	char name[64];
	int age;
};
void test01()
{

	//准备出数据
	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	//初始化栈
	LinkStack stack = init_LinkStack();

	//入栈
	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);

	while (isEmpty_LinkStack(stack) == 0) //如果栈不为空  进行访问栈顶元素，并且出栈
	{
		struct Person  * pTop = top_LinkStack(stack); //栈顶元素

		printf("栈顶元素 姓名： %s  年龄：  %d\n", pTop->name, pTop->age);

		//出栈
		pop_LinkStack(stack);
	}

	//栈的大小
	int size = size_LinkStack(stack);

	printf("栈的大小为：%d\n", size);


	//销毁栈
	destroy_LinkStack(stack);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}