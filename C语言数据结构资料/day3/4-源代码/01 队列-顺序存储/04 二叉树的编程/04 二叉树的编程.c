#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
	char ch; //数据域
	struct BinaryNode * lChild; //左孩子节点
	struct BinaryNode * rChild; //右孩子节点
};

//统计叶子数量
void calculateLeafNum(struct BinaryNode* root, int * num)
{
	//递归的结束条件
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

	//求出左子树的高度 
	int lHeight = getTreeHeight(root->lChild);

	int rHeight = getTreeHeight(root->rChild);

	//取左子树 和 右子树中最大值 +1 
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;


	return height;

}


struct BinaryNode * copyBinaryTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}

	//先拷贝 左子树 
	struct BinaryNode * lChild = copyBinaryTree(root->lChild);

	//再拷贝 右子树
	struct BinaryNode * rChild = copyBinaryTree(root->rChild);

	//创建新节点 
	struct BinaryNode * newNode = malloc(sizeof(struct BinaryNode));
	newNode->lChild = lChild;
	newNode->rChild = rChild;

	newNode->ch = root->ch;

	//返回给用户
	return newNode;

}


//遍历树
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

//释放树
void freeTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//先释放左子树 
	freeTree(root->lChild);
	//再释放右子树
	freeTree(root->rChild);

	printf("%c 被释放了\n", root->ch);
	//释放根节点
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

	//建立结点之间的关系

	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//1、求树中的叶子的数量
	int num = 0;
	calculateLeafNum(&nodeA, &num);
	printf("叶子的数量为:%d\n", num);

	//2、求树的高度/深度
	int height = getTreeHeight(&nodeA);

	printf("树的高度为: %d\n", height);


	//3、拷贝二叉树
	struct BinaryNode * newTree = copyBinaryTree(&nodeA);

	showBinaryTree(newTree);
	printf("\n");

	//4、释放二叉树
	freeTree(newTree);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}