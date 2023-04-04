// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConsumeItem.h"
#include "FinalSendoff/Items/InventoryUsable.h"
#include "WaterItem.generated.h"

/**
 * 
 */
UCLASS()
class FINALSENDOFF_API AWaterItem : public AConsumeItem, public IInventoryUsable
{
	GENERATED_BODY()

public:
	virtual void InventoryAction_Implementation() override;
	virtual void RemoveFromInventoryAction_Implementation() override;
};
