#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LinkNode
{
	//ֻά��ָ����
	struct LinkNode * next;
};

struct LList
{
	struct LinkNode pHeader; //����ͷ�ڵ�
	int m_Size; //������
};

typedef void * LinkList;
//��ʼ������
LinkList init_LinkList()
{
	struct LList * myList = malloc(sizeof(struct LList));


	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.next = NULL;

	myList->m_Size = 0; 

	return myList;
}


//��������
void insert_LinkList(LinkList list, int pos , void * data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList * mylist = list;

	if (pos < 0 || pos >mylist->m_Size - 1)
	{
		pos = mylist->m_Size; // ��Чλ�� ����β��
	}

	//���û������� ǰ4���ֽ�תΪ LinkNode����
	struct LinkNode * myNode = data;

	//�ҵ��������ݵ�ǰ���ڵ�λ��
	struct LinkNode * pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//����ָ���ָ��
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//����������
	mylist->m_Size++;
	
}

//��������
void foreach_LinkList(LinkList list , void (*myForeach)(void *))
{
	if (list == NULL)
	{
		return;
	}

	struct LList * myList = list;

	struct LinkNode * node = myList->pHeader.next; //��һ�������ݵĽڵ�

	for (int i = 0; i < myList->m_Size;i++)
	{
		myForeach(node);
		node = node->next;
	}
}

//ɾ������  ��λ��ɾ��
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList * myList = list;
	if (pos < 0 || pos > myList->m_Size - 1)
	{
		return;
	}

	//�ҵ�ɾ��λ�õ�ǰ���ڵ�λ��
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos;i ++)
	{
		pCurrent = pCurrent->next;
	}

	//��¼��ɾ���Ľڵ�
	struct LinkNode * pDel = pCurrent->next;

	//����ָ���ָ��
	pCurrent->next = pDel->next;

	//free(pDel); //�����������ǲ�ά��������ģ�д��free���������

	//����������
	myList->m_Size--;

}

//��������
void destroy_LinkList(LinkList list )
{
	if (list == NULL)
	{
		return;
	}

	free(list);
	list = NULL;

}






//����
struct Person
{
	struct LinkNode node; // Լ���õ�ǰ�ĸ��ֽڸ��ײ�����ʹ��
	char name[64];
	int age;
};

void printPerson(void * data)
{
	struct Person * p = data;
	printf("����: %s ����: %d\n", p->name, p->age);
}


void test01()
{
	//��ʼ��
	LinkList mylist = init_LinkList();

	//׼��������
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 0, &p3);
	insert_LinkList(mylist, 1, &p4);
	insert_LinkList(mylist, 100, &p5);
	// ccc ddd bbb aaa  eee

	//��������
	foreach_LinkList(mylist, printPerson);

	//����ɾ������
	removeByPos_LinkList(mylist, 2);

	printf("------------------\n");
	
	foreach_LinkList(mylist, printPerson);


	//struct Person p = { "aaa", 10 };

	//removeByValue_LinkList(mylist, &p , myCompare);

	destroy_LinkList(mylist);
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}