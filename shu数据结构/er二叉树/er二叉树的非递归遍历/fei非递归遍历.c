/*************************************************************************
	> File Name: fei非递归遍历.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月15日 星期日 20时16分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SeqStack.h"

struct BiNode {
    char ch;
    struct BiNode *lchild;
    struct BiNode *rchild;
};

struct Info {
    struct BiNode *node;
    bool flag;
};

struct Info* createInfo (struct BiNode *node, bool flag) {
    struct Info *info = malloc (sizeof (struct Info));
    info -> flag = flag;
    info -> node = node;

    return info;
}

void nonRecursion (struct BiNode *root) {
    //初始化栈
    SeqStack stack = Init_SeqStack ();
    //先把根节点压入栈中
    Push_SeqStack (stack, createInfo (root, false));

    while (Size_SeqStack (stack) > 0) {
        //获得栈顶元素
        struct Info *info = (struct Info *) Top_SeqStack (stack);
        //弹出栈顶元素
        Pop_SeqStack (stack);

        if (info -> flag) {
            printf ("%c \n", info -> node -> ch);
            free (info);
            continue;
        }
        
        //将右子树压入栈中
        if (info -> node -> rchild != NULL) {
            Push_SeqStack (stack, createInfo (info -> node -> rchild, false));
        }

        //将左子树压入栈中
        if (info -> node -> lchild != NULL) {
            Push_SeqStack (stack, createInfo (info -> node -> lchild, false));
        }
        
        //将根节点压入栈中
        info -> flag = true;
        Push_SeqStack (stack, info);
    }

    //销毁栈
    Destroy_SeqStack (stack);
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

    nonRecursion (&nodeA);
}

int main () {

    test ();

    return 0;
}
