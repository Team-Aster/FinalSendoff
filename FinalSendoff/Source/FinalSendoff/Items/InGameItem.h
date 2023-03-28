// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InGameItem.generated.h"

class UStaticMeshComponent;
class UTexture2D;

UENUM(BlueprintType)
enum class EItemState : uint8
{
	EIS_Initial		UMETA(DisplayName = "Initial State"),
	EIS_Equipped	UMETA(DisplayName = "Equipped"),
	EIS_Dropped		UMETA(DisplayName = "Dropped"),
	EIS_InInventory	UMETA(DisplayName = "InInventory"),

	EIS_MAX			UMETA(DisplayName = "DefaultMAX")
};

UENUM()
enum class EItemEndingType
{
	EIET_Collect		UMETA(DisplayName = "Collect"),
	EIET_Consume		UMETA(DisplayName = "Consume"),
	EIET_Survive		UMETA(DisplayName = "Survive"),

	EIET_DefaultMAX		UMETA(DisplayName = "DefaultMax")
};

USTRUCT()
struct FItemProperty
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> ItemIconImage;
	UPROPERTY(EditAnywhere)
	FName ItemName;
	UPROPERTY(EditAnywhere)
	EItemEndingType ItemEndingType;
	UPROPERTY(EditAnywhere)
	int32 EndingWeight;
};

UCLASS()
class FINALSENDOFF_API AInGameItem : public AActor
{
	GENERATED_BODY()
	
public:
	
	AInGameItem();

	void SetItemState(EItemState State);

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> ItemMesh;
	UPROPERTY(EditDefaultsOnly)
	FItemProperty ItemProperty;
	UPROPERTY()
	EItemState ItemState;
};
