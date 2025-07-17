// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleHudWidget.generated.h"

class UEditableTextBox;
class UButton;
class USignupWidget;
/**
 * 
 */


UCLASS()
class P20250716_NETWORK_API UTitleHudWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> UserIdBox;

	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> PasswordBox;

	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UButton> SignupButton;

	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UButton> LoginButton;


	UFUNCTION()
	void OnClickSignupButton();

	UFUNCTION()
	void OnClickLoginButton();

};
