/*************************************************************************
	> File Name: main1.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年09月20日 星期五 17时28分24秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include "SqList.h"
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	int i, k;
	ElemType e, data[10] = {'s', 'a', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'p'};
	SqList sq1;
	Status re;

	//测试初始化函数

    cout << "初始序列为: s, a , d, f, g, h, j, k, l, p" << endl;

	re = sq1.InitList(); 
 	if(re == OK) cout << "线性表初始化成功！" << endl << endl;
 	else cout << "线性表初始化失败！" << endl << endl; 

    //空表
    cout << "判断此线性表是否为空表：" << endl;
    re = sq1.ListEmpty();
    if (re == OK) cout << "此线性表为空表！" << endl << endl;
    else cout << "此线性表不是空表。" << endl << endl;

 	//输入原始数据 原来
   	for (k = 1; k <= 10; k++) {
   		sq1.ListInsert (k, data[k - 1]);
    }

	//测试求长度函数
   	cout << "线性表长度为：" << sq1.ListLength() << endl << endl;

    sort (data, data + sq1.ListLength());
    cout << "排序后的顺序表线性序列为:";
    for (int i = 0; i < sq1.ListLength(); i++) {
        cout << data[i] << ' ';
    }
    cout << endl;
    //cout << data << endl;
    //cout << data[0] << endl;

    //查找
    cout << "测试查找函数：" << endl;
    cout << "输入要查找的元素：" << endl;
    cin >> e;
    re = sq1.LocateElem (e); //
    //cout << re << endl;
    if (re > 0) cout << e << "查找成功!" << "　在第" << sq1.LocateElem (e) << "个" << endl << endl;
    else cout << "ERROR ！" << endl << endl;

	//测试读取
	cout << "测试读取函数，输入i的值:" << endl;
	cin	>>	i;
	re = sq1.GetElem(i, e);
	if (re == ERROR) cout << "ERROR!" << endl << endl;
	else cout << "读出数据为：" << e << endl << endl;

 	//测试插入
 	cout << "测试插入函数，输入i的值:" << endl;
 	cin >> i;
 	cout << "输入e的值:" << endl;
 	cin >> e;
 	re = sq1.ListInsert(i, e);
 	if (re == OK) cout << "在" << i << "位置插入数据" << e << endl << endl;
 	else cout << "ERROR!" << endl << endl;

 	//测试删除
    cout << "测试删除函数，输入 i 的值: " << endl;
    cin >> i;
    re = sq1.ListDelete (i, e);
    if (re == OK) cout << "在" << i << "位置删除数据" << e << endl << endl;
    else cout << "ERROR" << endl << endl;
    /*****/
    //空表
    cout << "判断此线性表是否为空表：" << endl;
    re = sq1.ListEmpty();
    if (re == OK) cout << "此线性表为空表！" << endl << endl;
    else cout << "此线性表不是空表。" << endl << endl;
	
    //清空
    cout << "测试清空函数：" << endl;
    re = sq1.ClearList ();
    if (re == OK) cout << "线性表清空成功！" << endl << endl;
    else cout << "线性表清空失败！" << endl << endl;

	//销毁
    cout << "测试销毁函数：" << endl;
    re = sq1.DestroyList ();
    if (re == OK) cout << "线性表销毁成功!" << endl << endl;
    else cout << "线性表销毁失败！" << endl << endl;

 	system("PAUSE");
 	return EXIT_SUCCESS;
}


