#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//链表结点
struct LinkNode
{
	void * data; //数据域
	struct LinkNode * next; //指针域
};

//链表结构体
struct LList
{
	struct LinkNode pHeader; //头节点
	int m_Size; //链表长度
};

typedef void * LinkList;

//初始化链表
LinkList init_LinkList()
{
	struct LList * myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	//初始化链表结构体
	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->m_Size = 0;
	return myList;
}

//插入结点
void insert_LinkList(LinkList list,int pos , void * data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList * myList = list;


	if (pos < 0 || pos >myList->m_Size)
	{
		//无效位置进行尾插
		pos = myList->m_Size;
	}

	//创建临时节点
	struct LinkNode * pCurrent = &myList->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}
	//通过循环 找到 插入位置的前驱节点

	//创建出新节点
	 struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	 newNode->data = data;
	 newNode->next = NULL;
	
	 //将新节点 插入到 链表中
	 newNode->next = pCurrent->next;
	 pCurrent->next = newNode;

	 myList->m_Size++; //更新链表的长度

}

//遍历链表
void foreach_LinkList(LinkList list , void(*myPrint)(void *) )
{
	if (list == NULL)
	{
		return;
	}

	struct LList * myList = list;

	struct LinkNode * pCurrent = myList->pHeader.next; //找到第一个有数据的节点
	for (int i = 0; i < myList->m_Size;i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}


//删除结点 -- 按位置 进行删除
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * myList = list;

	if (pos < 0 || pos >myList->m_Size-1)
	{
		return;
	}

	//找到删除节点的前驱节点
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos;i ++)
	{
		pCurrent = pCurrent->next;
	}


	//缓存中 待删除的节点
	struct LinkNode * pDel = pCurrent->next;

	//建立关系
	pCurrent->next = pDel->next;

	//释放掉待删除的节点
	free(pDel);
	pDel = NULL;

	//更新链表长度
	myList->m_Size--;
}


//删除节点  --- 按值进行删除
void removeByValue_LinkList(LinkList list, void * data , int (*myCompare)(void * ,void *) )
{

	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList * myList = list;

	//创建两个辅助指针变量
	struct LinkNode * pPrev = &myList->pHeader;
	struct LinkNode * pCurrent = pPrev->next;

	for (int i = 0; i < myList->m_Size;i++)
	{
		//if (pCurrent->data == data) 交给用户进行比对
		if (myCompare(pCurrent->data,data))
		{
			//更改指针指向
			pPrev->next = pCurrent->next;

			//释放掉要删除的节点
			free(pCurrent);
			pCurrent = NULL;

			myList->m_Size--;

			break;
		}
		//将两个辅助指针 后移
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//清空链表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	struct LList *myList = list;

	struct LinkNode * pCurrent = myList->pHeader.next;

	for (int i = 0; i < myList->m_Size;i++)
	{
		//先记住待删除节点的后继节点
		struct LinkNode * pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	myList->pHeader.next = NULL;
	myList->m_Size = 0;
}

//返回链表长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList * myList = list;
	return myList->m_Size;

}

//销毁链表
void destroy_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	clear_LinkList(list);

	free(list);
	list = NULL;

}











struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void * data)
{
	struct Person * p = data;
	printf("姓名： %s 年龄: %d\n", p->name, p->age);

}

int myCompare(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test01()
{
	//初始化链表
	LinkList list = init_LinkList();

	//插入数据
	struct Person p1 = { "亚瑟", 18 };
	struct Person p2 = { "王昭君", 28 };
	struct Person p3 = { "赵云", 38 };
	struct Person p4 = { "张飞", 19 };
	struct Person p5 = { "关羽", 20 };
	struct Person p6 = { "宫本", 17 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, 0, &p4);
	insert_LinkList(list, 1, &p5);
	insert_LinkList(list, 100, &p6);

	//  张飞  关羽 王昭君 赵云 亚瑟  宫本
	printf("链表的长度为：%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);


	//删除赵云
	removeByPos_LinkList(list, 3);
	printf("-------------------------\n");
	printf("链表的长度为：%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);

	//删除关羽
	struct Person p = { "关羽", 20 };
	removeByValue_LinkList(list, &p, myCompare);

	printf("-------------------------\n");
	printf("链表的长度为：%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);

	//清空链表
	clear_LinkList(list);

	printf("-------------------------\n");
	printf("链表的长度为：%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);

	//销毁链表
	destroy_LinkList(list);
	
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}