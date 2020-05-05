/*************************************************************************
	> File Name: suan算术表达式求值.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年12月15日 星期日 10时42分31秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

stack <char> s;
stack <int> str1;

int fun (char x, int a, int b) {
    int num;
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

int main() {
    string s1, s2;
    cin >> s1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= '0' && s1[i] <= '9') {
            if (s1[i + 1] > '9' || s1[i + 1] < '0') {
                //s2 = s2 + s.top() + ' ';
                s2 += s1[i];
                s2 += ' ';
               //* cout << s1[i] << ' ';
            } else {
                //*cout << s1[i];
                s2 += s1[i];
            } //cout << s1[i];
        } else {
            if (s.empty()) {
                s.push (s1[i]);
            } else if (s1[i] == '(') {
                s.push(s1[i]);
            } else if (s1[i] == ')') {
                while (s.top() != '(') {
                    //s2 = s2 + s.top() + ' ';
                    s2 += s.top();
                    s2 += ' ';
                    //*cout << s.top() << ' ';
                    s.pop();
                }
                s.pop();
            } else {
                //cout << s.top() << endl;
                while (prio(s1[i]) <= prio(s.top())) {
                    s2 = s2 + s.top() + ' ';
                    //s2 += s.top();
                    //s2 += ' ';
                    //*cout << s.top() << ' ';
                    s.pop();
                    if (s.empty()) break;
                } 
                s.push(s1[i]);
            }
        }
    }
    
    while (!s.empty()) {
        s2 = s2 + s.top() + ' ';
        //s2 += s.top();
        //s2 += ' ';
        //*cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
    cout << "后缀表达式为:  ";
    cout << s2 << endl;
    //cout << "&&       " << s2 << endl;
    
    //string s;
    //getline(cin, s);
    int num, sum = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] >= '0' && s2[i] <= '9') {
            if (s2[i] != ' ') {
                sum = sum * 10 + s2[i] - '0';
            }
        } else if (s2[i] == '+' || s2[i] == '-' || s2[i] == '*' || s2[i] == '/') {
            //cout << str1.top() << endl;
            int a = str1.top();
            str1.pop();
            int b = str1.top();
            str1.pop();
            num = fun (s2[i], a, b);
            str1.push(num);
        } else if (s2[i] == ' ') {
            if (sum) {
                str1.push(sum);
                sum = 0;
            }
        }
    }
    cout << "运算结果:   ";
    cout << str1.top() << endl;
    return 0;
}

