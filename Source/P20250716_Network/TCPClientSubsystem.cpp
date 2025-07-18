// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPClientSubsystem.h"

#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Sockets.h"
#include "SocketSubsystem.h"


UTCPClientSubsystem::UTCPClientSubsystem()
{
    ClientSocket = nullptr;
    SocketSubsystem = nullptr;
    ServerPort = 0;
    bIsConnected = false;
}

void UTCPClientSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

    if (!SocketSubsystem)
    {
        LogMessage("Failed to get socket subsystem");
        return;
    }

    //(UGameplayStatics::GetWorld())->GetTimerManager()->
    
}

void UTCPClientSubsystem::Deinitialize()
{
    Super::Deinitialize();
}

bool UTCPClientSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
    return true;
}

bool UTCPClientSubsystem::ConectToServer(const FString& InServerAddress, int32 InPort)
{
    return false;
}

void UTCPClientSubsystem::OnTick()
{

}

void UTCPClientSubsystem::LogMessage(const FString& Message)
{
    UE_LOG(LogTemp, Warning, TEXT("EchoClientSubsystem: %s"), *Message);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,
            FString::Printf(TEXT("EchoClientSubsystem: %s"), *Message));
    }
}