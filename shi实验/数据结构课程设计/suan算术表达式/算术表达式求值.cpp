/*************************************************************************
	> File Name: 4.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年12月17日 星期二 16时45分26秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;

stack <int> str1;

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

int main () {
    string s;
    getline(cin, s);
    int num, sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (s[i] != ' ') {
                sum = sum * 10 + s[i] - '0';
            }
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int a = str1.top();
            str1.pop();
            int b = str1.top();
            str1.pop();
            num = fun (s[i], a, b);
            str1.push(num);
        } else if (s[i] == ' ') {
            if (sum) {
                str1.push(sum);
                sum = 0;
            }
        }
    }
    cout << str1.top() << endl;
    return 0;
}
