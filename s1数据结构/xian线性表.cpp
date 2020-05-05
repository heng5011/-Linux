/*************************************************************************
	> File Name: shujujiegou.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 14 Apr 2019 09:08:40 AM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct Vector {
    int *data;
    int size, length;
}Vector;
//初始化
void init(Vector *v, int n) {
    v->data = (int *) malloc(sizeof(int) * n);
    v->size = n;
    v->length = 0;
    return ;
}

//扩容
int expand(Vector *v) {
    int *p = (int *)realloc(v->data,sizeof(int) * v->size * 2);
    if(p == NULL) {
        return 0;
    }
    v->data = p;
    v->size = v->size * 2;
    return 1;
}
//插入
int insert(Vector *v, int ind, int value) {
    /*if(v->length == 0) {
        return 0;
    }*/
    if(ind < 0 || ind > v->length) {
        return 0;
    }
    if(v->length >= v->size) {
        expand(v);
        return 0;
    }
    for(int i = v->length; i > ind; --i) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = value;
    v->length++;
    
    return 1;
}

    //删除
    int erase(Vector *v, int ind) {
        if(v->length == 0) {
            return 0;
        }
        if(ind < 0 || v->length) {
            return 0;
        }
        for(int i = ind + 1; i < v->length; i++) {
            v->data[i - 1] = v->data[i];
        }
        v->length -= 1;
        return 1;
    }
    
    //查找
    int search(Vector *v, int value0) {
        for(int i = 0; i < v->length; ++i) {
            if(v->data[i] == value0) {
                return 1;
            }
        }
        return 0;
    }

    //遍历
    void output(Vector *v) {
        for(int i = 0; i < v->length; i++) {
            printf("%d", v->data[i]);
        }
        cout<<endl;
        return ;
    }

    //清除
    void clear(Vector *v) {
        if(v == NULL) return ;
        free(v->data);
        free(v);
        return ;
    }

   int main() {
   Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
	int t, n, x, y, s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n == 1) {
            scanf("%d %d", &x, &y);
            s = insert(a, x, y);
            if(s == 1) {
                printf("success\n");
            }
            if(s == 0) {
                printf("failed\n");
            }
        }
        if(n == 2) {
            scanf("%d", &x);
            s = erase(a, x);
            if(s == 1) {
                printf("success\n");
            }
            if(s == 0) {
                printf("failed\n");
            }
        }
        if(n == 3) {
            scanf("%d", &x);
            s = search(a, x);
            if(s == 1) {
                printf("success\n");
            }
            if(s == 0) {
                printf("failed\n");
            }
        }
        if(n == 4) {
            output(a);
        }
    }
        clear(a);
    return 0;
} 
