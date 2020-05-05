/*************************************************************************
	> File Name: test2.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年12月13日 星期五 20时06分18秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;

typedef char StackData,QueueData;

typedef struct node {
    StackData data;
    struct node *link;
} StackNode, QueueNode;

typedef struct linkStack {
    StackNode* top;
} LinkStack;

typedef struct {
    QueueNode *rear, *front;
} LinkQueue;

void InitStack (LinkStack *s) {
    s->top = NULL;
}

int Push (LinkStack *S, StackData x) {
    StackNode *p = (StackNode*) malloc (sizeof(StackNode));
    if(!p) return 0;
    p -> data = x;
    p -> link = S -> top;
    S -> top = p;
    return 1;
}

int Pop (LinkStack *s, StackData *x) {
    if(s == NULL || s -> top == NULL)
        return 0;
    StackNode *p = s -> top;
    *x = p -> data;
    s -> top = p -> link;
    free(p);
    return 1;
}

void InitQueue (LinkQueue *q) {
    q->rear = q->front = NULL;
}

int EnQueue (LinkQueue *Q, QueueData x) {
    QueueNode *p = (QueueNode*) malloc (sizeof (QueueNode));
    if(!p) return 0;
    p -> data = x;
    p -> link = NULL;
    if (Q -> front == NULL) {
        Q->front = Q->rear = p;
    }
    else {
        Q->rear->link = p;
    }
    Q -> rear = p;
    return 1;
}

int DeQueue (LinkQueue *Q, QueueData *x) {
    if (Q -> front == NULL) return 0;
    QueueNode *p = Q -> front;
    *x = p -> data;
    Q -> front = Q -> front -> link;
    free(p);
    return 1;
}

int main () {
    char c, data;
    char s1[MAX_SIZE];
    LinkStack s;
    LinkQueue q;
    InitQueue (&q);
    InitStack (&s);
    cin >> s1;
    /*int i = 0;
    while ((c = getchar()) != '#') {
        s1[i] = c;
        i++;
    }*/
    for (int j = 0; j < strlen(s1); j++) {
        EnQueue (&q, s1[j]);
    }
    while (DeQueue (&q, &data)) {
        if (data == 'A') {
            cout << "sae";
           // printf ("sae");
        } else if (data == 'B') {
            //printf ("tsaedsae");
            cout << "tsaedsae";
        } else if (data == '(') {
            DeQueue (&q, &data);
            char temp = data;
            DeQueue (&q, &data);
            while (data != ')') {
                Push (&s, data);
                DeQueue (&q, &data);
            }
            while (Pop(&s, &data)) {
                if (data == 'A') {
                    cout << temp << "sae";
                } else if (data == 'B') {
                    cout << temp << "tsaedsae";
                } else cout << temp << data;
            }
        } else if (data == ')') {
            DeQueue (&q, &data);
        } else
            cout << data;
    }
    cout << endl;
    return 0;
}
