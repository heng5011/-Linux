/*************************************************************************
	> File Name: 4.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 09时49分10秒
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

typedef int Status;
typedef char SElemType;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

class SqStack {
    private :
        SElemType *base;
        SElemType *top;
        int stacksize;
    public :
        Status InitStack (SqStack *S);
        Status StackEmpty (SqStack *S);
        Status GetTop (SElemType &e);
        Status Push (SqStack *S, SElemType e);
        Status Pop (SqStack *S, SElemType &e);
};

typedef int SElemType_1;

class SqStack_1 {
    private :
        int *base;
        int *top;
        int stacksize;
    public :
        Status InitStack_1 (SqStack_1*S);
        Status GetTop_1 (SqStack_1 *S, SElemType_1 &e);
        Status Push_1 (SqStack_1 *S, SElemType_1 e);
        Status Pop_1 (SqStack_1 *S, SElemType_1 &e);
}; //分号

//初始化
Status SqStack_1 :: InitStack_1 (SqStack_1 *S) {
    base = (SElemType_1 *) malloc (STACK_INIT_SIZE * sizeof (SElemType_1));
    if (!base) exit(OVERFLOW);
    top = base;
    stacksize = STACK_INIT_SIZE;
    return OK;
}

Status SqStack_1 :: GetTop_1 (SqStack_1 *S, SElemType_1 &e) {
    if (top == base) return ERROR;
    e = *(top - 1);
    return OK;
}

//入栈
Status SqStack_1 :: Push_1 (SqStack_1 *S_1, SElemType_1 e) {
    if (top - base >= stacksize) {
        base = (SElemType_1 *) realloc (base, (stacksize + STACK_INIT_SIZE) * sizeof (SElemType_1));
        if (!base) exit (OVERFLOW);
        top = base + stacksize;
        stacksize += STACKINCREMENT;
    }
    *top++ = e;
    return OK;
}

//删除栈顶元素
Status SqStack_1 :: Pop_1 (SqStack_1 *S_1, SElemType_1 &e) {
    if (top == base) return ERROR;
    e = * --top;
    return OK;
}

/***************************************************************************/

//初始化
Status SqStack :: InitStack (SqStack *S) {
    base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof (SElemType));
    if (!base) exit(OVERFLOW);
    top = base;
    stacksize = STACK_INIT_SIZE;
    return OK;
}

//判断是否为空栈
Status SqStack :: StackEmpty (SqStack *S) {
    if (base == top) return TRUE;
    else return FALSE;
}

Status SqStack :: GetTop (SElemType &e) {
    if (top == base) return ERROR;
    e = *(top - 1);
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

int fun (char x, int a, int b) {
    double num;
    switch (x) {
        case '+' : num = b + a; break;
        case '-' : num = b - a; break;
        case '*' : num = b * a; break;
        case '/' : num = b / a; break;
        default : break;
    }
    return num;
}

int prio (char op) {
    int priority;
    if (op == '*' || op == '/') {
        priority = 2;
    }
    if (op == '+' || op == '-') {
        priority = 1;
    }
    if (op == '(') {
        priority = 0;
    }
    return priority;
}

char data;

int main() {
    SqStack s;
    s.InitStack(&s); //定义后不要忘了初始化!!!!!!!!!!!
    SqStack_1 str1;
    str1.InitStack_1(&str1);
    string s1, s2;
    cin >> s1;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '/' && s1[i + 1] == '0') {
            cout << "输入错误!" << endl; exit(0);
        }
    }

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= '0' && s1[i] <= '9') {
            if (s1[i + 1] > '9' || s1[i + 1] < '0') {
                s2 += s1[i];
                s2 += ' ';
            } else {
                s2 += s1[i];
            } 
        } else {
            if (s.StackEmpty(&s)) {
                s.Push (&s, s1[i]);
            } else if (s1[i] == '(') {
                s.Push(&s, s1[i]);
            } else if (s1[i] == ')') {
                while (s.Pop(&s, data)) {
                    if (data == '(') break;
                    //s2 = s2 + s.top() + ' ';
                    s2 += data;//GetTop(s, data);
                    s2 += ' ';
                }
            } else {
                s.GetTop(data);
                while (prio(s1[i]) <= prio(data)) {
                    s2 = s2 + data + ' ';//GetTop(s, data) + ' ';
                    s.Pop(&s, data);
                    if (s.StackEmpty(&s)) break;
                }
                s.Push(&s, s1[i]);
            }
        }
    }
    while (s.Pop(&s, data)) {
        s2 = s2 + data + ' ';
    }

    cout << '\n';
    cout << "后缀表达式为:  ";
    cout << s2 << endl;

    int data_1;
    int num, sum = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] >= '0' && s2[i] <= '9') {
            if (s2[i] != ' ') {
                sum = sum * 10 + s2[i] - '0';
            }
        } else if (s2[i] == '+' || s2[i] == '-' || s2[i] == '*' || s2[i] == '/') {
            str1.GetTop_1(&str1, data_1);
            int a = data_1;
            str1.Pop_1(&str1, data_1);

            str1.GetTop_1(&str1, data_1);
            int b = data_1;
            str1.Pop_1(&str1, data_1);
            num = fun (s2[i], a, b);
            str1.Push_1(&str1, num);
        } else if (s2[i] == ' ') {
            if (sum) {
                //str1.push(sum);
                str1.Push_1(&str1, sum);
                sum = 0;
            }
        }
    }
    cout << "运算结果:   ";
    str1.GetTop_1(&str1, data_1);
    cout << data_1 << endl;

    return 0;
}

