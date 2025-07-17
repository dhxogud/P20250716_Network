// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePC.h"
#include "Kismet/GameplayStatics.h"

ATitlePC::ATitlePC()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bEnableTouchEvents = true;
	bEnableTouchOverEvents = true;

	FInputModeUIOnly InputModeUIOnly;

	SetInputMode(InputModeUIOnly);
}