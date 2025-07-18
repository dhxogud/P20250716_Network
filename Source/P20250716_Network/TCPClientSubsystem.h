// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Engine/Engine.h"

#include "TCPClientSubsystem.generated.h"

/**
 * 
 */


UCLASS()
class P20250716_NETWORK_API UTCPClientSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UTCPClientSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	bool ConectToServer(const FString& InServerAddress, int32 InPort);


protected:
	void OnTick();

private:
	FSocket* ClientSocket;
	ISocketSubsystem* SocketSubsystem;

	FString ServerAddress;
	int32 ServerPort;

	bool bIsConnected;

	FTimerHandle TickTimerHandle;


	void LogMessage(const FString& Message);
};
