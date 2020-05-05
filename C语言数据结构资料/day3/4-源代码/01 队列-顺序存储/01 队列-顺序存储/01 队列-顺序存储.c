#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "seqQueue.h"

//测试队列
struct Person
{
	char name[64];
	int age;
};

void test01()
{
	//初始化队列
	seqQueue queue = init_SeqQueue();
	//准备数据
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	//入队
	push_SeqQueue(queue, &p1);
	push_SeqQueue(queue, &p2);
	push_SeqQueue(queue, &p3);
	push_SeqQueue(queue, &p4);
	push_SeqQueue(queue, &p5);

	while ( size_SeqQueue(queue)>0 )
	{
		//获取队头元素
		struct Person * pFront = front_SeqQueue(queue);
		printf("队头元素--- 姓名： %s  年龄： %d\n", pFront->name, pFront->age);

		//获取队尾
		struct Person * pBack = back_SeqQueue(queue);
		printf("队尾元素--- 姓名： %s  年龄： %d\n", pBack->name, pBack->age);

		//出队
		pop_SeqQueue(queue);
	}

	printf("队伍大小为： %d\n", size_SeqQueue(queue));


	//销毁
	destroy_SeqQueue(queue);


}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}