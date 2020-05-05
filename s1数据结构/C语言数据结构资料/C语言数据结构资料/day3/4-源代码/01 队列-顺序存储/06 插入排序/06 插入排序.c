#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��С����
void insertSort(int arr[] , int len)
{
	for (int i = 1; i < len;i++)
	{
		if (arr[i] < arr[i-1])
		{
			int temp = arr[i]; //����temp���浱ǰ i��λ�õ�����ֵ
			int j = i - 1;
			for (; j >= 0 && temp < arr[j];j--)
			{
				//���ݽ��к���
				arr[j + 1] = arr[j];
			}
			//��j+1 ��λ������ ��ֵΪ temp
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

	
	//��ӡ����
	printArray(arr,len);
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}