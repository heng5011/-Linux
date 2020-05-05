/*************************************************************************
	> File Name: LinkQueue.h
	> Author: kwh
	> Mail: 
	> Created Time: 2019年10月23日 星期三 12时05分31秒
 ************************************************************************/

#ifndef _LINKSTACK_H
#define _LINKSTACK_H

#define MAXSIZE 11 // 初始容量
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10

#include "status.h"

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}Qnode, *QueuePtr;

class LinkQueue {
    private :
        //QElemType data;
        QueuePtr front;
        QueuePtr rear;
    public :
        Status InitQueue (LinkQueue &Q);
        Status DestroyQueue (LinkQueue &Q);
        Status ClearQueue (LinkQueue &Q);
        Status QueueEmpty (LinkQueue Q);
        int QueueLength (LinkQueue Q);
        Status GetHead (LinkQueue Q, QElemType &e);
        Status EnQueue (LinkQueue Q, QElemType e);
        Status DeQueue (LinkQueue &Q, QElemType &e);
        Status QueueTraverse (LinkQueue Q);//visit ());
};

#endif
