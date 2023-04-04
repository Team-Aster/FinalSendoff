// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
class UWrapBox;
class AInGameItem;
class UInventorySlotWidget;

UCLASS()
class FINALSENDOFF_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UWrapBox> ItemWrapBox;
	UPROPERTY(EditAnywhere, Category = "Inventory HUD")
	TSubclassOf<UInventorySlotWidget> InventorySlotClass;

private:
	TArray<UInventorySlotWidget*> InventorySlotWidgets;
	
public:
	void SetInventoryWidgetList(const TArray<AInGameItem*>& ItemList);

private:
	void SetInventoryWidgetSlots(const int8 InventoryCapacity);
};
