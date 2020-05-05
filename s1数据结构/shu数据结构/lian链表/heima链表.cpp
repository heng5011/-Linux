/*************************************************************************
	> File Name: heima链表.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年06月03日 星期一 18时54分58秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct _LINKNODE {
    int data;
    struct _LINKNODE *next;
} link_node;

link_node *init_linklist () {
    //创建头结点指针
    link_node *head = NULL;
    //给头结点分配内存
    head = (link_node *) malloc (sizeof (link_node));
    if (head == NULL) {
        return NULL;
    }
    head -> data = -1;
    head -> next = NULL;
    
    //保存当前结点
    link_node * p_current = head;
    int data = -1;
    //循环向链表中插入结点
    while (1) {
        printf ("please input data: \n");
        scanf("%d", &data);

        //如果输入-1，则退出循环
        if (data == -1) {
            break;
        }

        //给新结点分配内存
        link_node * newnode = (link_node *) malloc (sizeof (link_node));
        if (newnode == NULL) {
            break;
        }

        //给结点赋值
        newnode -> data = data;
        newnode -> next = NULL;

        //新结点入链表，　也就是将结点插入到最后一个结点的下一个位置
        p_current -> next = newnode;
        //更新辅助指针 p_current
        p_current = newnode;
    }
    return head;
}

//遍历链表
void foreach_linklist (link_node * head) {
    if (head == NULL) {
        return ;
    }

    //赋值指针变量
    link_node * p_current = head -> next;
    while (p_current != NULL) {
        printf ("%d", p_current -> data);
        p_current = p_current -> next;
    }
    printf ("\n");
}

//在值val前插入结点
void insert_linklist (link_node * head, int val, int data) {
    if (head == NULL) {
        return ;
    }

    //两个辅助指针
    link_node * p_prev = head;
    link_node * p_current = p_prev -> next;
    while (p_current != NULL) {
        if (p_current -> data == val) {
            break;
        }
        p_prev = p_current;
        p_current = p_prev -> next;
    }

    //如果p_current为NULL,说明不存在值为val的结点
    if (p_current == NULL) {
        printf ("不存在值为%d的结点！\n", val);
        return ;
    }

    //创建新的结点
    link_node * newnode = (link_node *) malloc (sizeof (link_node));
    newnode -> data = data;
    newnode -> next = NULL;

    //新结点入链表
    newnode -> next = p_current;
    p_prev -> next = newnode;
}

//删除值为val的结点
void remove_linklist (link_node * head, int val) {
    if (head == NULL) {
        return ;
    }

    //辅助指针
    link_node * p_prev = head;
    link_node * p_current = p_prev -> next;

    //查找值为val的结点
    while (p_current != NULL) {
        if (p_current -> data == val) {
            break;
        }
        p_prev = p_current;
        p_current = p_prev -> next;
    }
    //如果p_current为NULL, 表示没有找到
    if (p_current == NULL) {
        return ;
    }

    //删除当前结点：重新建立待删除结点(p_current)的前驱后继结点关系
    p_prev -> next = p_current -> next;
    //释放待删除结点的内存
    free (p_current);
}

//销毁链表
void destory_linklist (link_node * head) {
    if (head == NULL) {
        return ;
    }
    //赋值指针
    link_node * p_current = head;
    while (p_current != NULL) {
        //缓存当前结点的下一个结点
        link_node * p_next = p_current -> next;
        free(p_current);
        p_current = p_next;
    }
}


int main() {

    return 0;
}
