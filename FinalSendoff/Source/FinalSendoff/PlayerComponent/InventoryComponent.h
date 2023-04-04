// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AInGameItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryChangedEvent, const TArray<AInGameItem*>&, Inventory);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALSENDOFF_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	FInventoryChangedEvent InventoryChangedEvent;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<AInGameItem*> ItemList;
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	int8 InventoryCapacity;

public:
	UInventoryComponent();

	UFUNCTION()
	void AddItemToInventory(AInGameItem* Item);
	UFUNCTION()
	void DropItemFromInventory(AInGameItem* Item);
	
protected:
	virtual void BeginPlay() override;
};
