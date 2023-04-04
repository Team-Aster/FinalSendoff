// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "FinalSendoff/PlayerInterfaces/Healable.h"

void AFoodItem::InventoryAction_Implementation()
{
	auto HealableCharacter = Cast<IHealable>(GetOwner());
	if(HealableCharacter == nullptr)	return;
	HealableCharacter->HealHungry(HealAmount);
}

void AFoodItem::RemoveFromInventoryAction_Implementation()
{
	
}