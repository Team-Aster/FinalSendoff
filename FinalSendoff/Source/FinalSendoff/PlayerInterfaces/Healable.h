// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Healable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHealable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FINALSENDOFF_API IHealable
{
	GENERATED_BODY()

public:

	virtual void HealThirst(float Amount) = 0;
	virtual void HealHungry(float Amount) = 0;
	virtual void HealMedicine(float Amount) = 0;
};
