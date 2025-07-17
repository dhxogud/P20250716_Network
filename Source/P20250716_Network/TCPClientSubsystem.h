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

	// ������ ����
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	bool ConnectToServer(const FString& ServerAddress, uint16 Port);

	// ������ �޽��� ����
	void SendMessageToServer(const FString& Message);

	// ���� ���� ����
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	void DisconnectFromServer();

	// ���� ���� ���� Ȯ��
	// ���� �޽��� ����


protected:
	void OnTick();

private:
	// Socket
	FSocket* ServerSocket;
	ISocketSubsystem* SocketSubsystem;
	
	// Server Ip, Server Port
	FString ServerIP;
	uint16 ServerPortNumber;

	// Connection State
	bool bIsConnected;

	FTimerHandle TickTimerHandle;
};
