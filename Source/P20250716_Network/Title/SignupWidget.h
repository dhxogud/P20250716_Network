// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignupWidget.generated.h"

class UEditableTextBox;
class UButton;
/**
 * 
 */


UCLASS()
class P20250716_NETWORK_API USignupWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> UserIdTextBox;

	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> PasswordTextBox;

	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UEditableTextBox> NicknameTextBox;
	
	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UButton> SignupButton;

	UPROPERTY(VisibleAnywhere, Category = "Component", BlueprintReadOnly)
	TObjectPtr<UButton> CancelButton;

	UFUNCTION()
	void OnClickSignupButton();

	UFUNCTION()
	void OnClickCancelButton();

	void Signup(FString UserId, FString Password, FString UserNickname);


};
