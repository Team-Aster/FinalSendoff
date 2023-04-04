// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "FinalSendoff/Items/InGameItem.h"

UInventoryComponent::UInventoryComponent()
	:
	InventoryCapacity(16)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::AddItemToInventory(AInGameItem* Item)
{
	if(ItemList.Num() >= InventoryCapacity)
	{
		UE_LOG(LogTemp, Warning, TEXT("인벤토리 가득참"));
		return;
	}
	Item->SetItemState(EItemState::EIS_InInventory);
	ItemList.Add(Item);
	InventoryChangedEvent.Broadcast(ItemList);
}

void UInventoryComponent::DropItemFromInventory(AInGameItem* Item)
{
	Item->SetItemState(EItemState::EIS_Dropped);
	ItemList.Remove(Item);
	InventoryChangedEvent.Broadcast(ItemList);
}