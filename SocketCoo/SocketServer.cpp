#include "pch.h"
#include <iostream>
#include "SocketServer.h"
#include <WinSock2.h>
#include <Windows.h>

using namespace std;
SocketServer::SocketServer()
{
	buff[10] = { 0 };
	//for (int i = 0; i < sizeof(buff); i++) {
	//	buff[i] = 0;
	//	cout << i;
	//}
	w = MAKEWORD(2, 0);
	WSAStartup(w, &data);
	socketServer = socket(AF_INET , SOCK_DGRAM, 0);
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(70);
	addrServer.sin_addr.S_un.S_addr = INADDR_ANY;//inet_addr("127.0.0.1");
	bind(socketServer, (const sockaddr *)&addrServer, sizeof(addrServer));
	cout << "socketServerÒÑÆô¶¯" << endl;
}

SocketServer::~SocketServer()
{
	closesocket(socketServer);
	WSACleanup();
}

SOCKET SocketServer::get_Socket()
{
	return SOCKET(socketServer);
}

int SocketServer::socketloop()
{
	//cout << buff;
	int n = sizeof(addrClient);
	while (1) {
		if (recvfrom(socketServer, buff, sizeof(buff), 0,(sockaddr*) &addrClient, /*(int *)sizeof(addrClient)*/ &n) != 0) {
			cout << buff ;
			buff[10] = { 0 };
		}
		Sleep(100);

	}
}
