/*************************************************************************
	> File Name: Linklist.h
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月13日 星期六 21时13分41秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef void * LinkList;
typedef int (*COMPARE) (void *, void *);

//初始化链表
LinkList Init_LinkList ();

//插入结点
void Insert_LinkList (LinkList list, int pos, void *data);

//遍历链表
void Foreach_LinkList (LinkList list, void (* myforeach)(void *));

//按位置删除
void RemoveByPos_LinkList (LinkList list, int pos);

//按值删除
void RemoveByVal_LinkList (LinkList list, void *data, COMPARE compare);

//清空链表
void Clear_LinkList (LinkList);

//大小
int Size_LinkList (LinkList list);

//销毁链表
void Destory_LinkList (LinkList list);

