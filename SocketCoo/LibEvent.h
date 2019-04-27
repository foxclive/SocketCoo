#pragma once
#include "SocketServer.h"
#include <event.h>

class LibEvent
{
public:
	LibEvent();
	~LibEvent();
public:
	
	void static socket_Read_cb(evutil_socket_t, short, void*);//evutil_socket_t fd, short what, void *arg);
private:
	struct event_base *eventBase;
	struct event *event;
	SOCKET socketSver;
	
	//int m_addr_size;
	//char buff[100] = { 0 };
	//LibEvent *ple;
};

