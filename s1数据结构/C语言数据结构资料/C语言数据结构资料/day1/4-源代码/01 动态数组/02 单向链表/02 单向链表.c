#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//������
struct LinkNode
{
	void * data; //������
	struct LinkNode * next; //ָ����
};

//����ṹ��
struct LList
{
	struct LinkNode pHeader; //ͷ�ڵ�
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

	//��ʼ������ṹ��
	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->m_Size = 0;
	return myList;
}

//������
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
		//��Чλ�ý���β��
		pos = myList->m_Size;
	}

	//������ʱ�ڵ�
	struct LinkNode * pCurrent = &myList->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}
	//ͨ��ѭ�� �ҵ� ����λ�õ�ǰ���ڵ�

	//�������½ڵ�
	 struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
	 newNode->data = data;
	 newNode->next = NULL;
	
	 //���½ڵ� ���뵽 ������
	 newNode->next = pCurrent->next;
	 pCurrent->next = newNode;

	 myList->m_Size++; //��������ĳ���

}

//��������
void foreach_LinkList(LinkList list , void(*myPrint)(void *) )
{
	if (list == NULL)
	{
		return;
	}

	struct LList * myList = list;

	struct LinkNode * pCurrent = myList->pHeader.next; //�ҵ���һ�������ݵĽڵ�
	for (int i = 0; i < myList->m_Size;i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}


//ɾ����� -- ��λ�� ����ɾ��
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

	//�ҵ�ɾ���ڵ��ǰ���ڵ�
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos;i ++)
	{
		pCurrent = pCurrent->next;
	}


	//������ ��ɾ���Ľڵ�
	struct LinkNode * pDel = pCurrent->next;

	//������ϵ
	pCurrent->next = pDel->next;

	//�ͷŵ���ɾ���Ľڵ�
	free(pDel);
	pDel = NULL;

	//����������
	myList->m_Size--;
}


//ɾ���ڵ�  --- ��ֵ����ɾ��
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

	//������������ָ�����
	struct LinkNode * pPrev = &myList->pHeader;
	struct LinkNode * pCurrent = pPrev->next;

	for (int i = 0; i < myList->m_Size;i++)
	{
		//if (pCurrent->data == data) �����û����бȶ�
		if (myCompare(pCurrent->data,data))
		{
			//����ָ��ָ��
			pPrev->next = pCurrent->next;

			//�ͷŵ�Ҫɾ���Ľڵ�
			free(pCurrent);
			pCurrent = NULL;

			myList->m_Size--;

			break;
		}
		//����������ָ�� ����
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}

//�������
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
		//�ȼ�ס��ɾ���ڵ�ĺ�̽ڵ�
		struct LinkNode * pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	myList->pHeader.next = NULL;
	myList->m_Size = 0;
}

//����������
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}

	struct LList * myList = list;
	return myList->m_Size;

}

//��������
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
	printf("������ %s ����: %d\n", p->name, p->age);

}

int myCompare(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test01()
{
	//��ʼ������
	LinkList list = init_LinkList();

	//��������
	struct Person p1 = { "��ɪ", 18 };
	struct Person p2 = { "���Ѿ�", 28 };
	struct Person p3 = { "����", 38 };
	struct Person p4 = { "�ŷ�", 19 };
	struct Person p5 = { "����", 20 };
	struct Person p6 = { "����", 17 };

	insert_LinkList(list, 0, &p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, 0, &p4);
	insert_LinkList(list, 1, &p5);
	insert_LinkList(list, 100, &p6);

	//  �ŷ�  ���� ���Ѿ� ���� ��ɪ  ����
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);


	//ɾ������
	removeByPos_LinkList(list, 3);
	printf("-------------------------\n");
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);

	//ɾ������
	struct Person p = { "����", 20 };
	removeByValue_LinkList(list, &p, myCompare);

	printf("-------------------------\n");
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);

	//�������
	clear_LinkList(list);

	printf("-------------------------\n");
	printf("����ĳ���Ϊ��%d\n", size_LinkList(list));
	foreach_LinkList(list, myPrintPerson);

	//��������
	destroy_LinkList(list);
	
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}