#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"
struct BinaryNode
{
	char ch; //数据域
	struct BinaryNode * lChild; //左孩子节点
	struct BinaryNode * rChild; //右孩子节点
	//标示
	int flag;
};
/*
	1、将根节点 压入栈中
	2、只要 栈size> 0  执行循环
		2.1 拿出栈顶元素
		2.2 如果栈顶元素的标志位 真    直接输出  执行下一次循环
		2.3 如果不是真 该flag的标志位真
		2.4 将  右子节点  和 左子节点  和 根 入栈
		2.5 执行下一次循环
*/

void nonRecursion(struct BinaryNode * root)
{
	//初始栈
	seqStack myStack = init_SeqStack();

	push_SeqStack(myStack, root);


	while (size_SeqStack(myStack)>0)
	{
		//获取栈顶元素
		struct BinaryNode * topNode = top_SeqStack(myStack);

		//弹出栈顶
		pop_SeqStack(myStack);

		//如果栈顶元素的标志位 真    直接输出  执行下一次循环
		if (topNode->flag == 1)
		{
			printf("%c ", topNode->ch);
			continue;
		}
		//如果不是真 该flag的标志位真
		topNode->flag = 1;
		//将  右子节点  和 左子节点  和 根 入栈
		if (topNode->rChild != NULL)
		{
			push_SeqStack(myStack, topNode->rChild);
		} 

		if (topNode->lChild != NULL)
		{
			push_SeqStack(myStack, topNode->lChild);
		}

		push_SeqStack(myStack,topNode);
	}

	//栈销毁掉
	destroy_SeqStack(myStack);
	myStack = NULL;
}

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL, 0 };
	struct BinaryNode nodeB = { 'B', NULL, NULL, 0 };
	struct BinaryNode nodeC = { 'C', NULL, NULL, 0 };
	struct BinaryNode nodeD = { 'D', NULL, NULL, 0 };
	struct BinaryNode nodeE = { 'E', NULL, NULL, 0 };
	struct BinaryNode nodeF = { 'F', NULL, NULL, 0 };
	struct BinaryNode nodeG = { 'G', NULL, NULL, 0 };
	struct BinaryNode nodeH = { 'H', NULL, NULL, 0 };

	//建立结点之间的关系

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//执行非递归遍历
	nonRecursion(&nodeA);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}