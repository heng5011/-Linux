/*************************************************************************
	> File Name: jiekou.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月03日 星期三 19时51分56秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
#include "CSckImp1.h"
using namespace std;

//初始化
typedef void (*init_CSocketProtocol) (void **handle);
//发送接口
typedef void (*send_CSocketProtocol) (void *handle,  char* sendData, int sendLen);
//接收接口
typedef void (*recv_CSocketProtocol) (void *handle,  char* recvData, int* recvLen);
//关闭
typedef void (*close_CSocketProtocol) (void *handle);

//业务代码
void FrameWork (
    init_CSocketProtocol init,
    send_CSocketProtocol send,
    recv_CSocketProtocol recv,
    close_CSocketProtocol close) {
        //初始化连接
        void *handle = NULL;
        init (&handle);

        //发送数据
        char buf[] = "hello world !";
        int len = strlen(buf);
        send (handle, buf, len);

        //接收数据
        char recvBuf[1024] = {0};
        int recvLen = 0;
        recv (handle, recvBuf, &recvLen);
        printf ("接收到的数据： %s \n", recvBuf);
        printf ("接收到的数据长度: %d \n", recvLen);
        
        //关闭连接
        close (handle);
        handle = NULL;
    }

void test () {
    FrameWork (init_CSckImp1, send_CSckImp1, recv_CSckImp1, close_CSckImp1);

}

int main() {
    test();
    system ("pause");
    return EXIT_SUCCESS;
    return 0;
}
