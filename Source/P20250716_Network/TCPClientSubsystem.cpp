// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPClientSubsystem.h"
#include "SocketSubsystem.h"
#include "TimerManager.h"

UTCPClientSubsystem::UTCPClientSubsystem()
{
	ServerSocket = nullptr;
	SocketSubsystem = nullptr;
	bIsConnected = false;
	ServerIP = { 0, };
	ServerPortNumber = 0;
}

void UTCPClientSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// SocketSubsystem Initlize
	SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

	if (!SocketSubsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed To Get SocketSubsystem"));
		return;
	}

	// 타이머 설정 (0.1초마다 메시지 체크)
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(TickTimerHandle, this, &UTCPClientSubsystem::OnTick, 0.1f, true);
	}

}

void UTCPClientSubsystem::Deinitialize()
{
	Super::Deinitialize();


}


bool UTCPClientSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UTCPClientSubsystem::OnTick()
{
	if (bIsConnected && !ServerSocket)
	{

	}
}

bool UTCPClientSubsystem::ConnectToServer(const FString& ServerAddress, uint16 Port)
{

}

void UTCPClientSubsystem::SendMessageToServer(const FString& Message)
{

}

void UTCPClientSubsystem::DisconnectFromServer()
{

}


