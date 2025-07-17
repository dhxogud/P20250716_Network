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

	// 서버에 연결
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	bool ConnectToServer(const FString& ServerAddress, uint16 Port);

	// 서버에 메시지 전송
	void SendMessageToServer(const FString& Message);

	// 서버 연결 해제
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	void DisconnectFromServer();

	// 서버 연결 상태 확인
	// 서버 메시지 수신


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
