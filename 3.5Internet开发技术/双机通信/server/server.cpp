#pragma comment(lib, "ws2_32.lib") 
#include <winsock2.h>
#include <stdio.h>
#include <string.h>
//#include <windows.h>
//#include <process.h>
#define PROTOPORT 5188//�����׽��ֵ�ȱʡЭ��˿ں�
#define QLEN 6//�����׽��ֵ�������д�С      

struct sockaddr_in clientaddr;
struct sockaddr_in servaddr;//(local);
int Listenfd;
int Clientfd;
char buf[1000];

DWORD WINAPI receive_server(LPVOID) //�������ݵ�Windows�߳�
{
	while (1)
	{    
		char buf[1000];
		if (recv(Clientfd, buf, strlen(buf), 0) > 0)
		{
			printf("client: %s\n",buf);
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
	Listenfd = socket(AF_INET, SOCK_STREAM, 0);       //���������������׽���
	servaddr.sin_family = AF_INET;                     //������ַ��ʽ��TCP/IP��ַ��ʽ
	servaddr.sin_port = htons(PROTOPORT);              //�������Ķ˿ں� 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);      //�Զ���ȡ������ַ 
	
	bind(Listenfd, (struct sockaddr *)&servaddr, sizeof(SOCKADDR_IN));    //��ַ�󶨵��׽���
	listen(Listenfd, 1);                                               //������ʼ
	int alen = sizeof(sockaddr_in);
	Clientfd = accept(Listenfd, (struct sockaddr *)&clientaddr, &alen);    //�������� 
	printf("server-client accepted!\n");
	HANDLE hThread = CreateThread(NULL, 0, receive_server, 0, 0, 0);        //���������߳�

	while (1)
	{
		//scanf("%s",&buf);
		//send(Clientfd, buf, strlen(buf)+1, 0);
		//if(strncmp(buf, "quit", 4) == 0)
        //{
        //    closesocket(Clientfd);
        //}
		scanf("%s", &buf);
		send(Clientfd, buf, strlen(buf)+1, 0);
		if(strncmp(buf, "quit", 4) == 0)
        {
            closesocket(Clientfd);
        }
		memset(buf, NULL, 1000);
	}
	closesocket(Clientfd);
	closesocket(Listenfd);
	CloseHandle(hThread);                           
	return 0;
}
