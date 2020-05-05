/*************************************************************************
	> File Name: test.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年12月16日 星期一 18时04分17秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
const int MAX_SIZE = 100;

typedef int Status;
typedef char SElemType;
typedef char QElemType;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXSIZE 11

class SqStack {
    private :
        SElemType *base;
        SElemType *top;
        int stacksize;
    public :
        Status InitStack (SqStack *S);
        Status Push (SqStack *S, SElemType e);
        Status Pop (SqStack *S, SElemType &e);
};

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} Qnode, *QueuePtr;

class LinkQueue {
    private :
        QueuePtr front;
        QueuePtr rear;
    public :
        Status InitQueue (LinkQueue &Q);
        Status EnQueue (LinkQueue Q, QElemType e);
        Status DeQueue (LinkQueue &Q, QElemType &e);
};

Status SqStack :: InitStack (SqStack *S) {
    base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof (SElemType));
    if (!base) exit(OVERFLOW);
    top = base;
    stacksize = STACK_INIT_SIZE;
    return OK;
}

//入栈
Status SqStack :: Push (SqStack *S, SElemType e) {
    if (top - base >= stacksize) {
        base = (SElemType *) realloc (base, (stacksize + STACK_INIT_SIZE) * sizeof (SElemType));
        if (!base) exit (OVERFLOW);
        top = base + stacksize;
        stacksize += STACKINCREMENT;
    }
    *top++ = e;
    return OK;
}

//删除栈顶元素
Status SqStack :: Pop (SqStack *S, SElemType &e) {
    if (top == base) return ERROR;
    e = * --top;
    return OK;
}

//初始化队列
Status LinkQueue :: InitQueue (LinkQueue &Q) {
    front = rear = (QueuePtr) malloc (sizeof (QNode));
    if (!front) exit (OVERFLOW);
    front -> next = NULL;
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

int main () {
    char data;
    char s1[MAX_SIZE];
    SqStack s;
    LinkQueue q;
    q.InitQueue (q);
    s.InitStack (&s);
    cout << "输入数据为:    ";
    cin >> s1;
    /*int i = 0;
    while ((c = getchar()) != '#') {
        s1[i] = c;
        i++;
    }*/
    for (int j = 0; j < strlen(s1); j++) {
        q.EnQueue (q, s1[j]);
    }
    cout << "输出为:        ";
    while (q.DeQueue (q, data)) {
        if (data == 'A') {
            cout << "sae";
           // printf ("sae");
        } else if (data == 'B') {
            //printf ("tsaedsae");
            cout << "tsaedsae";
        } else if (data == '(') {
            q.DeQueue (q, data);
            char temp = data;
            q.DeQueue (q, data);
            while (data != ')') {
                s.Push (&s, data);
                q.DeQueue (q, data);
            }
            while (s.Pop(&s, data)) {
                if (data == 'A') {
                    cout << temp << "sae";
                } else if (data == 'B') {
                    cout << temp << "tsaedsae";
                } else cout << temp << data;
            }
            cout << temp;
        } else if (data == ')') {
            q.DeQueue (q, data);
        } else
            cout << data;
    }
    cout << endl;
    return 0;
}

