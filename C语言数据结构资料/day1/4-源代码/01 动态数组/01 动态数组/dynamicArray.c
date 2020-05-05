#include "dynamicArray.h"


//初始化数组
struct dynamicArray * init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct dynamicArray * array = malloc(sizeof(struct dynamicArray));

	//判断内存是否申请成功
	if (array == NULL)
	{
		return  NULL;
	}

	//设置容量
	array->m_capacity = capacity;
	//设置大小
	array->m_size = 0;
	//维护在堆区数组的指针
	array->pAddr = malloc(sizeof(void*)*array->m_capacity);

	return array;
}

//插入功能
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
		//无效的位置  进行尾插
		pos = array->m_size;
	}

	//先判断是否已经 满载 ，如果满载了  动态开辟
	if (array->m_size >= array->m_capacity)
	{
		//1、申请一个更大的内存空间
		int newCapacity = array->m_capacity * 2;

		//2、创建新空间
		void ** newSpace = malloc(sizeof(void *)* newCapacity);

		//3、将原有数据 拷贝到新空间下
		memcpy(newSpace, array->pAddr, sizeof(void*)*array->m_capacity);

		//4、释放原有空间
		free(array->pAddr);

		//5、更改指针指向
		array->pAddr = newSpace;
		//6、更新新容量大小
		array->m_capacity = newCapacity;

	}

	//插入新数据元素
	//从最后一个位置开始 依次移动数据  后移

	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	//将新元素插入到指定位置
	array->pAddr[pos] = data;

	//更新大小
	array->m_size++;
}


//遍历数组
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

//删除数组中元素  -- 按照指定位置进行删除
void removeByPos_DynamicArray(struct dynamicArray * arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos < 0 || pos > arr->m_size - 1)
	{
		//无效的位置 直接return
		return;
	}

	//从pos位置开始  到数组尾  数据进行前移
	for (int i = pos; i < arr->m_size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->m_size--;
}

//删除数组中的元素  --- 按照值来进行删除
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

//销毁数组
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

