// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameItem.h"

AInGameItem::AInGameItem()
	:
	ItemMesh(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh")))
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(ItemMesh);
	ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	ItemMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
}

void AInGameItem::BeginPlay()
{
	Super::BeginPlay();
}

void AInGameItem::SetItemState(EItemState State)
{
	ItemState = State;
	switch (ItemState)
	{
	case EItemState::EIS_Equipped:
		ItemMesh->SetVisibility(true);
		ItemMesh->SetSimulatePhysics(false);
		ItemMesh->SetEnableGravity(false);
		ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
		
	case EItemState::EIS_InInventory:
		ItemMesh->SetVisibility(false);
		ItemMesh->SetSimulatePhysics(false);
		ItemMesh->SetEnableGravity(false);
		ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
		
	case EItemState::EIS_Dropped:
		SetOwner(nullptr);
		ItemMesh->SetVisibility(true);
		ItemMesh->SetSimulatePhysics(true);
		ItemMesh->SetEnableGravity(true);
		ItemMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
		ItemMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		break;
		
	default:
		break;
	}
}