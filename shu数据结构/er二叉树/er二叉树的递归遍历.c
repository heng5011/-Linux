/*************************************************************************
	> File Name: er二叉树的递归遍历.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月15日 星期日 08时39分43秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BiNode {
    char ch;
    struct BiNode *lchild;
    struct BiNode *rchild;
};

//二叉树递归遍历
void recursion (struct BiNode *root) {
    if (NULL == root) {
        return ;
    }
    
    //printf ("%c ", root -> ch);/*前序*/
    //递归遍历左子树
    recursion (root -> lchild);
    //printf ("%c ", root -> ch);/*中序*/
    //递归遍历右子树
    recursion (root -> rchild);
    printf ("%c ", root -> ch); /*后序*/

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

    recursion (&nodeA);

    printf ("\n");
}

int main () {

    test ();

    return 0;
}
