/*************************************************************************
	> File Name: LinkList.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月13日 星期六 21时21分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkList.h"

//链表结点数据类型
struct LinkNode {
    void *data;
    struct LinkNode *next;
};

//链表数据类型
struct LList {
    struct LinkNode header;
    int size;
};

typedef void * LinkList;

//初始化链表
LinkList Init_LinkList () {
    struct LList *list = malloc (sizeof (struct LList));
    if (NULL == list) {
        return NULL;
    }
    list -> header.data = NULL;
    list -> header.next = NULL;
    list -> size = 0;
    return list;
}
//插入结点
void Insert_LinkList (LinkList list, int pos, void *data) {
    if (NULL == list) {
        return ;
    } 
    if (NULL == data) {
        return ;
    }
    struct LList * mylist = (struct LList *) list;
    if (pos < 0 || pos > mylist -> size) {
        pos = mylist -> size;
    }

    //查找插入位置
    struct LinkNode *pCurrent = &mylist -> header;
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent -> next;
    }

    //创建新结点
    struct LinkNode *newnode = malloc (sizeof (struct LinkNode));
    newnode -> data = data;
    newnode -> next = NULL;

    //新结点插入到链表中
    newnode -> next = pCurrent -> next;
    pCurrent -> next = newnode;

    mylist -> size++;
}

//遍历链表
void Foreach_LinkList (LinkList list, void(* myfoach)(void *)) {
    if (NULL == list) {
        return ;
    }
    if (NULL == myfoach) {
        return ;
    }
    struct LList * mylist = (struct LList *)list;
    struct LinkNode *pCurrent = mylist -> header.next;
    while (pCurrent != NULL) {
        myfoach (pCurrent -> data);
        pCurrent = pCurrent -> next;
    } 
}

//按位置删除
void RemoveByPos_LinkList (LinkList list, int pos) {
    if (NULL == list) {
        return ;
    } 

    struct LList *mylist = (struct LList *) list;

    if (pos < 0 || pos > mylist -> size - 1) {
        return ;
    }
    
    //找位置
    struct LinkNode *pCurrent = &(mylist -> header);
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent -> next;
    }

    //先保存待删除结点
    struct LinkNode *pDel = pCurrent -> next;
    //重新建立待删除结点的前驱后继结点关系
    pCurrent -> next = pDel -> next;
    //释放删除结点内存
    free (pDel);
    pDel = NULL;

    mylist -> size--;

}

//按值删除
void RemoveByVal_LinkList (LinkList list, void *data, COMPARE compare) {
    if (NULL == list) {
        return ;
    }
    if (NULL == data) {
        return ;
    }
    if (NULL == compare) {
        return ;
    }

    struct LList *mylist = (struct LList *) list;
    
    //辅助指针变量
    struct LinkNode *pPrev = &(mylist -> header);
    struct LinkNode *pCurrent = pPrev -> next;

    while (pCurrent != NULL) {
        if (compare (pCurrent -> data, data)) {
            //找到了
            pPrev -> next = pCurrent -> next;
            //释放删除结点内存
            free(pCurrent);
            mylist -> size--;
            pCurrent = NULL;
            break;
        }

        pPrev = pCurrent;
        pCurrent = pCurrent -> next;
    }
}

//清空链表
void Clear_LinkList (LinkList list) {
    if (NULL == list) {
        return ;
    }
    
    struct LList *mylist = (struct LList *) list;

    //辅助指针变量
    struct LinkNode *pCurrent = mylist -> header.next;

    while (pCurrent != NULL) {
        //先缓存下一个结点的地址
        struct LinkNode *pNext = pCurrent -> next;
        //释放当前结点内存
        free (pCurrent);

        pCurrent = pNext;
    }
    mylist -> header.next = NULL;
    mylist -> size = 0; 
}

//大小
int Size_LinkList (LinkList list) {
    if (NULL == list) {
        return -1;
    }
    struct LList *mylist = (struct LList *) list;
    return mylist -> size;
}

//销毁链表
void Destory_LinkList (LinkList list) {
    /*if (NULL == list) {
        return ;
    }
    
    struct LList *mylist = (struct LList *) list;

    //辅助指针变量
    struct LinkNode *pCurrent = mylist -> header.next;

    while (pCurrent != NULL) {
        //先缓存下一个结点的地址
        struct LinkNode *pNext = pCurrent -> next;
        //释放当前结点内存
        free (pCurrent);

        pCurrent = pNext;
    }*/
    //清空链表
    Clear_LinkList(list);
    free (list);
    //mylist -> size = 0; 
    list = NULL;
}

<<<<<<< HEAD

=======
>>>>>>> first
