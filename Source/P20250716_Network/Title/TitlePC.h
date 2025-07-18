// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitlePC.generated.h"

/**
 * 
 */
UCLASS()
class P20250716_NETWORK_API ATitlePC : public APlayerController
{
	GENERATED_BODY()
public:
	ATitlePC();

	UFUNCTION(BlueprintCallable)
	bool Login(FText UserId, FText Password);

};
