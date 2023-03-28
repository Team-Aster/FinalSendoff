// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterItem.h"
#include "FinalSendoff/PlayerInterfaces/Healable.h"

void AWaterItem::InventoryAction_Implementation()
{
	auto HealableCharacter = Cast<IHealable>(GetOwner());
	if(HealableCharacter == nullptr)	return;
	HealableCharacter->HealThirst(HealAmount);
}
