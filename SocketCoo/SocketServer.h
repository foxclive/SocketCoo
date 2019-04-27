
#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include "LibEvent.h"

#pragma comment(lib, "WS2_32.lib") //Á¬½ÓÌ×½Ó×Ö¿â



class SocketServer {
public:
	
	SocketServer();
	~SocketServer();

	SOCKET get_Socket();
	int socketloop();
private:
	SOCKET socketServer;
	sockaddr_in addrServer;
	sockaddr addrClient;
	char buff[10];
	WSADATA data;
	WORD w;

};