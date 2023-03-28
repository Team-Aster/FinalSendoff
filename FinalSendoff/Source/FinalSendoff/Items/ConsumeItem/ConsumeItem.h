// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalSendoff/Items/InGameItem.h"
#include "FinalSendoff/Items/Interactable.h"
#include "ConsumeItem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FINALSENDOFF_API AConsumeItem : public AInGameItem, public IInteractable
{
	GENERATED_BODY()

public:

	AConsumeItem();

	virtual void InteractWithThis_Implementation() override;
	
protected:
	
	UPROPERTY(EditDefaultsOnly)
	float HealAmount;
};
