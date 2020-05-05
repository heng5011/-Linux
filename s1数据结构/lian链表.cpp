/*************************************************************************
	> File Name: lian链表.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 27 Apr 2019 09:48:19 AM CST
 ************************************************************************/

#include <iostream>
#include<ctime>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
}Node, *Linklist;

Node *init(int value) {
    Node *p = (Node *)malloc(sizeof(Node)); //强制类型转换为Node* malloc为viod型
    p->data = value;
    p->next = NULL;
    return p;
}

Linklist insert(Linklist head, Node *node, int index) {
    if (head == NULL) {
        if (index != 0) {
            printf("index error\n");
            return head;
        }
        head = node;
        return head;
    }
    if(index == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        return head;
    } // 找到链表位置
// 未找到
    return head;
}
void output(Linklist head) {
    if(head == NULL) {
        return ;
    }
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
Linklist delete_node(Linklist head, int index) {
    if(head == NULL) {
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while(current_node != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1 && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
        return head;
    } // 找到链表位置
    return head;
}

void clear(Linklist head) {
    if (head == NULL) {
        return ;
    }
    Node *current_node = head;
    while(current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
    return ;
}

Linklist reverse(Linklist head) {
    if (head == NULL) {
        return head;
    }
    Node *current_node, *next_node;
    current_node = head->next;
    head->next = NULL;
    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head;
        head = current_node;
        current_node = next_node;
    }
    return head;
}

int main() {
    Linklist linklist = NULL;
    Node *p = init(89);
    linklist = insert(linklist,p,0);
    output(linklist);
    printf("%.8f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

