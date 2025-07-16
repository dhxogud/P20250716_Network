#pragma once

#include <iostream>
#include <WinSock2.h>

#include "flatbuffers/flatbuffers.h"

int RecvPacket(SOCKET Socket);
int RecvPacket(SOCKET Socket, char* Buffer);

int SendPacket(SOCKET Socket, char* Message);
int SendPacket(SOCKET Socket, const flatbuffers::FlatBufferBuilder& Builder);




int RecvPacket(SOCKET Socket)
{
	return 0;
}

int RecvPacket(SOCKET Socket, char* Buffer)
{
	int RecvBytes = recv(Socket, Buffer, sizeof(Buffer), 0);
	std::cout << "Server Receive Message : " << Buffer << std::endl;
	return RecvBytes;
}

int SendPacket(SOCKET Socket, char* Message)
{
	int SentBytes = send(Socket, Message, sizeof(Message), 0);
	return SentBytes;
}

int SendPacket(SOCKET Socket, const flatbuffers::FlatBufferBuilder& Builder)
{
	char Buffer[1024] = { 0, };
	int SentBytes = send(Socket, Buffer, sizeof(Buffer), 0);
	std::cout << "Server Send Message" << Buffer << std::endl;
	return SentBytes;
}