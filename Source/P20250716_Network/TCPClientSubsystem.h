// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "Engine/Engine.h"

#include "TCPClientSubsystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageReceived, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConnectionStatusChanged, bool, bIsConnected);

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
	bool ConnectToServer(const FString& ServerAddress, int32 Port);

	// ������ �޽��� ����
	void SendMessageToServer(const FString& Message);

	// ���� ���� ����
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	void DisconnectFromServer();

	// ���� ���� ���� Ȯ��
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	bool IsConnected() const;

	// ���� ���� ��������
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	FString GetServerInfo() const;
	
	// �̺�Ʈ ��������Ʈ
	UPROPERTY(BlueprintAssignable, Category = "TCP Client")
	FOnMessageReceived OnMessageReceived;

	UPROPERTY(BlueprintAssignable, Category = "TCP Client")
	FOnConnectionStatusChanged OnConnectionStatusChanged;

	// �������� �޽��� ���� üũ (Tick ��� ��� ����)
	UFUNCTION(BlueprintCallable, Category = "TCP Client")
	void CheckForMessages();

protected:
	// Ÿ�̸� �ڵ鷯
	void OnTick();

private:
	// ���� ����
	FSocket* ClientSocket;
	ISocketSubsystem* SocketSubsystem;

	// ���� ����
	FString ServerIP;
	int32 ServerPort;

	// ���� ����
	bool bIsConnected;

	// Ÿ�̸� �ڵ�
	FTimerHandle TickTimerHandle;

	// �޽��� ���� ó��
	void ReceiveMessages();

	// ���ŵ� �޽����� ó��
	void ProcessReceivedMessage(const FString& Message);

	// ���� ���� ���� �˸�
	void NotifyConnectionStatusChanged(bool bNewConnectionStatus);

	// �α� ���
	void LogMessage(const FString& Message);

	// ���� ����
	void CleanupSocket();
};
