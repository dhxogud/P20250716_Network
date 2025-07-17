// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPClientSubsystem.h"
#include "SocketSubsystem.h"
#include "TimerManager.h"

UTCPClientSubsystem::UTCPClientSubsystem()
{
	ClientSocket = nullptr;
	SocketSubsystem = nullptr;
	bIsConnected = false;
	ServerIP = { 0, };
	ServerPort = 0;
}

void UTCPClientSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

	if (!SocketSubsystem)
	{
		LogMessage(TEXT("Failed to get socket subsystem"));
		return;
	}

	LogMessage(TEXT("Echo Client Subsystem initialized"));

	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(TickTimerHandle, this, &UTCPClientSubsystem::OnTick, 0.1f, true);
	}

}

void UTCPClientSubsystem::Deinitialize()
{
	//delete ClientSocket;
	//delete SocketSubsystem;
	
	Super::Deinitialize();


}

bool UTCPClientSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UTCPClientSubsystem::OnTick()
{

}

bool UTCPClientSubsystem::ConnectToServer(const FString& ServerAddress, int32 Port)
{
	if (bIsConnected)
	{
		LogMessage(TEXT("Already connected to server"));
		return false;
	}

	if (!SocketSubsystem)
	{
		LogMessage(TEXT("Socket subsystem not available"));
		return false;
	}

	return false;
}

void UTCPClientSubsystem::SendMessageToServer(const FString& Message)
{

}

void UTCPClientSubsystem::DisconnectFromServer()
{
}

bool UTCPClientSubsystem::IsConnected() const
{
	return false;
}

FString UTCPClientSubsystem::GetServerInfo() const
{
	return FString();
}

void UTCPClientSubsystem::CheckForMessages()
{
}

void UTCPClientSubsystem::ReceiveMessages()
{
}

void UTCPClientSubsystem::ProcessReceivedMessage(const FString& Message)
{
}

void UTCPClientSubsystem::NotifyConnectionStatusChanged(bool bNewConnectionStatus)
{
}

void UTCPClientSubsystem::LogMessage(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
}

void UTCPClientSubsystem::CleanupSocket()
{

}


