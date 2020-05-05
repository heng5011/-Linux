#pragma once 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//动态数组结构体
struct dynamicArray
{
	void ** pAddr; //维护在堆区真实数组指针

	int m_capacity; //数组容量

	int m_size; //数组大小
};



//初始化数组
struct dynamicArray * init_DynamicArray(int capacity);

//插入功能
void insert_dynamicArray(struct dynamicArray * array, int pos, void * data);


//遍历数组
void foreach_DynamicArray(struct dynamicArray * array, void(*myForeach)(void *));


//删除数组中元素  -- 按照指定位置进行删除
void removeByPos_DynamicArray(struct dynamicArray * arr, int pos);


//删除数组中的元素  --- 按照值来进行删除
void removeByValue_DynamicArray(struct dynamicArray * arr, void * data, int(*myCompare)(void *, void *));


//销毁数组
void destroy_DynamicArray(struct dynamicArray * arr);


