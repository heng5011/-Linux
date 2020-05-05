/*************************************************************************
	> File Name: dong动态数组.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 20时54分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <cstdlib>
//using namespace std;

//１.先把所需要的数据信息结构定义下来
struct DynamicArray {
    //数组存储元素的空间首地址
    void **addr;
    //存储数据的内存中最大能够容纳多少元素
    int capacity; //容量
    //当前存储数据的内存中有多少元素
    int size; //大小
};

//初始化数组
struct DynamicArray *Init_DynamicArray (int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    struct DynamicArray *arr = malloc (sizeof (struct DynamicArray));
    if (NULL == arr) {
        return NULL;
    }
    arr -> capacity = capacity;
    arr -> addr = malloc (sizeof (void *)* capacity);
    arr -> size = 0;

    return arr;
}

//插入元素
void Insert_DynamicArray (struct DynamicArray *arr, int pos, void *data) {
    if (NULL == arr) {
        return ;
    }
    if (NULL == data) {
        return ;
    }
    if (pos < 0 || pos > arr -> size) {
        pos = arr -> size;
    }

    //判断空间是否足够
    if (arr -> size >= arr -> capacity) {
        //申请一块二更大的内存
        int newcapacity = arr -> capacity * 2;
        void **newspace = malloc (sizeof (void *)* newcapacity);

        //２.将原来空间的数据拷贝到新空间
        memcpy (newspace, arr -> addr, sizeof (void *)* arr -> capacity);

        //３．释放原来空间的内存
        free (arr -> addr);

        //４.更新addr指向
        arr -> addr = newspace;
        arr -> capacity = newcapacity;
    }
    
    //移动元素，给pos位置空出位置来
    for (int i = arr -> size - 1; i >= pos; --i) {
        arr -> addr[i + 1] = arr -> addr[i];
    }

    //将新元素插入到pos位置
    arr -> addr[pos] = data;
    arr -> size++;
}
//遍历
void Foreach_DynamicArray (struct DynamicArray *arr, void (*_callback)(void *) ) {
    if (NULL == arr) {
        return ;
    }
    if (NULL == _callback) {
        return ;
    }
    for (int i = 0; i < arr -> size; ++i) {
        _callback (arr -> addr[i]);
    }
}

//位置删除
void removeByPos_DynamicArray (struct DynamicArray *arr, int pos) {
    if (NULL == arr) {
        return ;
    } 
    if (pos < 0 || pos > arr -> size - 1) {
        return ;
    }
    for (int i = pos; i < arr -> size - 1; ++i) {
        arr -> addr[i] = arr -> addr[i + 1];
    }
    arr -> size--;
}

//按值删除
void RemoveByValue_DynamicArray (struct DynamicArray *arr, void *data, int (*compare)(void *, void *)) {
    if (NULL == arr) {
        return ;
    }
    if (NULL == data) {
        return ;
    }
    if (NULL == compare) {
        return ;
    }

    for (int i = 0; i < arr -> size; ++i) {
        if (compare (arr -> addr[i], data)) {
            removeByPos_DynamicArray (arr, i);
            break;
        }
    }
}

//销毁数组
void Destory_DynamicArry (struct DynamicArray *arr) {
    if (NULL == arr) {
        return ;
    }
    if (arr -> addr != NULL) {
        free (arr -> addr);
        arr -> addr = NULL;
    }
    free(arr);
    arr = NULL;
}    

struct Person {
    char name[64];
    int age;

};

void myPrint (void *data) {
    struct Person *person = data;
    printf ("Name: %s Age:%d\n", person -> name, person -> age);
}

int myCompare (void *d1, void *d2) {
    struct Person *p1 = (struct Person *)d1;
    struct Person *p2 = (struct Person *)d2;
    return strcmp (p1 -> name, p2 -> name) == 0 && (p1 -> age == p2 -> age);
}

void test() {
    //创建动态数组
    struct DynamicArray *da = Init_DynamicArray(10);
    //动态数组添加元素
    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"ccc", 30};
    struct Person p4 = {"ddd", 40};
    struct Person p5 = {"eee", 50};
    struct Person p6 = {"fff", 60};
    
    Insert_DynamicArray (da, 0, &p1);
    Insert_DynamicArray (da, 0, &p2);
    Insert_DynamicArray (da, 0, &p3);
    Insert_DynamicArray (da, 1, &p4);
    Insert_DynamicArray (da, 1, &p5);
    printf ("capacity:%d \n", da -> capacity);
    Insert_DynamicArray (da, 100, &p6);
    printf ("capacity:%d \n", da -> capacity);

    Foreach_DynamicArray (da, myPrint);

    printf ("-------------------------\n");
    removeByPos_DynamicArray (da, 2);
    Foreach_DynamicArray (da, myPrint);

    printf ("--------------------------\n");
    struct Person pDel = {"aaa", 10};
    RemoveByValue_DynamicArray (da, &pDel, myCompare);
    Foreach_DynamicArray (da, myPrint);

    printf ("----------------\n");
    //销毁
    Destory_DynamicArry (da);
}
int main() {
    test ();
    return 0;
}
