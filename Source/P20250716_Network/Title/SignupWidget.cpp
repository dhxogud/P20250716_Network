// Fill out your copyright notice in the Description page of Project Settings.


#include "SignupWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"

void USignupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UserIdTextBox = Cast<UEditableTextBox>(GetWidgetFromName("UserId_Box"));
	PasswordTextBox = Cast<UEditableTextBox>(GetWidgetFromName("Password_Box"));
	NicknameTextBox = Cast<UEditableTextBox>(GetWidgetFromName("NickName_Box"));

	SignupButton = Cast<UButton>(GetWidgetFromName("Signup_Button"));
	if (SignupButton)
	{
		SignupButton->OnClicked.AddDynamic(this, &USignupWidget::OnClickSignupButton);
	}

	CancelButton = Cast<UButton>(GetWidgetFromName("Cancel_Button"));
	if (CancelButton)
	{
		CancelButton->OnClicked.AddDynamic(this, &USignupWidget::OnClickCancelButton);
	}
}

void USignupWidget::NativeDestruct()
{
	Super::NativeDestruct();

}

void USignupWidget::OnClickSignupButton()
{
	FString UserId = (UserIdTextBox->GetText()).ToString();
	FString Password = (PasswordTextBox->GetText()).ToString();
	FString Nickname = (NicknameTextBox->GetText()).ToString();
	
}

void USignupWidget::OnClickCancelButton()
{
	RemoveFromParent();
}


void USignupWidget::Signup(FString UserId, FString Password, FString UserNickname)
{

}
