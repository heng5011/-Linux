/*************************************************************************
	> File Name: test2.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年10月18日 星期五 18时55分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 100
using namespace std;
struct edge
{
    char preNode;  //节点表示只能用单个字符
    char nextNode;
    char tchar; //转换字符
};

struct newJ  //得到的状态集合
{
    string setJ;
};

struct relation //集合和集合之间的转换联系
{
    newJ* preJ;
    char jchar;
    newJ* nextJ;

};

void getEClosure(const edge *e, int cntEdge, newJ *st) //得到闭包
{
    for (int i = 0; i < st->setJ.length(); i++) //对每个状态集合中的状态取出
    {
        for (int j = 0; j < cntEdge; j++)  //对每条边进行测试
        {
            if (e[j].preNode == st->setJ[i] && e[j].tchar == '0') //转换字符为'0'也就是为空字符
            {
                st->setJ += e[j].nextNode;
            }
        }
    }
}

void move(char ttchar, edge *e, int cntEdge, newJ *source, newJ *dest) //e为所有边的集合，然后就能从一个转换字符得到全部的，比如2得到bd，而不会第一个2得到b，第二个2得到d
{
    for (int i = 0; i < source->setJ.length(); i++) //对每个状态集合中的状态取出
    {
        for (int j = 0; j < cntEdge; j++)
        {
            if (e[j].preNode == source->setJ[i] && e[j].tchar == ttchar)
            {
                dest->setJ += e[j].nextNode;
            }
        }
    }
}

//通过状态集合中的setJ来决定是否添加
bool isInsert(vector<newJ*> allSet, newJ *newSet)
{
    bool b = true;
    for (int k = 0; k < allSet.size(); k++)
    {
        if (allSet.at(k)->setJ == newSet->setJ)
            b = false;
    }
    return b;
}
//判断relation结构体去重
bool isInsertForRel(vector<relation*>relVec, newJ* preJ, char jchar, newJ* nextJ)
{
    bool isIn = true;
    for (int i = 0; i < relVec.size(); i++)
    {

        if (relVec.at(i)->preJ->setJ == preJ->setJ && relVec.at(i)->nextJ->setJ == nextJ->setJ && relVec.at(i)->jchar == jchar)
            isIn = false;

    }
    return isIn;
}
void uniqueChars(char*arr, int n, char *outs)
{
    memset(outs, 0, sizeof(char)*n);
    char first = arr[0];
    for (int i = 0; i < n; i++)
    {
        outs[arr[i] - first] = arr[i];
    }

}

//重命名转换
void changeName(vector<newJ*>allSet, newJ *tJ, string& newStr)
{
    newJ *tmpJ = new newJ();
    for (int i = 0; i < allSet.size(); i++)
    {
        if (tJ->setJ == allSet.at(i)->setJ)
            tmpJ->setJ = 'A' + i;
    }
    newStr = tmpJ->setJ;

}

int main()
{
    edge* e = new edge[MAX];
    int cntEdge = 0;
    char staNode;  //初始点和终止点
    string endNode;
    string Node;  //结点集合

    cout << "请输入NFA的总状态数: " << endl;
    int m;
    char a[15];
    cin >> m;
    cout << "请依次输入NFA的状态名称: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int cntRealEdge[MAX] = { 0 }; //不为空字符的边数组
    //cout << "输入各边的信息,并且以 '前点(char 'a'-'z')   转换字符(char '1'-'9')   后点(char 'a'-'z')'格式，结束以'$'开头" << endl;
    int n;
    cout << "请输入NFA的边数: " ;//<< n << endl;
    cin >> n;
    cout << n << endl;
    cout << "请分别输入 起始状态，接受字符 和 到达状态: <同组数据请依次用空格隔开>" << endl;
    cout << "如果转换字符为空，则用'0'表示" << endl;
    //以 preNode  tchar  nextNpde来进行边的输入。并且以 '$'结束输入
    for (int i = 0; i < MAX; i++)
    {

        cin >> e[i].preNode;
        if ((e[i].preNode) == '$')break;
        cin >> e[i].tchar >> e[i].nextNode;
        if (e[i].tchar == '0') cntRealEdge[cntEdge] = 1;
        cntEdge++;
    }
    //将edge边的结点放入向量中
    for (int i = 0; i < cntEdge; i++)
    {
        char preTmp = e[i].preNode;
        char nextTmp = e[i].nextNode;
        //边中的结点没有收录的话就添加
        if (Node.find (preTmp) > Node.length())
            Node += preTmp;
        if (Node.find (nextTmp) > Node.length())
            Node += nextTmp;
    }

    cout << "输入初始点字符" << endl;
    cin >> staNode;
    while (Node.find (staNode) == string::npos)
    {
        cout << "初始状态输入错误" << endl;
        cin >> staNode;
    }
    cout << "输入终止点字符(若有多个终结状态，直接写成字符串形式)" << endl;
    cin >> endNode;
    bool inputStatus = true;
    while (inputStatus)
    {
        for (int i = 0; i < endNode.length(); i++)
        {
            if (Node.find(endNode[i]) == string::npos)
            {
                cout << "终结状态输入错误" << endl;
                cout << "请重新输入:" << endl;
                cin >> endNode;

            }

        }
        inputStatus = false;

    }
    newJ *newSet = new newJ();
    newSet->setJ = staNode;  //设置初始点为状态集合I
    getEClosure(e, cntEdge, newSet);  //
    vector<newJ*>allSet(1, newSet);  //设置所有状态集合的向量
    vector<newJ*>::iterator iter;
    int sizeOfStrVec = 1;

    /*用来存储每一次的闭包操作前的第一列的状态集合
    *比如第一次strVec存储的是初始状态，求闭包时多了2个状态集合。在第二次时存储的是新的2个状态，原先的初始状态被去除。
    *总的状态集合存储在allSet中
    */
    vector<newJ*>strVec(1, newSet);
    vector<relation*>relVec;
    while (sizeOfStrVec)  //如果不符合则说明新增的集合都是原有的集合
    {
        int oldAllSet = allSet.size();
        for (int j = 0; j < sizeOfStrVec; j++)
        {
            for (int i = 0; i < cntEdge; i++) //对每个字母进行求类似Ik;这个循环只处理一行
            {
                newJ *dest = new newJ();
                if (!cntRealEdge[i])  //去掉空转换字符的边
                {
                    move(e[i].tchar, e, cntEdge, strVec.at(j), dest);  //如果有一个字符在多条边上，所以要按字符相同的归类集合。否则就会使得状态集合分开而造成错误！！
                    getEClosure(e, cntEdge, dest);  //此时dest为 Ia,Ib之类的。
                    if (isInsert(allSet, dest) && dest->setJ != "")   //没找到并且dest->setJ且不为空则添加
                    {
                        allSet.push_back(dest);

                    }
                    //在添加relVec时，只要是不为空就要添加，这里会使relDest的元素可能重复（当一个字符出现在多条边中）
                    if (dest->setJ != "")
                    {
                        relation* relDest = new relation();
                        relDest->preJ = strVec.at(j);
                        relDest->jchar = e[i].tchar;
                        relDest->nextJ = dest;
                        bool isIn = isInsertForRel(relVec, relDest->preJ, relDest->jchar, relDest->nextJ);
                        if (isIn)  //去重
                        {
                            relVec.push_back(relDest);
                        }
                    }
                }
            }
        }
        strVec.clear();
        int newAllSet = allSet.size();
        for (int i = oldAllSet; i < allSet.size(); i++) //将allSet中新增的后面元素添加进strVec中。
        {
            newJ *dest = new newJ();
            dest = allSet.at(i);
            strVec.push_back(dest);
        }

        sizeOfStrVec = strVec.size();
    }

    /*cout << "转换结果" << endl; //
    vector<relation*>::iterator relIter;
    for (relIter = relVec.begin(); relIter != relVec.end(); relIter++)
    {
        cout << (*relIter)->preJ->setJ << " " << (*relIter)->jchar << " " << (*relIter)->nextJ->setJ << endl;
    }*/

    char upperChars[26];
    memset(upperChars, 0, sizeof(char) * 26);
    //cout << "重命名如下：" << endl;
    cout << "状态转换为：" << endl;
    for (int i = 0; i < allSet.size(); i++)
    {
        upperChars[i] = 'A' + i;
        cout << upperChars[i] << ":" << allSet.at(i)->setJ << endl;
    }

    vector <relation*> newRelVec;  //经过重命名后的relVec
    for (int i = 0; i < relVec.size(); i++)
    {
        relation* newRel = new relation();
        string preNew, nextNew;
        changeName(allSet, relVec.at(i)->preJ, preNew);
        changeName(allSet, relVec.at(i)->nextJ, nextNew);
        newJ* tpreJ = new newJ();
        newJ* tnextJ = new newJ();
        newRel->preJ = tpreJ;
        newRel->nextJ = tnextJ;
        newRel->preJ->setJ = preNew;
        newRel->nextJ->setJ = nextNew;
        newRel->jchar = relVec.at(i)->jchar;
        newRelVec.push_back(newRel);
    }
    //输出验证重命名的集合关系
    cout << "转化后的DFA为：" << endl;
    vector<relation*>::iterator newRelIter;
    for (newRelIter = newRelVec.begin(); newRelIter != newRelVec.end(); newRelIter++)
    {
        cout << endl << (*newRelIter)->preJ->setJ << " " << (*newRelIter)->jchar << " " << (*newRelIter)->nextJ->setJ << endl;
    }

/*
    //得出初始状态和接受状态
    cout << "接受状态是:" << endl;
    int outsize = allSet.size();
    char *output = new char[outsize];
    memset(output, 0, sizeof(char)*outsize);
    int outputCnt = 0;
    for (int k = 0; k < allSet.size(); k++)
    {
        for (int i = 0; i < endNode.length(); i++)
        {
            if ((allSet.at(k)->setJ).find(endNode[i]) != string::npos)
                output[outputCnt++] = 'A' + k;
        }

    }
    //数组去重输出
    char *outsFinal = new char[outputCnt];
    uniqueChars(output, outputCnt, outsFinal);
    for (int i = 0; i < outputCnt; i++)
    {
        if (outsFinal[i] != '\0')
            cout << outsFinal[i]<<" ";
    }

    system("pause");
*/
    return 0;
}

