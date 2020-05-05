#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

/*
�ӵ�һ���ַ���ʼɨ��
��������ͨ�ַ�ʱ���ԣ�
������������ʱѹ��ջ��
������������ʱ��ջ�е���ջ�����ţ�������ƥ��
ƥ��ɹ�������������һ���ַ�
ƥ��ʧ�ܣ�����ֹͣ��������
������
�ɹ�: �����ַ�ɨ����ϣ���ջΪ��
ʧ�ܣ�ƥ��ʧ�ܻ������ַ�ɨ����ϵ�ջ�ǿ�
*/

//�ж��ַ��Ƿ���������
int IsLeft(char ch)
{
	return ch == '(';
}

//�ж��ַ��Ƿ���������
int IsRight(char ch)
{
	return ch == ')';
}

void printError(char * str, char * errMsg,char * pos)
{
	printf("�������Ϣ��%s\n", errMsg);
	printf("%s\n", str);

	//�����ӡ�ո�����
	int num = pos - str;
	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("A\n");
}

void test01()
{
	char * str = "5+5*(6)+9/3*1-(1+3(";

	char * p = str;

	//��ʼ��ջ
	seqStack stack  =  init_SeqStack();

	while ( *p != '\0')
	{
		//�����������  ��ջ
		if (IsLeft(*p))
		{
			push_SeqStack(stack, p);
		}
		//�����������  ����ջ�е�ջ��Ԫ��
		if (IsRight(*p))
		{
			//���ջ��Ԫ�ظ���>0 ˵�� ����ƥ��
			if (size_SeqStack(stack)>0)
			{
				//����ջ��Ԫ��
				pop_SeqStack(stack);
			}
			else //��ջ  ƥ��ʧ��
			{
				printError(str, "������û��ƥ�䵽������",p);
				break;
			}
		}
		p++;
	}

	//�ж�ջ�Ƿ�Ϊ��ջ
	while ( size_SeqStack(stack) > 0)
	{
		printError(str, "������û��ƥ�䵽������", top_SeqStack(stack));
		//����ջ��Ԫ��
		pop_SeqStack(stack);
	}

	//����ջ
	destroy_SeqStack(stack);
	stack = NULL;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}