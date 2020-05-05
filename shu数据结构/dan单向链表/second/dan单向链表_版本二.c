/*************************************************************************
	> File Name: dan单向链表_版本二.c
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月20日 星期六 15时25分47秒
 ************************************************************************/

/*缺点: 同一个数据(地址相同的数据)不能插入两遍*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表结点数据结构
struct LinkNode {
    struct LinkNode *next;
};

//链表结构体
struct LList {
    struct LinkNode header; //头结点
    int size;
};

typedef void * LinkList;

//初始化链表
LinkList init_LinkList () {
    struct LList *mylist = malloc (sizeof (struct LList));
    if (NULL == mylist) {
        return NULL;
    }
    mylist -> header.next = NULL;
    mylist -> size = 0;
    return mylist;
}

//插入
void Insert_LinkList (LinkList list, int position, void *data) {
    if (NULL == list) {
        return ;
    }
    if (NULL == data) {
        return ;
    }

    struct LList *mylist = (struct LList *) list;
    struct LinkNode *mynode = (struct LinkNode *) data;

    if (position < 0 || position > mylist -> size - 1) {
        position = mylist -> size;
    }

    //找位置(找到position位置的前一个位置)
    struct LinkNode *pCurrent = &(mylist -> header);
    for (int i = 0; i < position; ++i) {
        pCurrent = pCurrent -> next;
    }

    //数据入链表
    mynode -> next = pCurrent -> next;
    pCurrent -> next = mynode;

    mylist -> size++;
}

//遍历
void foreach_LinkList (LinkList list, void (*myforeach)(void *)) {
    if (NULL == list) {
        return ;
    }
    if (NULL == myforeach) {
        return ;
    }
    
    struct LList *mylist = (struct LList *) list;
    struct LinkNode *pCurrent = mylist -> header.next;
    while (pCurrent != NULL) {
        struct LinkNode *pNext = pCurrent -> next;
        myforeach (pCurrent);
        pCurrent = pNext;
    }
}

//删除结点
void RemoveByPos_LinkList (LinkList list, int position) {
    if (NULL == list) {
        return ;
    }
    struct LList *mylist = (struct LList *)list;
    if (position < 0 || position > mylist -> size - 1) {
        return ;
    }
    
    //辅助指针
    struct LinkNode *pCurrent = &(mylist -> header);
    for (int i = 0; i < position; ++i) {
        pCurrent = pCurrent -> next;
    }

    //缓存下待删除结点
    struct LinkNode *pDel = pCurrent -> next;
    //重新建立待删除结点的前驱后继结点关系
    pCurrent -> next = pDel -> next;
    mylist -> size--;
}

void Destory_LinkList (LinkList list) {
    if (NULL == list) {
        return ;
    }
   free (list);
    list = NULL;
}

struct Person {
    struct LinkNode node; 
    //struct LinkNode *node; //结构体应该指针？？//理解错
    char name[64];
    int age;
};

void myPrint (void *data) {
    struct Person *person = (struct Person *) data;
    printf ("Name:%s Age:%d\n", person -> name, person -> age);
}

void test () {
    //初始化链表
    LinkList list = init_LinkList ();

    //创建数据
    struct Person p1 = {NULL, "aaa", 10};
    struct Person p2 = {NULL, "bbb", 20};
    struct Person p3 = {NULL, "ccc", 30};
    struct Person p4 = {NULL, "ddd", 40};
    struct Person p5 = {NULL, "eee", 50};
    struct Person p6 = {NULL, "fff", 60};

    //插入数据
    Insert_LinkList (list, 0, &p1);
    Insert_LinkList (list, 0, &p2);
    Insert_LinkList (list, 0, &p3);
    Insert_LinkList (list, 0, &p4);
    Insert_LinkList (list, 0, &p5);
    Insert_LinkList (list, 0, &p6);

    //遍历
    foreach_LinkList (list, myPrint);

    //删除
    RemoveByPos_LinkList (list, 3);
    printf ("------------------\n");

    //遍历
    foreach_LinkList (list, myPrint);

    //销毁
    Destory_LinkList (list);
}

int main() {

    test ();

    return 0;
}
