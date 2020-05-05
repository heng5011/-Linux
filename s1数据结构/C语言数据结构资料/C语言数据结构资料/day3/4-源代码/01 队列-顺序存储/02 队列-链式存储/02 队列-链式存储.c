#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkQueue.h"


//���Զ���
struct Person
{
	void * node;
	char name[64];
	int age;
};

void test01()
{
	//��ʼ������
	LinkQueue queue = init_LinkQueue();
	//׼������
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };
	//���
	push_LinkQueue(queue, &p1);
	push_LinkQueue(queue, &p2);
	push_LinkQueue(queue, &p3);
	push_LinkQueue(queue, &p4);
	push_LinkQueue(queue, &p5);

	while (size_LinkQueue(queue) > 0)
	{
		//��ȡ��ͷԪ��
		struct Person * pFront = front_LinkQueue(queue);
		printf("��ͷԪ��--- ������ %s  ���䣺 %d\n", pFront->name, pFront->age);

		//��ȡ��β
		struct Person * pBack = back_LinkQueue(queue);
		printf("��βԪ��--- ������ %s  ���䣺 %d\n", pBack->name, pBack->age);

		//����
		pop_LinkQueue(queue);
	}

	printf("::::�����СΪ�� %d\n", size_LinkQueue(queue));


	//����
	destroy_LinkQueue(queue);


}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}