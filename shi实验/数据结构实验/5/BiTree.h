/*************************************************************************
	> File Name: BiTree.h
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年11月15日 星期五 15时30分12秒
 ************************************************************************/

#ifndef _BITREE_H
#define _BITREE_H
#include "status.h"
//#include <iostream>
//#include <vector>
//using namespace std;

class BiTree {
    private :
    
    TElemType data;
    //char data;
    BiTree* lchild;
    BiTree* rchild;

    public :

    BiTree* CreateBiTree ();
    void PreorderTraversal (BiTree* T);
    void PreorderTraversal2 (BiTree* T);
    void InorderTraversal (BiTree* T);
    void InorderTraversal2 (BiTree* T);
    void PostorderTraversal (BiTree* T);
    void PostorderTraversal2 (BiTree* T);
    void LevelOrderTraversal (BiTree* T);
    int getBiTreeHeight (BiTree* T);
    int getBiTreeHeight2 (BiTree* T);
    bool Judge (BiTree* T);
    bool FindAncestors (BiTree* T, char data);
    void FindAncestors2 (BiTree* T, char data);
    int WPL (BiTree* T);
    void set (char ch);
    BiTree* Creat_Node (char ch);
    //BiTree* Pre_In_Build (char* pre, char* in, int size);
    //bool PrintPath (BiTree* tree, char v, vector<char>& path);
};

#endif
