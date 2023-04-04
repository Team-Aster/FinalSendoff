// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */

class UButton;
class UImage;
class AInGameItem;
class UItemTooltipWidget;
class UInventorySlotActionWidget;

UCLASS()
class FINALSENDOFF_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetSlotInformation(const AInGameItem* Item);
	
protected:
	virtual void NativeConstruct() override;
	virtual FReply NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

private:
	void SetToolTipWidget();
	
	UFUNCTION()
	void DoSlotItemAction();
	UFUNCTION()
	void DropItemAction();

public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> ItemButton;
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> ItemImage;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TWeakObjectPtr<AInGameItem> SlotItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UInventorySlotActionWidget> SlotActionWidgetClass;
};
