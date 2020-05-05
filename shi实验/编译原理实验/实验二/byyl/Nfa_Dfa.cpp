/*************************************************************************
	> File Name: Nfa_Dfa.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年10月18日 星期五 22时21分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

const int MAX = 100;

struct edge {
    char preNode;
    char nextNode;
    char tchar;
};

struct newJ {
    string setJ;
};

struct relation {
    newJ* preJ;
    char jchar;
    newJ* nextJ;
};

void getEClosure (const edge *e, int cntEdge, newJ *st) {
    for (int i = 0; i < st -> setJ.length (); i++) {
        for (int j = 0; j < cntEdge; j++) {
            if (e[j].preNode == st -> setJ[i] && e[j].tchar == '0') {
                st -> setJ += e[j].nextNode;
            }
        }
    }
}

void move (char ttchar, edge *e, int cntEdge, newJ *source, newJ *dest) {
    for (int i = 0; i < source -> setJ.length (); i++) {
        for (int j = 0; j < cntEdge; j++) {
            if (e[j].preNode == source -> setJ[i] && e[j].tchar == ttchar) {
                dest -> setJ += e[j].nextNode;
            }
        }
    }
}

bool isInsert (vector <newJ*> allSet, newJ *newSet) {
    bool b = true;
    for (int k = 0; k < allSet.size (); k++) {
        if (allSet.at (k) -> setJ == newSet -> setJ) {
            b = false;
        }
    }
    return b;
}

bool isInsertForRel (vector <relation*>relVec, newJ* preJ, char jchar, newJ* nextJ) {
    bool isIn = true;
    for (int i = 0; i < relVec.size (); i++) {
        if (relVec.at(i) -> preJ -> setJ == preJ -> setJ && relVec.at (i) -> nextJ -> setJ == nextJ -> setJ && relVec.at (i) -> jchar == jchar) {
            isIn = false;
        }
    }
    return isIn;
}

void uniqueChars (char *arr, int n, char *outs) {
    memset (outs, 0, sizeof (char) *n);
    char first = arr[0];
    for (int i = 0; i < n; i++) {
        outs[arr[i] - first] = arr[i];
    }
}

void changeName (vector <newJ*>allSet, newJ *tJ, string& newStr) {
    newJ *tmpJ = new newJ();
    for (int i = 0; i < allSet.size (); i++) {
        if (tJ -> setJ == allSet.at(i) -> setJ) {
            tmpJ -> setJ = 'A' + i;
        }
    }
    newStr = tmpJ -> setJ;
}

int main () {
    edge* e = new edge[MAX];
    int cntEdge = 0;
    char staNode;
    string endNode;
    string Node;

    cout << "请输入NFA的总状态数：" << endl;
    int m;
    char a[15];
    cin >> m;
    cout << "请依次输入NFA的状态名称：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int cntRealEdge[MAX] = {0};
    int n;
    cout << "请输入NFA的边数：";
    cin >> n;
    cout << n << endl;
    cout << "请分别输入　起始状态，接受状态　和　到达状态：<同组数据请依次用空格隔开>" << endl;
    cout<< "如果转换字符为空，　则用 '0' 表示" << endl;
    for (int i = 0; i < MAX; i++) {
        cin >> e[i].preNode;
        if ((e[i].preNode) == '$') break;
        cin >> e[i].tchar >> e[i].nextNode;
        if (e[i].tchar == '0') cntRealEdge[cntEdge] = 1;
        cntEdge++;
    }

    for (int i = 0; i < cntEdge; i++) {
        char preTmp = e[i].preNode;
        char nextTmp = e[i].nextNode;
        if (Node.find (preTmp) > Node.length ()) {
            Node += preTmp;
        }
        if (Node.find (nextTmp) > Node.length ()) {
            Node += nextTmp;
        }
    }
    cout << "输入初始点字符" << endl;
    cin >> staNode;
    while (Node.find (staNode) == string :: npos) {
        cout << "初始化状态输入错误" << endl;
        cin >> staNode;
    }
    cout << "输入终点字符 (若有多个终结状态，直接写成字符串形式)" << endl;
    cin >> endNode;
    bool inputStatus = true;
    while (inputStatus) {
        for (int i = 0; i < endNode.length (); i++) {
            if (Node.find (endNode[i]) == string :: npos) {
                cout << "终结状态输入错误" << endl;
                cout << "请重新输入:" << endl;
                cin >> endNode;
            }
        }
        inputStatus = false;
    }
    newJ *newSet = new newJ ();
    newSet -> setJ = staNode;
    getEClosure (e, cntEdge, newSet);
    vector <newJ*>allSet (1, newSet);
    vector <newJ*> :: iterator iter;
    int sizeOfStrVec = 1;

    vector <newJ*>strVec (1, newSet);
    vector <relation*>relVec;
    while (sizeOfStrVec) {
        int oldAllSet = allSet.size();
        for (int j = 0; j < sizeOfStrVec; j++) {
            for (int i = 0; i < cntEdge; i++) {
                newJ *dest = new newJ();
                if (!cntRealEdge[i]) {
                    move (e[i].tchar, e, cntEdge, strVec.at(j), dest);

                    getEClosure (e, cntEdge, dest);
                    if (isInsert (allSet, dest) && dest -> setJ != "") {
                        allSet.push_back (dest);
                    }

                    if (dest -> setJ != "") {
                        relation* relDest = new relation ();
                        relDest -> preJ = strVec.at(j);
                        relDest -> jchar = e[i].tchar;
                        relDest -> nextJ = dest;
                        bool isIn = isInsertForRel (relVec, relDest -> preJ, relDest -> jchar, relDest -> nextJ);
                        if (isIn) {
                            relVec.push_back (relDest);
                        }
                    }
                }
            }
        }
        strVec.clear();
        int newAllSet = allSet.size();
        for (int i = oldAllSet; i < allSet.size(); i++) {
            newJ *dest = new newJ ();
            dest = allSet.at(i);
            strVec.push_back (dest);
        }

        sizeOfStrVec = strVec.size(); //239
    }
    char upperChars[26];
    memset (upperChars, 0, sizeof (char) * 26);
    cout << "状态转换为: " << endl;
    for (int i = 0; i < allSet.size(); i++) {
        upperChars[i] = 'A' + i;
        cout << upperChars[i] << ":" << allSet.at(i) -> setJ << endl;
    }

    vector <relation*> newRelVec;
    for (int i = 0; i < relVec.size(); i++) {
        relation* newRel = new relation ();
        string preNew, nextNew;
        changeName (allSet, relVec.at(i) -> preJ, preNew);
        changeName (allSet, relVec.at(i) -> nextJ, nextNew);
        newJ* tpreJ = new newJ (); //266
        newJ* tnextJ = new newJ ();
        newRel -> preJ = tpreJ;
        newRel -> nextJ = tnextJ;
        newRel -> preJ -> setJ = preNew;
        newRel -> nextJ -> setJ = nextNew;
        newRel -> jchar = relVec.at (i) -> jchar;
        newRelVec.push_back (newRel);
    }
        cout << "转化后的DFA为：" << endl;
        vector <relation *> :: iterator newRelIter;
    for (newRelIter = newRelVec.begin (); newRelIter != newRelVec.end(); newRelIter++) {
        cout << '\n' << (*newRelIter) -> preJ -> setJ << " " << (*newRelIter) -> jchar << " " << (*newRelIter) -> nextJ -> setJ << endl; //278
    }

    return 0;
}
