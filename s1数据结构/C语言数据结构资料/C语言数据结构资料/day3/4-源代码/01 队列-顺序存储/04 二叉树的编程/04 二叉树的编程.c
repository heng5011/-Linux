#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
	char ch; //������
	struct BinaryNode * lChild; //���ӽڵ�
	struct BinaryNode * rChild; //�Һ��ӽڵ�
};

//ͳ��Ҷ������
void calculateLeafNum(struct BinaryNode* root, int * num)
{
	//�ݹ�Ľ�������
	if (root == NULL)
	{
		return;
	}

	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*num)++;
	}

	calculateLeafNum(root->lChild, num);
	calculateLeafNum(root->rChild, num);
}

int getTreeHeight(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return 0;
	}

	//����������ĸ߶� 
	int lHeight = getTreeHeight(root->lChild);

	int rHeight = getTreeHeight(root->rChild);

	//ȡ������ �� �����������ֵ +1 
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;


	return height;

}


struct BinaryNode * copyBinaryTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//�ȿ��� ������ 
	struct BinaryNode * lChild = copyBinaryTree(root->lChild);

	//�ٿ��� ������
	struct BinaryNode * rChild = copyBinaryTree(root->rChild);

	//�����½ڵ� 
	struct BinaryNode * newNode = malloc(sizeof(struct BinaryNode));
	newNode->lChild = lChild;
	newNode->rChild = rChild;

	newNode->ch = root->ch;

	//���ظ��û�
	return newNode;

}


//������
void showBinaryTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->ch);

	showBinaryTree(root->lChild);
	showBinaryTree(root->rChild);
}

//�ͷ���
void freeTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//���ͷ������� 
	freeTree(root->lChild);
	//���ͷ�������
	freeTree(root->rChild);

	printf("%c ���ͷ���\n", root->ch);
	//�ͷŸ��ڵ�
	free(root);
}

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	//�������֮��Ĺ�ϵ

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//1�������е�Ҷ�ӵ�����
	int num = 0;
	calculateLeafNum(&nodeA, &num);
	printf("Ҷ�ӵ�����Ϊ:%d\n", num);

	//2�������ĸ߶�/���
	int height = getTreeHeight(&nodeA);

	printf("���ĸ߶�Ϊ: %d\n", height);


	//3������������
	struct BinaryNode * newTree = copyBinaryTree(&nodeA);

	showBinaryTree(newTree);
	printf("\n");

	//4���ͷŶ�����
	freeTree(newTree);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}