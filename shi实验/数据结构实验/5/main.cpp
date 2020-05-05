/*************************************************************************
	> File Name: main.cpp
	> Author: kwh
	> Mail: 
	> Created Time: 2019年11月15日 星期五 11时55分19秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include "BiTree.h"
using namespace std;

int main () {
    cout << "请初始化二叉树:" << endl;
    BiTree* T;
    T = T -> CreateBiTree ();
    
    cout << "前序遍历(递归) :" << endl;
    T -> PreorderTraversal(T);
    cout << '\n';
    cout << "前序遍历(非递归)" << endl;
    T -> PreorderTraversal2 (T);
    cout << '\n';
    
    cout << "中序遍历(递归)：" << endl;
    T -> InorderTraversal (T);
    cout << '\n';
    cout << "中序便利 (非递归): " << endl;
    T -> InorderTraversal2 (T);
    cout << '\n';

    cout << "后序遍历(递归)\n";
    T -> PostorderTraversal(T);
    cout << '\n';
    cout << "后序遍历(非递归)\n";
    T -> PostorderTraversal2 (T);
    cout << '\n';

    cout << "层次遍历\n";
    T -> LevelOrderTraversal (T);
    cout << '\n';

    vector <char> path;
 //   bool flag = T -> PrintPath (T, '5', path);

    cout << "二叉树高度 (递归)为: \n";
    cout << T -> getBiTreeHeight (T) << endl;

    cout << "二叉树高度 （非递归)为 ：\n";
    cout << T -> getBiTreeHeight2 (T) << endl;

    if (T -> Judge (T)) {
        cout << "这是棵完全二叉树\n";
    } else {
        cout << "这不是棵完全二叉树\n";
    }

    /*char data = '5';
    cout << "非递归打印" << data << "的祖先结点:" << endl;
    T -> FindAncestor (T, data);
    cout << '\n';

    cout << "非递归打印" << data << "的祖先结点:" << endl;
    T -> FindAncestor2 (T, data);
    cout << endl;*/

    cout << "叶子结点的带权路径之和为:" << endl;
    int wpl = T -> WPL(T);
    cout << wpl << endl;

    //cout << "该二叉树的WPL为" << BiTree :: WPL (T) << endl;

    return 0;
}

