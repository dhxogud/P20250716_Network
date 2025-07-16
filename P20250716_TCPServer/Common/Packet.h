#pragma once

#include <iostream>
#include <WinSock2.h>

#include "flatbuffers/flatbuffers.h"

int RecvPacket(SOCKET Socket);
int SendPacket(SOCKET Socket, const flatbuffers::FlatBufferBuilder& Builder);

int RecvPacket(SOCKET Socket)
{
	char Buffer[1024] = { 0, };
	int RecvBytes = recv(Socket, Buffer, sizeof(Buffer), 0);
	std::cout << "Server Receive Message : " << Buffer << std::endl;
	return RecvBytes;
}

int SendPacket(SOCKET Socket, const flatbuffers::FlatBufferBuilder& Builder)
{
	char Buffer[1024] = { 0, };
	int SentBytes = send(Socket, Buffer, sizeof(Buffer), 0);
	std::cout << "Server Send Message" << Buffer << std::endl;
	return SentBytes;
}