// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePC.h"
#include "Kismet/GameplayStatics.h"
#include "../TCPClientSubsystem.h"

ATitlePC::ATitlePC()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bEnableTouchEvents = true;
	bEnableTouchOverEvents = true;
}

bool ATitlePC::Login(FText UserId, FText Password)
{
	UTCPClientSubsystem* TCPClientSubsystem = (UGameplayStatics::GetGameInstance(GetWorld()))->GetSubsystem<UTCPClientSubsystem>();
	if (!TCPClientSubsystem)
	{
		return false;
	}

	return false;
}
