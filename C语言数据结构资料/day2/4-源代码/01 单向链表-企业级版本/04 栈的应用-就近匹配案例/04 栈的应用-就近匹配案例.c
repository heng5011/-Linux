#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

/*
从第一个字符开始扫描
当遇见普通字符时忽略，
当遇见左括号时压入栈中
当遇见右括号时从栈中弹出栈顶符号，并进行匹配
匹配成功：继续读入下一个字符
匹配失败：立即停止，并报错
结束：
成功: 所有字符扫描完毕，且栈为空
失败：匹配失败或所有字符扫描完毕但栈非空
*/

//判断字符是否是左括号
int IsLeft(char ch)
{
	return ch == '(';
}

//判断字符是否是右括号
int IsRight(char ch)
{
	return ch == ')';
}

void printError(char * str, char * errMsg,char * pos)
{
	printf("错误的信息：%s\n", errMsg);
	printf("%s\n", str);

	//计算打印空格数量
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

	//初始化栈
	seqStack stack  =  init_SeqStack();

	while ( *p != '\0')
	{
		//如果是左括号  入栈
		if (IsLeft(*p))
		{
			push_SeqStack(stack, p);
		}
		//如果是右括号  弹出栈中的栈顶元素
		if (IsRight(*p))
		{
			//如果栈的元素个数>0 说明 可以匹配
			if (size_SeqStack(stack)>0)
			{
				//弹出栈顶元素
				pop_SeqStack(stack);
			}
			else //空栈  匹配失败
			{
				printError(str, "右括号没有匹配到左括号",p);
				break;
			}
		}
		p++;
	}

	//判断栈是否为空栈
	while ( size_SeqStack(stack) > 0)
	{
		printError(str, "左括号没有匹配到右括号", top_SeqStack(stack));
		//弹出栈顶元素
		pop_SeqStack(stack);
	}

	//销毁栈
	destroy_SeqStack(stack);
	stack = NULL;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}