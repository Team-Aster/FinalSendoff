// Fill out your copyright notice in the Description page of Project Settings.


#include "MedicineItem.h"
#include "FinalSendoff/PlayerInterfaces/Healable.h"

void AMedicineItem::InventoryAction_Implementation()
{
	auto HealableCharacter = Cast<IHealable>(GetOwner());
	if(HealableCharacter == nullptr)	return;
	HealableCharacter->HealMedicine(HealAmount);
}

void AMedicineItem::RemoveFromInventoryAction_Implementation()
{
	
}