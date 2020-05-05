/*************************************************************************
	> File Name: status.h
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年11月13日 星期三 20时15分10秒
 ************************************************************************/

#ifndef _STATUS_H
#define _STATUS_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_TREE_SIZE 100

typedef int Status;
typedef int Boolean;
typedef char TElemType;

typedef TElemType Tree[MAX_TREE_SIZE];

#endif
