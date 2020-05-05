#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"
////��̬����ṹ��
//struct dynamicArray
//{
//	void ** pAddr; //ά���ڶ�����ʵ����ָ��
//
//	int m_capacity; //��������
//
//	int m_size; //�����С
//};
//
//
////��ʼ������
//struct dynamicArray * init_DynamicArray(int capacity)
//{
//	if (capacity <= 0 )
//	{
//		return NULL;
//	}
//
//	struct dynamicArray * array = malloc(sizeof(struct dynamicArray));
//
//	//�ж��ڴ��Ƿ�����ɹ�
//	if (array == NULL)
//	{
//		return  NULL;
//	}
//
//	//��������
//	array->m_capacity = capacity;
//	//���ô�С
//	array->m_size = 0;
//	//ά���ڶ��������ָ��
//	array->pAddr = malloc(sizeof(void*)*array->m_capacity);
//
//	return array;
//}
//
////���빦��
//void insert_dynamicArray(struct dynamicArray * array , int pos , void * data)
//{
//	if (array == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	if (pos < 0 || pos > array->m_size)
//	{
//		//��Ч��λ��  ����β��
//		pos = array->m_size;
//	}
//
//	//���ж��Ƿ��Ѿ� ���� �����������  ��̬����
//	if (array->m_size >= array->m_capacity)
//	{
//		//1������һ��������ڴ�ռ�
//		int newCapacity = array->m_capacity * 2;
//
//		//2�������¿ռ�
//		void ** newSpace = malloc(sizeof(void *)* newCapacity);
//		
//		//3����ԭ������ �������¿ռ���
//		memcpy(newSpace, array->pAddr, sizeof(void*)*array->m_capacity);
//
//		//4���ͷ�ԭ�пռ�
//		free(array->pAddr);
//
//		//5������ָ��ָ��
//		array->pAddr = newSpace;
//		//6��������������С
//		array->m_capacity = newCapacity;
//
//	}
//
//	//����������Ԫ��
//	//�����һ��λ�ÿ�ʼ �����ƶ�����  ����
//
//	for (int i = array->m_size - 1; i >= pos;i--)
//	{
//		array->pAddr[i + 1] = array->pAddr[i];
//	}
//
//	//����Ԫ�ز��뵽ָ��λ��
//	array->pAddr[pos] = data;
//
//	//���´�С
//	array->m_size++;
//}
//
//
////��������
//void foreach_DynamicArray(struct dynamicArray * array , void(*myForeach)(void *))
//{
//
//	if (array == NULL)
//	{
//		return;
//	}
//	if (myForeach == NULL)
//	{
//		return;
//	}
//
//	for (int i = 0; i < array->m_size;i++)
//	{
//		myForeach(array->pAddr[i]);
//	}
//}
//
////ɾ��������Ԫ��  -- ����ָ��λ�ý���ɾ��
//void removeByPos_DynamicArray(struct dynamicArray * arr, int pos)
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//	if (pos < 0 || pos > arr->m_size-1)
//	{
//		//��Ч��λ�� ֱ��return
//		return;
//	}
//
//	//��posλ�ÿ�ʼ  ������β  ���ݽ���ǰ��
//	for (int i = pos; i < arr->m_size - 1; i++)
//	{
//		arr->pAddr[i] = arr->pAddr[i + 1];
//	}
//
//	arr->m_size--;
//}
//
////ɾ�������е�Ԫ��  --- ����ֵ������ɾ��
//void removeByValue_DynamicArray(struct dynamicArray * arr, void * data , int(*myCompare)(void *,void *))
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//
//	for (int i = 0; i < arr->m_size;i++)
//	{
//		if (myCompare(arr->pAddr[i],data))
//		{
//			removeByPos_DynamicArray(arr, i);
//			break;
//		}
//	}
//
//}
//
////��������
//void destroy_DynamicArray(struct dynamicArray * arr)
//{
//	if (arr==NULL)
//	{
//		return;
//	}
//
//	if (arr->pAddr != NULL)
//	{
//		free(arr->pAddr);
//		arr->pAddr = NULL;
//	}
//
//	free(arr);
//	arr = NULL;
//}
//
//
//









struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void * data)
{
	struct Person * p = data;
	printf("������%s ����%d\n", p->name, p->age);
}

int myComparePerson(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}


void test01()
{
	//������̬����
	struct dynamicArray * arr = init_DynamicArray(5);

	//׼����5��person����
	struct Person p1 = { "��ɪ", 18 };
	struct Person p2 = { "���Ѿ�", 28 };
	struct Person p3 = { "����", 38 };
	struct Person p4 = { "�ŷ�", 19 };
	struct Person p5 = { "����", 20 };
	struct Person p6 = { "����", 17 };

	//�����ݲ��뵽��̬������

	printf("��ǰ������Ϊ:%d\n", arr->m_capacity);

	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);


	//  ����  ����  ���Ѿ�  �ŷ� ��ɪ  ���� 

	//������̬����
	foreach_DynamicArray(arr, myPrintPerson);

	printf("�������ݺ������Ϊ:%d\n", arr->m_capacity);

	
	//ɾ�������е�Ԫ��
	removeByPos_DynamicArray(arr, 1);

	printf("ɾ����һ��λ�õ�Ԫ�غ�����������Ϊ��\n");
	foreach_DynamicArray(arr, myPrintPerson);

	struct Person p = { "�ŷ�", 19 };

	removeByValue_DynamicArray(arr, &p, myComparePerson);

	printf("-----------------------------------\n");
	foreach_DynamicArray(arr, myPrintPerson);

	//��������
	destroy_DynamicArray(arr);
	arr = NULL;

}



int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}