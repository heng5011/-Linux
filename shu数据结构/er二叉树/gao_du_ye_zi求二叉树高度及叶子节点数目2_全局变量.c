/*************************************************************************
	> File Name: gao_du_ye_zi求二叉树高度及叶子节点数目.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月15日 星期日 09时19分49秒
 ************************************************************************/

#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

struct BiNode {
    char ch;
    struct BiNode *lchild;
    struct BiNode *rchild;
};

int num = 0;/*num 未封装, 不安全*/

void cuculateLeafNum (struct BiNode *root) {
    if (NULL == root) {
        return ;
    }

    if (root -> lchild == NULL && root -> rchild == NULL) {
        num++;
    }

    cuculateLeafNum (root -> lchild);
    cuculateLeafNum (root -> rchild);

}

void test () {
    struct BiNode nodeA = {'A', NULL, NULL};
    struct BiNode nodeB = {'B', NULL, NULL};
    struct BiNode nodeC = {'C', NULL, NULL};
    struct BiNode nodeD = {'D', NULL, NULL};
    struct BiNode nodeE = {'E', NULL, NULL};
    struct BiNode nodeF = {'F', NULL, NULL};
    struct BiNode nodeG = {'G', NULL, NULL};
    struct BiNode nodeH = {'H', NULL, NULL};

    nodeA.lchild = &nodeB;
    nodeA.rchild = &nodeF;

    nodeB.rchild = &nodeC;

    nodeC.lchild = &nodeD;
    nodeC.rchild = &nodeE;

    nodeF.rchild = &nodeG;

    nodeG.lchild = &nodeH;

    //1.　求二叉树的叶子节点数目
    cuculateLeafNum(&nodeA);

    printf ("叶子节点数目:%d\n", num);
}

int main () {

    test();

    return 0;
}
