#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"
struct BinaryNode
{
	char ch; //������
	struct BinaryNode * lChild; //���ӽڵ�
	struct BinaryNode * rChild; //�Һ��ӽڵ�
	//��ʾ
	int flag;
};
/*
	1�������ڵ� ѹ��ջ��
	2��ֻҪ ջsize> 0  ִ��ѭ��
		2.1 �ó�ջ��Ԫ��
		2.2 ���ջ��Ԫ�صı�־λ ��    ֱ�����  ִ����һ��ѭ��
		2.3 ��������� ��flag�ı�־λ��
		2.4 ��  ���ӽڵ�  �� ���ӽڵ�  �� �� ��ջ
		2.5 ִ����һ��ѭ��
*/

void nonRecursion(struct BinaryNode * root)
{
	//��ʼջ
	seqStack myStack = init_SeqStack();

	push_SeqStack(myStack, root);


	while (size_SeqStack(myStack)>0)
	{
		//��ȡջ��Ԫ��
		struct BinaryNode * topNode = top_SeqStack(myStack);

		//����ջ��
		pop_SeqStack(myStack);

		//���ջ��Ԫ�صı�־λ ��    ֱ�����  ִ����һ��ѭ��
		if (topNode->flag == 1)
		{
			printf("%c ", topNode->ch);
			continue;
		}
		//��������� ��flag�ı�־λ��
		topNode->flag = 1;
		//��  ���ӽڵ�  �� ���ӽڵ�  �� �� ��ջ
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

	//ջ���ٵ�
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

	//�������֮��Ĺ�ϵ

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//ִ�зǵݹ����
	nonRecursion(&nodeA);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}