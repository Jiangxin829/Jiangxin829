#pragma comment(lib, "ws2_32.lib") 
#include <WinSock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define SERVER_ADDRESS "127.0.0.1"
#define PROTOPORT 5188//ȱʡЭ��˿ں�
#define QLEN 6//�����׽��ֵ�������д�С
int Clientfd;
struct sockaddr_in servaddr;             
char buf[1000];

DWORD WINAPI receive_client(LPVOID)    //�������ݵ�Windows�߳�
{
	while (1)
	{
		char buf[1000];
		if(recv(Clientfd, buf, strlen(buf), 0) > 0)
		{
			printf("server: %s\n",buf);
			continue;
		}
	}
	return 0;
}
     
int main()
{
	
	WSADATA wsa;
	//��ʼ���׽���DLL
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("�׽��ֳ�ʼ��ʧ�ܣ�");
			exit(-1);
	}

	Clientfd = socket(AF_INET, SOCK_STREAM, 0);    //�����׽���
	memset((char*) & servaddr, 0, sizeof(servaddr));   //�������ַ��server��Ϊȫ0 
	servaddr.sin_family = PF_INET;              //������ַ��ʽ��TCP/IP��ַ��ʽ
	servaddr.sin_port = htons(PROTOPORT);                //�������Ķ˿ں�  
	servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);    //ָ����ַ  
	connect(Clientfd, (struct sockaddr *)&servaddr, sizeof(SOCKADDR_IN));   //���ӵ�������/
	printf("client-server connected!\n");
	HANDLE hThread = CreateThread(NULL, 0, receive_client, 0, 0, 0);      //���������߳�

	while (1)
	{
		scanf("%s", &buf);
		send(Clientfd, buf, strlen(buf)+1, 0);
		if(strncmp(buf, "quit", 4) == 0)
        {
            closesocket(Clientfd);
        }
		memset(buf, NULL, 1000);
	}
	closesocket(Clientfd); 
	CloseHandle(hThread);
	return 0;
}
