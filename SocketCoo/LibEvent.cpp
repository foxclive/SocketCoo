#include "pch.h"
#include "LibEvent.h"
#include "event.h"
#include <iostream>

//#include <stdio.h>

using namespace std;
//typedef void(*event_callback_fn)(evutil_socket_t sockfd, short event_type, void *arg);
//void socket_Read_cb(int fd, short what, void* arg);


LibEvent::LibEvent()
{
	SocketServer *ssPrt = new SocketServer;
	socketSver = ssPrt->get_Socket();
	eventBase = event_base_new();
	//m_addr_size = sizeof(addrClient);
	if (!eventBase) {
		cout << stderr, "event_Base ´´½¨Ê§°Ü";
	}
	//cout << "creating event";
	//typedef void ( * st)(evutil_socket_t, short, void*);
	event = event_new(eventBase,socketSver,EV_READ|EV_PERSIST, LibEvent::socket_Read_cb,ssPrt);
	//cout << "dispatching";
	event_add(event, NULL);
	event_base_dispatch(eventBase);
}


LibEvent::~LibEvent()
{
}

void LibEvent::socket_Read_cb(evutil_socket_t, short, void* SocketServerPointer)//evutil_socket_t fd, short what, void *arg)
{
	SOCKET socket;
	SocketServer *ssPrt =(SocketServer *) SocketServerPointer;
	socket = ssPrt->get_Socket();
	char b[100] = { 0 };
	sockaddr addrClient;
	int m_addr_size;
	m_addr_size=sizeof(addrClient);
	recvfrom(socket,b,100,NULL,&addrClient,&m_addr_size);
	cout << b << endl;
}

