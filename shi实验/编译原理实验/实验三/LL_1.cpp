/*************************************************************************
	> File Name: LL_1.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年10月28日 星期一 14时19分38秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

map <char, int> getnum;
vector <string> proce;
char text[100];
int table[105][105];
int num = 0, numvt = 0;

string first[100];
string follow[200];

void readin () {
    memset (table, -1, sizeof (table));
    getnum['#'] = 0;
    text[0] = '#';
    cout << "请输入所有的终结符: " << '\n';
    char x;
    do {
        cin >> x;
        getnum[x] = ++num;
        text[num] = x;
    } while (cin.peek () != '\n');
    numvt = ++num;
    getnum['@'] = numvt;
    text[num] = ('@');
    printf ("请输入所有的非终结符: \n");

    do {
        cin >> x;
        getnum[x] = ++num;
        text[num] = x;
    } while (cin.peek () != '\n');

    printf ("输入产生式集合(空字用'@'表示)，以'end'结束：\n");
    string pro;

    while (cin >> pro && pro != "end") {
        string ss;
        ss += pro[0];
        for (int i = 3; i < pro.size(); i++) {
            if (pro[i] == '|') {
                proce.push_back (ss);
                ss.clear();
                ss += pro[0];
            } else {
                ss += pro[i];
            }
        }
        proce.push_back (ss);
    }
}

void jiaoji (string &a, string b) {
    set <char> se;
    for (int i = 0; i < a.size (); i++) {
        se.insert (a[i]);
    }
    for (int i = 0; i < b.size (); i++) {
        se.insert(b[i]);
    }
    string ans;
    set <char> :: iterator it;
    for (it = se.begin (); it != se.end (); it++) {
        ans += *it;
    }
    a = ans;
}

string get_f (int vn, int & has_0) {
    if (vn == numvt) has_0 = 1;
    if (vn < numvt) return first[vn];
    string ans;
    for (int i = 0; i < proce.size (); i++) {
        if (getnum[proce[i][0]] == vn) {
            ans += get_f (getnum[proce[i][1]], has_0);
        }
    }
    return ans;
}

void getfirst () {
    for (int i = 1; i <= numvt; i++) {
        first[i] += ('0' + i);
    }
    for (int j = 0; j < proce.size (); j++) {
        int k = 0, has_0 = 0;
        do {
            has_0 = 0;
            k++;
            if (k == proce[j].size()) {
                first[getnum[proce[j][0]]] += ('0' + numvt); break;
            }

            jiaoji(first[getnum[proce[j][0]]], get_f (getnum[proce[j][k]], has_0));
        } while (has_0);
    }
}

void print_first () {
    printf ("first集: \n");
    for (int i = 1; i <= num; i++) {
        cout << "first [" << text[i] << "]: ";
        for (int j = 0; j < first[i].size(); j++) {
            cout << text[first[i][j] - '0'] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void getfollow() {
    jiaoji(follow[getnum[proce[0][0]]], "0");
    for (int j = 0; j < proce.size(); j++) {
        for (int i = 1; i < proce[j].size(); i++) {
            if (getnum[proce[j][i]] <= numvt)continue;
            int k = i; int has_0;
            do {
                has_0 = 0;
                k++;
                if (k == proce[j].size()) {
                    jiaoji(follow[getnum[proce[j][i]]], follow[getnum[proce[j][0]]]);
                    break;
                }
                jiaoji(follow[getnum[proce[j][i]]], get_f(getnum[proce[j][k]], has_0));
            } while (has_0);
        }
    }
}

void gettable() {
    for (int i = 0; i < proce.size(); i++) {
        if (proce[i][1] == '@') {
            string flw = follow[getnum[proce[i][0]]];
            for (int k = 0; k < flw.size(); k++) {
                table[getnum[proce[i][0]]][flw[k] - '0'] = i;
            }
        }
        string temps = first[getnum[proce[i][1]]];
        for (int j = 0; j < temps.size(); j++) {
            if (temps[j] != ('0' + numvt)) {
                table[getnum[proce[i][0]]][temps[j] - '0'] = i;
            } else {
                string flw = follow[getnum[proce[i][1]]];
                for (int k = 0; k < flw.size (); k++) {
                    table[getnum[proce[i][0]]][flw[k] - '0'] = i;
                }
            }
        }
    }
}

string get_proce(int i) {
    if (i < 0)return " ";
    string ans;
    ans += proce[i][0];
    ans += "->";
    for (int j = 1; j < proce[i].size(); j++)
        ans += proce[i][j];
    return ans;
}

void print_table() {
    cout << "预测分析表：" << endl;
    for (int i = 0; i < numvt; i++)
        cout << '\t' << text[i];
    cout << '\n';
    for (int i = numvt + 1; i <= num; i++) {
        cout << text[i];
        for (int j = 0; j<numvt; j++) {
            cout << '\t' << get_proce(table[i][j]);
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_follow() {
    cout << "follow集：" << endl;
    for (int i = numvt + 1; i <= num; i++) {
        cout << "follow [" << text[i] << "]: ";
        for (int j = 0; j < follow[i].size(); j++)
            cout << text[follow[i][j] - '0'] << " ";
        cout << '\n';
    }
    cout << '\n';
}

string word;

bool analyze() {
    stack <char> sta;
    sta.push('#'); sta.push(proce[0][0]);
    int i = 0;
    while (!sta.empty()) {
        int cur = sta.top();
        sta.pop();
        if (cur == word[i]) {
            i++;
        } else if (cur == '#') {
            return 1;
        } else if (table[getnum[cur]][getnum[word[i]]] != -1) {
            int k = table[getnum[cur]][getnum[word[i]]];
            cout << proce[k][0] << "->";
            for (int j = 1; j<proce[k].size(); j++) {
                cout << proce[k][j];
            }
            cout << '\n';
            for (int j = proce[k].size() - 1; j>0; j--) {
                if (proce[k][j] != '@') {
                    sta.push(proce[k][j]);
                }
            }
        } else {
            return 0;
        }
    }
    return 1;
}

void fun () {
    readin();
    getfirst();
    getfollow();
    getfollow();
    gettable();
    print_first();
    print_follow();
    print_table();
    cout << "请输入字：" << endl;
    cin >> word;
    cout << (analyze() ? "succeed! 该字符有效，所用产生式如上。" : "ERROR !") << endl;
}

int main() {

    fun ();

    return 0;
}

