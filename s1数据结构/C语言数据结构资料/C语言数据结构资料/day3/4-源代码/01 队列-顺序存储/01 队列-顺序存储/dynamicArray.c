#include "dynamicArray.h"


//��ʼ������
struct dynamicArray * init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct dynamicArray * array = malloc(sizeof(struct dynamicArray));

	//�ж��ڴ��Ƿ�����ɹ�
	if (array == NULL)
	{
		return  NULL;
	}

	//��������
	array->m_capacity = capacity;
	//���ô�С
	array->m_size = 0;
	//ά���ڶ��������ָ��
	array->pAddr = malloc(sizeof(void*)*array->m_capacity);

	return array;
}

//���빦��
void insert_dynamicArray(struct dynamicArray * array, int pos, void * data)
{
	if (array == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > array->m_size)
	{
		//��Ч��λ��  ����β��
		pos = array->m_size;
	}

	//���ж��Ƿ��Ѿ� ���� �����������  ��̬����
	if (array->m_size >= array->m_capacity)
	{
		//1������һ��������ڴ�ռ�
		int newCapacity = array->m_capacity * 2;

		//2�������¿ռ�
		void ** newSpace = malloc(sizeof(void *)* newCapacity);

		//3����ԭ������ �������¿ռ���
		memcpy(newSpace, array->pAddr, sizeof(void*)*array->m_capacity);

		//4���ͷ�ԭ�пռ�
		free(array->pAddr);

		//5������ָ��ָ��
		array->pAddr = newSpace;
		//6��������������С
		array->m_capacity = newCapacity;

	}

	//����������Ԫ��
	//�����һ��λ�ÿ�ʼ �����ƶ�����  ����

	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	//����Ԫ�ز��뵽ָ��λ��
	array->pAddr[pos] = data;

	//���´�С
	array->m_size++;
}


//��������
void foreach_DynamicArray(struct dynamicArray * array, void(*myForeach)(void *))
{

	if (array == NULL)
	{
		return;
	}
	if (myForeach == NULL)
	{
		return;
	}

	for (int i = 0; i < array->m_size; i++)
	{
		myForeach(array->pAddr[i]);
	}
}

//ɾ��������Ԫ��  -- ����ָ��λ�ý���ɾ��
void removeByPos_DynamicArray(struct dynamicArray * arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos < 0 || pos > arr->m_size - 1)
	{
		//��Ч��λ�� ֱ��return
		return;
	}

	//��posλ�ÿ�ʼ  ������β  ���ݽ���ǰ��
	for (int i = pos; i < arr->m_size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->m_size--;
}

//ɾ�������е�Ԫ��  --- ����ֵ������ɾ��
void removeByValue_DynamicArray(struct dynamicArray * arr, void * data, int(*myCompare)(void *, void *))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_size; i++)
	{
		if (myCompare(arr->pAddr[i], data))
		{
			removeByPos_DynamicArray(arr, i);
			break;
		}
	}

}

//��������
void destroy_DynamicArray(struct dynamicArray * arr)
{
	if (arr == NULL)
	{
		return;
	}

	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
		arr->pAddr = NULL;
	}

	free(arr);
	arr = NULL;
}

