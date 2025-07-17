// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleHudWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "TitlePC.h"
#include "SignupWidget.h"

#include "../TCPClientSubsystem.h"


void UTitleHudWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UserIdBox = Cast<UEditableTextBox>(GetWidgetFromName("UserId_Box"));
	PasswordBox = Cast<UEditableTextBox>(GetWidgetFromName("Password_Box"));

	SignupButton = Cast<UButton>(GetWidgetFromName("Signup_Button"));
	if (SignupButton)
	{
		SignupButton->OnClicked.AddDynamic(this, &UTitleHudWidget::OnClickSignupButton);
	}

	LoginButton = Cast<UButton>(GetWidgetFromName("Login_Button"));
	if (LoginButton)
	{
		LoginButton->OnClicked.AddDynamic(this, &UTitleHudWidget::OnClickLoginButton);
	}
}

void UTitleHudWidget::NativeDestruct()
{
	Super::NativeDestruct();

}

// Signup Window Popup
void UTitleHudWidget::OnClickSignupButton()
{

}

void UTitleHudWidget::OnClickLoginButton()
{
	//UTCPClientSubsystem* TCPClient = GetGameInstance()->GetSubsystem<UTCPClientSubsystem>();
	//UserIdBox->GetText();	
	//PasswordBox->GetText();
}

