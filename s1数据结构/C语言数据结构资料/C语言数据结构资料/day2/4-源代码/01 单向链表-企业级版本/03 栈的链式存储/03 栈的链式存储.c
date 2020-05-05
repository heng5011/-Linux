#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct StackNode
{
	struct StackNode * next; //ֻά��ָ����
};

//��ʽ��ջ�ṹ��
struct LStack
{
	struct StackNode pHeader; //ͷ�ڵ�

	int m_Size; //ջ�Ĵ�С
};

typedef void * LinkStack;

//��ʼ��ջ
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

//��ջ
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

	//��ջ ���� ͷ��

	struct LStack * myStack = stack;

	//�õ��û����ݵ�ǰ�ĸ��ֽ�
	struct StackNode * myNode = data;


	//����ڵ�
	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	//����ջ�Ĵ�С
	myStack->m_Size++;
}

//��ջ
void pop_LinkStack( LinkStack stack )
{
	
	if (stack == NULL)
	{
		return;
	}

	struct LStack * myStack = stack;
	//����ǿ�ջ   ����ջ��
	if ( myStack->m_Size <= 0 )
	{
		return;
	}

	//�����һ�������ݵĽڵ�  ջ��Ԫ��
	struct StackNode * pFirst = myStack->pHeader.next;

	myStack->pHeader.next = pFirst->next;

	//����������  ջ��С
	myStack->m_Size--;
}

//����ջ��Ԫ��
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

	return myStack->pHeader.next; //����һ�������ݵĽڵ㷵�ؾͿ�����
}

//����ջ��С
int size_LinkStack(LinkStack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct LStack * myStack = stack;
	return myStack->m_Size;
}

//�ж��Ƿ�Ϊ��
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
//����
void destroy_LinkStack(LinkStack stack)
{

	if (stack == NULL)
	{
		return ;
	}
	free(stack);
	stack = NULL;
}



//����
struct Person
{
	struct StackNode node;
	char name[64];
	int age;
};
void test01()
{

	//׼��������
	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	//��ʼ��ջ
	LinkStack stack = init_LinkStack();

	//��ջ
	push_LinkStack(stack, &p1);
	push_LinkStack(stack, &p2);
	push_LinkStack(stack, &p3);
	push_LinkStack(stack, &p4);
	push_LinkStack(stack, &p5);

	while (isEmpty_LinkStack(stack) == 0) //���ջ��Ϊ��  ���з���ջ��Ԫ�أ����ҳ�ջ
	{
		struct Person  * pTop = top_LinkStack(stack); //ջ��Ԫ��

		printf("ջ��Ԫ�� ������ %s  ���䣺  %d\n", pTop->name, pTop->age);

		//��ջ
		pop_LinkStack(stack);
	}

	//ջ�Ĵ�С
	int size = size_LinkStack(stack);

	printf("ջ�Ĵ�СΪ��%d\n", size);


	//����ջ
	destroy_LinkStack(stack);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}