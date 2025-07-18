#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define NOMINMAX 
#include <iostream>
#include <WinSock2.h>

#include "flatbuffers/flatbuffers.h"
#include "UserEvents_generated.h"
#include "Packet.h"

#pragma comment(lib, "ws2_32.lib")

int ProcessRecvPacket(SOCKET ClientSocket, char* Buffer);

int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!ListenSocket)
	{
		std::cout << "Failed Create ListenSocket" << std::endl;
		exit(-1);
	}

	sockaddr_in ListenSockAddr;
	memset(&ListenSockAddr, 0, sizeof(ListenSockAddr));
	ListenSockAddr.sin_family = PF_INET;
	ListenSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ListenSockAddr.sin_port = htons(30303);

	int Result = bind(ListenSocket, (sockaddr*)&ListenSockAddr, sizeof(ListenSockAddr));

	if (Result == SOCKET_ERROR)
	{
		std::cout << "Failed Bind ListenSocket" << std::endl;
		exit(-1);
	}

	Result = listen(ListenSocket, 0);

	if (Result == SOCKET_ERROR)
	{
		std::cout << "Failed Listen ListenSocket" << std::endl;
		exit(-1);
	}


	fd_set ReadSockets;
	FD_ZERO(&ReadSockets);
	FD_SET(ListenSocket, &ReadSockets);

	while (true)
	{

		fd_set ReadSocketsCopy = ReadSockets;
		timeval timeout{ 0, 1000 };

		int ChangedReadSocketCount = select(0, &ReadSocketsCopy, NULL, NULL, &timeout);
		if (ChangedReadSocketCount > 0)
		{
			for (int i = 0; i < (int)ReadSockets.fd_count; ++i)
			{
				if (ReadSockets.fd_array[i] == ListenSocket)
				{
					// New ClientSocket accept
					sockaddr_in ClientSockAddr;
					memset(&ClientSockAddr, 0, sizeof(ClientSockAddr));
					int ClientSockAddrLength = sizeof(ClientSockAddr);
					SOCKET ClientSocket = accept(ListenSocket, (sockaddr*)&ClientSockAddr, &ClientSockAddrLength);

					if (ClientSocket == SOCKET_ERROR)
					{
						std::cout << "Failed Accept ClientSocket" << std::endl;
						closesocket(ClientSocket);
					}
					else
					{
						FD_SET(ClientSocket, &ReadSockets);
					}
				}
				else
				{
					//recv
					char Buffer[4096] = { 0, };
					int RecvBytes = RecvPacket(ReadSockets.fd_array[i], Buffer);
					
					if (RecvBytes <= 0)
					{
						closesocket(ReadSockets.fd_array[i]);
						FD_CLR(ReadSockets.fd_array[i], &ReadSockets);
						std::cout << "Disconnect" << std::endl;
					}
					else
					{
						for (int j = 0; j < (int) ReadSockets.fd_count; ++j)
						{
							//send : test echo server
							if (ReadSockets.fd_array[j] != ListenSocket)
							{
								SendPacket(ReadSockets.fd_array[j], Buffer);
							}
						}
						
					}
				}
			}
		}
		else
		{
			//std::cout << "Server Stand By" << std::endl;
		}
	}


	closesocket(ListenSocket);

	WSACleanup();

	return 0;
}

int ProcessRecvPacket(SOCKET ClientSocket, char* Buffer)
{
	flatbuffers::FlatBufferBuilder Builder(1024);
	
	const UserEvents::EventData* RecvEventData = UserEvents::GetEventData(Buffer);

	int RecvBytes = RecvPacket(ClientSocket, Buffer);

	return RecvBytes;
}