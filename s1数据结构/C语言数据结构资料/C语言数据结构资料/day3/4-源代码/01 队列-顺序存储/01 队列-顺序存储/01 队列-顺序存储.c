#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "seqQueue.h"

//���Զ���
struct Person
{
	char name[64];
	int age;
};

void test01()
{
	//��ʼ������
	seqQueue queue = init_SeqQueue();
	//׼������
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	//���
	push_SeqQueue(queue, &p1);
	push_SeqQueue(queue, &p2);
	push_SeqQueue(queue, &p3);
	push_SeqQueue(queue, &p4);
	push_SeqQueue(queue, &p5);

	while ( size_SeqQueue(queue)>0 )
	{
		//��ȡ��ͷԪ��
		struct Person * pFront = front_SeqQueue(queue);
		printf("��ͷԪ��--- ������ %s  ���䣺 %d\n", pFront->name, pFront->age);

		//��ȡ��β
		struct Person * pBack = back_SeqQueue(queue);
		printf("��βԪ��--- ������ %s  ���䣺 %d\n", pBack->name, pBack->age);

		//����
		pop_SeqQueue(queue);
	}

	printf("�����СΪ�� %d\n", size_SeqQueue(queue));


	//����
	destroy_SeqQueue(queue);


}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}