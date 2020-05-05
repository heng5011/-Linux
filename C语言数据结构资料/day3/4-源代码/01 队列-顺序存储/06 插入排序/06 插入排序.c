#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//从小到大
void insertSort(int arr[] , int len)
{
	for (int i = 1; i < len;i++)
	{
		if (arr[i] < arr[i-1])
		{
			int temp = arr[i]; //利用temp保存当前 i号位置的数据值
			int j = i - 1;
			for (; j >= 0 && temp < arr[j];j--)
			{
				//数据进行后移
				arr[j + 1] = arr[j];
			}
			//将j+1 的位置数据 赋值为 temp
			arr[j + 1] = temp;
		}

	}
}

void printArray(int arr[], int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d\n", arr[i]);
	}
}

void test01()
{
	int arr[] = { 5, 9, 6, 1, 3, 7 };
	int len = sizeof(arr) / sizeof(int);
	insertSort(arr, len);

	
	//打印数组
	printArray(arr,len);
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}