// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "InventorySlotActionWidget.h"
#include "Components/Button.h"
#include "FinalSendoff/Items/InGameItem.h"
#include "FinalSendoff/Items/InventoryUsable.h"

void UInventorySlotWidget::SetSlotInformation(const AInGameItem* Item)
{
	// SlotItem = Item;
}

void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetToolTipWidget();
}

FReply UInventorySlotWidget::NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry,const FPointerEvent& InMouseEvent)
{
	if(SlotActionWidgetClass == nullptr || InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
	{
		return Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
	}
	
	const auto ActionWidget = CreateWidget<UInventorySlotActionWidget>(this, SlotActionWidgetClass);
	if(ActionWidget == nullptr)	return  Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);

	ActionWidget->AddToViewport();
	ActionWidget->ActionButton->OnClicked.AddDynamic(this, &UInventorySlotWidget::DoSlotItemAction);
	ActionWidget->DropButton->OnClicked.AddDynamic(this, &UInventorySlotWidget::DropItemAction);
	
	return Super::NativeOnPreviewMouseButtonDown(InGeometry, InMouseEvent);
}

void UInventorySlotWidget::SetToolTipWidget()
{
}

void UInventorySlotWidget::DoSlotItemAction()
{
	if(const auto ItemToInventoryAction = Cast<IInventoryUsable>(SlotItem.Get()))
	{
		ItemToInventoryAction->InventoryAction_Implementation();
	}
}

void UInventorySlotWidget::DropItemAction()
{
	if(const auto ItemToInventoryAction = Cast<IInventoryUsable>(SlotItem.Get()))
	{
		ItemToInventoryAction->RemoveFromInventoryAction_Implementation();
	}
}
