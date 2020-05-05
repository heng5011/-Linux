/*************************************************************************
	> File Name: CScklmp1.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月03日 星期三 20时21分22秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include "CSckImp1.h"
using namespace std;

struct Info {
    char data[1024];
    int len;
};

//初始化
void init_CSckImp1 (void **handle) {
    if (NULL == handle) {
        return ;
    }

    struct Info *info = (Info *) malloc (sizeof (struct Info)); //使用强制类型转换
    memset(info, 0, sizeof (struct Info));

    *handle = info;
}
//发送接口
void send_CSckImp1 (void *handle,  char* sendData, int sendLen) {
    if (NULL == handle) {
        return ;
    }

    if (NULL == sendData) {
        return ;
    }

    struct Info *info = (struct Info *) handle;

    strncpy(info -> data, sendData, sendLen);
    info -> len = sendLen;
}

//接收接口
void recv_CSckImp1 (void *handle,  char* recvData, int* recvLen) {
    if (NULL == handle) {
        return ;
    }

    if (NULL == recvData) {
        return ;
    }

    if (NULL == recvLen) {
        return ;
    }

    struct Info *info = (struct Info *) handle;
    strncpy (recvData, info -> data, info -> len);
    *recvLen = info -> len;
}
//关闭
void close_CSckImp1 (void *handle) {
    if (NULL == handle) {
        return ;
    }

    free (handle);
    handle = NULL;
}


