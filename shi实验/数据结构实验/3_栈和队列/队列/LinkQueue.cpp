/*************************************************************************
	> File Name: LinkQueue.cpp
	> Author: kwh
	> Mail: 
	> Created Time: 2019年10月23日 星期三 12时00分11秒
 ************************************************************************/

#include <iostream>
#include "LinkQueue.h"
using namespace std;

//初始化队列
Status LinkQueue :: InitQueue (LinkQueue &Q) {
    front = rear = (QueuePtr) malloc (sizeof (QNode));
    if (!front) exit (OVERFLOW);
    front -> next = NULL;
    return OK;
}

//销毁队列
Status LinkQueue :: DestroyQueue (LinkQueue &Q) {
    while (front) {
        rear = front -> next;
        free (front);
        front = rear;
    }
    return OK;
}

//清空
Status LinkQueue :: ClearQueue (LinkQueue &Q) {
    front = rear = NULL;
    return OK;
}

//判断是否为空队列
Status LinkQueue :: QueueEmpty (LinkQueue Q) {
    //(front == rear) ? (return OK) : (return ERROR); 
    if (front == rear) return TRUE;
    else return FALSE;
}

//队长
int LinkQueue :: QueueLength (LinkQueue Q) {
    int length = 0;
    QNode *p = front;
    while (p != rear) {
        length++;
        p = p -> next;
    } 
    return length;
    //cout << length;
}

//获得队头
Status LinkQueue :: GetHead (LinkQueue Q, QElemType &e) {
    if (front == rear) return ERROR;
    QNode *p = front;
    e = p -> data;
    //e = data[front];
    return OK;
}

//入队
Status LinkQueue :: EnQueue (LinkQueue Q, QElemType e) {
    
    QNode *p = (QueuePtr) malloc (sizeof (QNode));
    if (!p) exit (OVERFLOW);
    p -> data = e;
    p -> next = NULL;
    rear -> next = p;
    rear = p;
    return OK;
}

//出队
Status LinkQueue :: DeQueue (LinkQueue &Q, QElemType &e) {
    if (front == rear) return ERROR;
    QNode *p = front -> next;
    e = p -> data;
    front -> next = p -> next;
    if (rear == p) rear = front;
    free (p);
    return OK;
}

Status LinkQueue :: QueueTraverse (LinkQueue Q) {
    if (QueueEmpty (Q) == TRUE) {
        printf ("此队列为空! \n");
        exit (ERROR);
    }
    //exit (ERROR);
    QNode *p = front;
    printf ("将队列中的所有元素出队：\n");
    while (p != rear) {
        p = p -> next;
        printf ("%d ", p -> data);
    }
    printf ("\n");
}

