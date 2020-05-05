/*************************************************************************
	> File Name: wang网络通信接口.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月03日 星期三 20时16分25秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
using namespace std;

//初始化
typedef void (*init_CSocketProtocol) (void **handle);
//发送接口
typedef void (*send_CSocketProtocol) (void *handle,  char* sendData, int sendLen);
//接收接口
typedef void (*recv_CSocketProtocol) (void *handle,  char* recvData, int* recvLen);
//关闭
typedef void (*close_CSocketProtocol) (void *handle);

