// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "InventorySlotWidget.h"
#include "Components/WrapBox.h"

void UInventoryWidget::SetInventoryWidgetList(const TArray<AInGameItem*>& ItemList)
{
	for(int8 i = 0; i < ItemList.Num(); i++)
	{
		InventorySlotWidgets[i]->SetSlotInformation(ItemList[i]);
	}
}

void UInventoryWidget::SetInventoryWidgetSlots(const int8 InventoryCapacity)
{
	InventorySlotWidgets.Reserve(InventoryCapacity);
	for(int8 i = 0; i < InventoryCapacity; i++)
	{
		const auto SlotWidget = CreateWidget<UInventorySlotWidget>(this, InventorySlotClass);
		InventorySlotWidgets.Add(SlotWidget);
		ItemWrapBox->AddChildToWrapBox(SlotWidget);
	}
}