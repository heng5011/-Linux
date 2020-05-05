/*************************************************************************
	> File Name: CScklmp1.h
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月03日 星期三 20时18分08秒
 ************************************************************************/

#ifndef _CSCKLMP1_H
#define _CSCKLMP1_H
#endif
#include <cstdlib>
#include <cstdio>
//初始化
void init_CSckImp1 (void **handle);
//发送接口
void send_CSckImp1 (void *handle,  char* sendData, int sendLen);
//接收接口
void recv_CSckImp1 (void *handle,  char* recvData, int* recvLen);
//关闭
void close_CSckImp1 (void *handle);

